;									tab:8
;
; prog1.asm - starting code for ECE198KL Spring 2013 Program 1
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
; Creation Date:    11 January 2013
; Filename:	    prog1.asm
; History:
;	SL	1.00	11 January 2013
;		Adapted from ECE190 example code.
;


;
; The code given to you here implements the histogram calculation that 
; we developed in class.  In programming studio, we will add code that
; prints a number in hexadecimal to the monitor.
;
; Your assignment for this program is to combine these two pieces of 
; code to print the histogram to the monitor.
;
; If you finish your program, 
;    ** commit a working version to your repository  **
;    ** (and make a note of the repository version)! **
; you may want to try (in increasing order of difficulty)
;   - printing leading zeroes as spaces instead
;   - allowing the user to type the string to be processed using
;     the keyboard (either with GETC or directly using the KBSR
;     and the KBDR)
;   - wrapping the pieces up as subroutines (you may need to read
;     farther ahead to do this well)
;   - printing histogram results in decimal rather than in hexadecimal
;


	.ORIG	x3000		; starting address is x3000


;
; Count the occurrences of each letter (A to Z) in an ASCII string 
; terminated by a NUL character.  Lower case and upper case should 
; be counted together, and a count also kept of all non-alphabetic 
; characters (not counting the terminal NUL).
;
; The string starts at x4000.
;
; The resulting histogram (which will NOT be initialized in advance) 
; should be stored starting at x3F00, with the non-alphabetic count 
; at x3F00, and the count for each letter in x3F01 (A) through x3F1A (Z).
;
; table of register use in this part of the code
;    R0 holds a pointer to the histogram (x3F00)
;    R1 holds a pointer to the current position in the string
;       and as the loop count during histogram initialization
;    R2 holds the current character being counted
;       and is also used to point to the histogram entry
;    R3 holds the additive inverse of ASCII '@' (xFFC0)
;    R4 holds the difference between ASCII '@' and 'Z' (xFFE6)
;    R5 holds the difference between ASCII '@' and '`' (xFFE0)
;    R6 is used as a temporary register
;

	LD R0,HIST_ADDR      	; point R0 to the start of the histogram
	
	; fill the histogram with zeroes 
	AND R6,R6,#0		; put a zero into R6
	LD  R1,NUM_BINS		; initialize loop count to 27
	ADD R2,R0,#0		; copy start of histogram into R2

	; loop to fill histogram starts here
HFLOOP	STR R6,R2,#0		; write a zero into histogram
	ADD R2,R2,#1		; point to next histogram entry
	ADD R1,R1,#-1		; decrement loop count
	BRp HFLOOP		    ; continue until loop count reaches zero

	; initialize R1, R3, R4, and R5 from memory
	LD R3,NEG_AT		; set R3 to additive inverse of ASCII '@'
	LD R4,AT_MIN_Z		; set R4 to difference between ASCII '@' and 'Z'
	LD R5,AT_MIN_BQ		; set R5 to difference between ASCII '@' and '`'
	LD R1,STR_START		; point R1 to start of string

	; the counting loop starts here
COUNTLOOP
	LDR R2,R1,#0		; read the next character from the string
	BRz PRINT_HIST		; found the end of the string

	ADD R2,R2,R3		; subtract '@' from the character
	BRp AT_LEAST_A		; branch if > '@', i.e., >= 'A'
NON_ALPHA
	LDR R6,R0,#0		; load the non-alpha count
	ADD R6,R6,#1		; add one to it
	STR R6,R0,#0		; store the new non-alpha count
	BRnzp GET_NEXT		; branch to end of conditional structure
AT_LEAST_A
	ADD R6,R2,R4		; compare with 'Z'
	BRp MORE_THAN_Z         ; branch if > 'Z'

; note that we no longer need the current character
; so we can reuse R2 for the pointer to the correct
; histogram entry for incrementing
ALPHA	ADD R2,R2,R0		; point to correct histogram entry
	LDR R6,R2,#0		; load the count
	ADD R6,R6,#1		; add one to it
	STR R6,R2,#0		; store the new count
	BRnzp GET_NEXT		; branch to end of conditional structure

; subtracting as below yields the original character minus '`'
MORE_THAN_Z
	ADD R2,R2,R5		; subtract '`' - '@' from the character
	BRnz NON_ALPHA		; if <= '`', i.e., < 'a', go increment non-alpha
	ADD R6,R2,R4		; compare with 'z'
	BRnz ALPHA		    ; if <= 'z', go increment alpha count
	BRnzp NON_ALPHA		; otherwise, go increment non-alpha

GET_NEXT
	ADD R1,R1,#1		; point to next character in string
	BRnzp COUNTLOOP		; go to start of counting loop

PRINT_HIST
    LD R0,POS_AT        ; load POS_AT into r0.
    OUT                 ; print ASCII character '@' onto screen
    LD R0, ASC_SPACE    ; load ASC_SPACE into R0
    OUT                 ; print a space onto screen
    LD R1,POS_AT        ; load POS_AT into R1
    LD R2,HIST_ADDR     ; load histogram starting address into R2

PRINT_HEX
	LDR R3,R2,#0
    AND R5,R5,#0        ; initialize digit count to 0
    
DIG_LOOP
    AND R4,R4,#0        ; initialize bit count to 0
    AND R0,R0,#0        ; initialize current digit to 0
    
BIT_LOOP
    ADD R0,R0,R0        ; double the current digit (shift left)
    ADD R3,R3,#0        ; check if it is the MSB set
    BRzp MSB_CLEAR
    ADD R0,R0,#1        ; if so, add 1 to digit
    
MSB_CLEAR
    ADD R3,R3,R3        ; get rid of that bit (shift left)
    ADD R4,R4,#1        ; increment the bit count
    ADD R6,R4,#-4       ; check if we have four bits yet 
    BRn BIT_LOOP        ; if not, go get another
    ADD R6,R0,#-10      ; is the digit >= 10?
    BRzp HIGH_DIGIT     ; if so, we need to print a letter
    LD R6,ASC_ZERO      ; add ’0’ to digits < 10
    BRnzp PRINT_DIGIT
    
HIGH_DIGIT
    LD R6,ASC_HIGH      ; add ’A’ - 10 to digits >= 10
PRINT_DIGIT
    ADD R0,R0,R6        ; calculate the digit
    OUT
    ADD R5,R5,#1        ; increment the digit count
    ADD R6,R5,#-4       ; check if printed both digits yet?
    BRn DIG_LOOP        ; if not, go print another

    LEA R0, NEWLN       ; Load address of newln into r0.
    LDR R0,R0,#0        ; Load contents into r0.
    OUT                 ; Print R0 (i.e. a newline).

    ADD R1,R1, #1       ; go to next char in ASCII table.
    ADD R0,R1, #0       ; store content of R1 into R0
    LD  R6,NEG_Z        ; load the additive inverse of ASCII 'Z'
    ADD R6,R6,R1        ; compare the value with 'Z'
    BRzp DONE           ; if the character is 'Z', go to done
    ADD R0,R1,#0        ; store content of R1 into R0
    OUT                 ; print out the ascii character
    LD  R0,ASC_SPACE    ; load R0 with ASC_SPACE
    OUT                 ; print out a space
    ADD R2,R2,#1        ; go to the next histogram entry
    LD R6, NEG_Z        ; load the additive inverse of ASCII 'Z'
    ADD R6,R6,R1        ; compare with 'Z'
    BRn PRINT_HEX       ; Loop if the character is not 'Z' yet 



DONE	HALT			; done


; the data needed by the program
NUM_BINS	.FILL #27	; 27 loop iterations
NEG_AT		.FILL xFFC0	; the additive inverse of ASCII '@'
AT_MIN_Z	.FILL xFFE6	; the difference between ASCII '@' and 'Z'
AT_MIN_BQ	.FILL xFFE0	; the difference between ASCII '@' and '`'
HIST_ADDR	.FILL x3F00 ; histogram starting address
STR_START	.FILL x4000	; string starting address
ASC_HIGH    .FILL X0037
ASC_ZERO    .FILL X0030
POS_AT      .FILL x0040
NEWLN       .stringz "\n" 
ASC_SPACE   .FILL x0020
NEG_Z       .FILL xFFA5

; for testing, you can use the lines below to include the string in this
; program...
; STR_START	.FILL STRING	; string starting address
; STRING		.STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."



	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END
