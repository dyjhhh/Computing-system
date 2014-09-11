;									tab:8
;
; prog3.asm - starting code for ECE198KL Spring 2013 Program 3
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
; Creation Date:    26 January 2013
; Filename:	    prog3.asm
; History:
;	SL	1.00	26 January 2013
;		First written.
;

	.ORIG	x3000		; starting address is x3000



; PUT YOUR CODE FROM PROGRAM 2 HERE (without copying .ORIG / .END)



; You may need to move these strings to be close to your game play loop.

P3_START_STR	.STRINGZ "\n\n--- Starting adventure. ---\n\n"
P3_PROMPT_STR	.STRINGZ "Please enter your choice: "
P3_INVALID_STR	.STRINGZ "\n\n--- Invalid choice. ---\n\n"
P3_END_STR	.STRINGZ "\n\n--- Ending adventure. ---\n\n"


	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END

