;Write a MEM_MOVE subroutine in memmove.asm that meets the following specifications:

;You are given a sequence of memory locations starting at x5001 
;and the length of the sequence is given at x5000. 
;Your subroutine should copy the sequence to a new space 
;in memory indicated by the address at the label MOVE_ADDR. 
;The destination memory location could be any memory location after x5000.  
;When we test your code, we will try different locations in MOVE_ADDR
;and different lengths of the original sequence.  
;Hint: your code doesn’t need to preserve the original sequence.  
;It might be overwritten depending on the length and the location of MOVE_ADDR.
;To test your code first load either movemem_test1 or movemem_test2 and then load the program


	.ORIG	x3000
	;;R1 holds the lengthe of sequence
	;;R2 is the current location pointer
	;; R3 is the temp register used for copying content
	;; r4 is the move location pointer
	;; r5 holds the contents
	
;Your code goes here
	LD R1, LEN_ADDR		;load the length of sequence in R1
	LD R2, DEST_ADDR	;load [x5001] to R2(current location pointer)
	LDR R5, R2, #0          ; load content of x5001 to R5
	LD R4, MOVE_ADDR        ; load x5009 to R4 (destination pointer)
	
COPY    AND R3, R3, #0		; clear r3
	ADD R2, R3, #0          ; copy content in r2 to R3
	STR R3, R4, #0          ; store content in r3 to destination address
	ADD R1, R1, #-1		; decrement length
	BRp COPY		; if still positive, continue copy


; Your code ends here
	
;Printing out your original string and the moved string to help you debug

	LD R0, DEST_ADDR
	PUTS
	LD R0, MOVE_ADDR	
	PUTS
        HALT

LEN_ADDR	.FILL x5000
DEST_ADDR	.FILL x5001
MOVE_ADDR	.FILL x5009






.END
