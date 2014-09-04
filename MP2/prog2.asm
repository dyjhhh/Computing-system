;									tab:8
;
; prog2.asm - starting code for ECE198KL Spring 2013 Program 2
;
; "Copyright (c) 2013 by Steven S. Lumetta.
;
; Permission to use, copy, modify, and distribute this software and its
; documentation for any purpose, without fee, and without written agreement is
; hereby granted, provided that the above copyright notice and the following
; two paragraphs appear in all copies of this software.
; 
; IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO 
; ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL 
; DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
; EVEN IF THE AUTHOR AND/OR THE UNIVERSITY OF ILLINOIS HAS BEEN ADVISED 
; OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; THE AUTHOR AND THE UNIVERSITY OF ILLINOIS SPECIFICALLY DISCLAIM ANY 
; WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
; MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE 
; PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND NEITHER THE AUTHOR NOR
; THE UNIVERSITY OF ILLINOIS HAS ANY OBLIGATION TO PROVIDE MAINTENANCE, 
; SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
;
; Author:	    Steve Lumetta
; Version:	    1.00
; Creation Date:    21 January 2013
; Filename:	    prog2.asm
; History:
;	SL	1.00	21 January 2013
;		Culled from Program 1 gold code, then adapted slightly.
;

	.ORIG	x3000		; starting address is x3000


	LD R3,SAMPLE
	JSR PRINT_HEX_DIGIT	; will not work as is!
	HALT

SAMPLE	.FILL xAB		; data for main progam

;
; For Program 2, you must wrap the following code up as a subroutine.
;
; This code relies on another subroutine called PRINT_CHAR
;   that prints a single ASCII character in the low 8 bits of R2
;   to the monitor.  The PRINT_CHAR call must not change any registers
;   (other than R7)!
;

;
; Subroutine PRINT_HEX_DIGIT
;   input: R3 -- 8-bit value to be printed as hex (high bits ignored)
;   caller-saved registers: R7 (as always with LC-3)
;   callee-saved registers: all other registers
;

PRINT_HEX_DIGIT

; registers used in this subroutine
;   R2 -- ASCII character to be printed
;   R3 -- 8-bit value to be printed as hex (high bits ignored)
;   R4 -- bit counter
;   R5 -- digit counter
;   R6 -- temporary

	; print low 8 bits of R3 as hexadecimal

	; shift R3 up 8 bits
	AND R2,R2,#0		; initialize shift count to 8
	ADD R2,R2,#8
SHIFT_LOOP
	ADD R3,R3,R3		; shift one bit
	ADD R2,R2,#-1		; count down
	BRp SHIFT_LOOP		; keep going until we're done

	AND R5,R5,#0		; initialize digit count to 0
DIG_LOOP
	AND R4,R4,#0		; initialize bit count to 0
	AND R2,R2,#0		; initialize current digit to 0
BIT_LOOP
	ADD R2,R2,R2		; double the current digit (shift left)
	ADD R3,R3,#0		; is the MSB set?
	BRzp MSB_CLEAR
	ADD R2,R2,#1		; if so, add 1 to digit
MSB_CLEAR
	ADD R3,R3,R3		; now get rid of that bit (shift left)
	ADD R4,R4,#1		; increment the bit count
	ADD R6,R4,#-4		; have four bits yet?
	BRn BIT_LOOP		; if not, go get another

	ADD R6,R2,#-10		; is the digit >= 10?
	BRzp HIGH_DIGIT		; if so, we need to print a letter
	LD R6,ASC_ZERO		; add '0' to digits < 10
	BRnzp PRINT_DIGIT
HIGH_DIGIT
	LD R6,ASC_HIGH		; add 'A' - 10 to digits >= 10
PRINT_DIGIT
	ADD R2,R2,R6		; calculate the digit

	JSR PRINT_CHAR		; print the digit

	ADD R5,R5,#1		; increment the digit count
	ADD R6,R5,#-2		; printed both digits yet?
	BRn DIG_LOOP		; if not, go print another


	; THIS CODE WILL NOT WORK AS IS!

	RET

	; data for PRINT_HEX subroutine

ASC_ZERO	.FILL x0030	; ASCII '0'
ASC_HIGH	.FILL x0037	; ASCII 'A' - 10


;
; Subroutine PRINT_CHAR
;   input: R2 -- 8-bit ASCII character to print to monitor
;   caller-saved registers: R7 (as always with LC-3)
;   callee-saved registers: all other registers
;

PRINT_CHAR
	ST	R0,PRINT_CHAR_R0	; save R0 to memory
	ST	R7,PRINT_CHAR_R7	; save R7 to memory...why?
	ADD	R0,R2,#0		; copy from R2
	OUT		; cheat! (you must fix...)
	LD	R0,PRINT_CHAR_R0	; restore R0 from memory
	LD	R7,PRINT_CHAR_R7	; restore R7 from memory...why?
	RET

	; data for PRINT_CHAR subroutine

PRINT_CHAR_R0	.BLKW #1
PRINT_CHAR_R7	.BLKW #1


	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END

