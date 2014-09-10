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



	;; ---------START OF DATABSE PARSING CODE----------
	;; Register table:
	;; R2 : pointer to current location in array
	;; R3 : pointer to current location in database
	;; R4 : amount of pages, counter
	;; R5 : read data reg
	;; R6 : choice counter (3)

	;;  initialize registers
	AND R2,R2,#0	    	; clear R2 to 0
	LD R2,ARRAY_START   	; load R2 with x4000
				;; (array starting addr)
	AND R3,R3,#0		; clear R3 to 0
	LD R3,DATABASE_START 	; load R3 with x5000
				;;  (db starting addr)
	AND R4,R4,#0		; clear R4 to 0
	AND R5,R5,#0		; clear R5 to 0
	AND R6,R6,#0		; clear R6 to 0

	;;  read database
	
STORE_ADDRESS	        
	STR R3,R2,#0		; put addr loc x5000 into mem[x4000]
	        
CHK_STRING_END

	ADD R3,R3,#1		; increment the database pointer
	LDR R5,R3,#0		; load mem[R3] to R5
	BRnp CHK_STRING_END	; check whether this is a NUL char
        ADD R6,R6,#3		; initialize choice counter to 3
           
            	        
READ_CHOICE
	ADD R3,R3,#1		; invrement database pointer
	ADD R2,R2,#1		; increment array pointer
	LDR R5,R3,#0		; load mem[R3] into R5
	STR R5,R2,#0		; store R5 into mem[R2]	
	ADD R6,R6,#-1		; decrement choice counter (R6)
	BRp READ_CHOICE		; loop again if the 3rd choice wasn't stored
	ADD R2,R2,#1		; increment array pointer
	ADD R3,R3,#		; increment database pointer
	LDR R5,R3,#0		; load mem[R3] into R5
	BRz PRINTOUT		; if it is zero, start printing out characters
	BRnzp STORE_ADDRESS	; unconditional branch to store address
	        	        
;;  at this point, we know the next three lines will contain the three choices
;;  so all we have to do is go about this loop three times..
	       

	ARRAY_START		 .FILL x4000
	DATABASE_START   	 .FILL x5000
	;;  ---- End of Database Parsing Code ----

PRINTOUT
	AND R0,R0,#0		; clear R0
	LD R3,ARRAY_START	; load R3 to the starting address of array
	ADD R3,R3,#1		; increment database pointer
	ADD R2,R3,#0		; copy content in R3 to R2
	
PRINTNEWLINE
	JSR PRINT_FOUR_HEX	
	LD R2, NEWLINE
	JSR PRINT_CHAR
    ADD R0,R0,#1	
    ADD R3,R3,#4
    ADD R2,R3,#0
    LDR R5,R3,#0
    BRnp PRINTNEWLINE
    
	HALT

NEWLINE .FILL x000A

	
; For Program 2, you must wrap the following code up as a subroutine.
;
; This code relies on another subroutine called PRINT_CHAR
;   that prints a single ASCII character in the low 8 bits of R2
;   to the monitor.  The PRINT_CHAR call must not change any registers
;   (other than R7)!
;


; if the number can be printed as hex then go to subroutine PRINT_HEX_DIGIT
; if the number can only be printed as ascii character
; go to subroutine
        
        
        
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

    ST R2,PRINT_HEX_DIGIT_R2	; Save registers
	ST R3,PRINT_HEX_DIGIT_R3	;
	ST R4,PRINT_HEX_DIGIT_R4	;
	ST R5,PRINT_HEX_DIGIT_R5	;
	ST R6,PRINT_HEX_DIGIT_R6	;
	ST R7,PRINT_HEX_DIGIT_R7	;

	; print low 8 digits of R3 as hexdecimal
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

    LD R2,PRINT_HEX_DIGIT_R2 ;restore register
	LD R3,PRINT_HEX_DIGIT_R3 ;
	LD R4,PRINT_HEX_DIGIT_R4 ;
	LD R5,PRINT_HEX_DIGIT_R5 ;
	LD R6,PRINT_HEX_DIGIT_R6 ;
	LD R7,PRINT_HEX_DIGIT_R7 ;
	
	RET

	; data for PRINT_HEX subroutine
PRINT_HEX_DIGIT_R2	.BLKW #1 ;avoid changing register
PRINT_HEX_DIGIT_R3	.BLKW #1		
PRINT_HEX_DIGIT_R4	.BLKW #1
PRINT_HEX_DIGIT_R5	.BLKW #1
PRINT_HEX_DIGIT_R6	.BLKW #1
PRINT_HEX_DIGIT_R7	.BLKW #1
ASC_ZERO	.FILL x0030	; ASCII '0'
ASC_HIGH	.FILL x0037	; ASCII 'A' - 10


;
; Subroutine PRINT_CHAR
;   input: R2 -- 8-bit ASCII character to print to monitor
;   caller-saved registers: R7 (as always with LC-3)
;   callee-saved registers: all other registers
	;; input: R2 - 8 bit ASCII character print to monitor

	;; --------PRINT_CHAR SUBROUTINE-----------
	;; callee-save R0 and R7 into memory, check if display is ready for
	;; next character to be printed. If it is, load contents of DDR to R2
	;; DSR[15]=0, not ready
	;; DSR[15]=1, ready

PRINT_CHAR
	ST	R0,PRINT_CHAR_R0	; callee-save pre contents of R0 to memery, R0 is used for checking the DSR
	ST	R7,PRINT_CHAR_R7	; callee-save pre contents of R7 to memory, R7 will be overwritten by JSR

POLL_DSR
	LDI R0,DSR		; R0<-mem[mem[DSR]]
				;; R0<-mem[xFE04]
				;; load contents of DSR to R0
 	BRzp POLL_DSR		; loop if R0(DSR) is not ready

	STI R2,DDR		; mem[mem[DDR]]<-data
				;; mem[xFE04]
				;; store contents of DDR to R2
	
	LD	R0,PRINT_CHAR_R0	; restore R0 from memory
	LD	R7,PRINT_CHAR_R7	; restore R7 from memory, because the code after the subroutine might require R7 to work properly
	RET

	; data for PRINT_CHAR subroutine
DSR	.FILL xFE04
DDR	.FILL xFE06
PRINT_CHAR_R0	.BLKW #1
PRINT_CHAR_R7	.BLKW #1

	;; -----------PRINT_FOUR_HEX subroutine----------------


PRINT_FOUR_HEX
	;; R2 holds an ASCII SPACE (for printing with PRINT_CHAR)
	;; R3 holds the hex value to print (with PRINT_HEX_DIGIT)
	;; R4 holds the pointer to the value array (moved from input R2)
	;; R5 is a loop counter

	ST R2,PRINT_FOUR_HEX_R2	; save registers
    ST R3,PRINT_FOUR_HEX_R3
	ST R4,PRINT_FOUR_HEX_R4
	ST R5,PRINT_FOUR_HEX_R5
	ST R7,PRINT_FOUR_HEX_R7

	ADD R3,R0,#0		; copy R0 to R3, print the first digit
	JSR PRINT_HEX_DIGIT	; jump tp PRINT_HEX_DIGIT subroutine
	
	AND R5,R5,#0		; clear R5 to 0, prepare to loop
	ADD R4,R2,#0		; copy R2 to R4, R2 is free to hold SPACE
	LD  R2,SPACE		; load hex value of space (x20) into R2
PFHLOOP
	JSR PRINT_CHAR		; jump to PRINT_CHAR subroutine
	LDR R3,R4,#0		;
	JSR PRINT_HEX_DIGIT	; jump to PRINT_HEX_DIGIT subroutine

	ADD R4,R4,#1		; increment R4 by 1
	ADD R5,R5,#1		; increment R5 by 1
	ADD R3,R5,#-3		; decrement R5 by 3
	BRn PFHLOOP

	LD R2,PRINT_FOUR_HEX_R2
	LD R3,PRINT_FOUR_HEX_R3
	LD R4,PRINT_FOUR_HEX_R4
	LD R5,PRINT_FOUR_HEX_R5
	LD R7,PRINT_FOUR_HEX_R7
	RET
	
PRINT_FOUR_HEX_R2	.BLKW #1
PRINT_FOUR_HEX_R3	.BLKW #1
PRINT_FOUR_HEX_R4	.BLKW #1
PRINT_FOUR_HEX_R5	.BLKW #1
PRINT_FOUR_HEX_R7	.BLKW #1
	
SPACE	.FILL x20

	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END

