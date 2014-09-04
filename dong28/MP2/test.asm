;									tab:8
;
; test.asm - sample input for ECE198KL Spring 2013 Program 2
;
; "Copyright (c) 2004-2013 by Illinois ECE.
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
; Author:	    Eugene ... (a TA...I forget his last name)
; Version:	    1.01
; Creation Date:    27 February 2004
; Filename:	    test.asm (originally mp2data.asm)
; History:
;	E??	1.00	27 February 2004
;		Written for ECE199SJP in Fall 2004.
;	SL	1.01	21 January 2013
;		Added header for ECE198KL in Spring 2013.
;

.ORIG x5000

.STRINGZ "Story Text 0. Do you choose (1), (2) or (3)?\n"
.FILL x0005
.FILL x0007
.FILL x0003
.STRINGZ "Ending Text 1.\n"
.FILL xFFFF
.FILL xFFFF
.FILL xFFFF
.STRINGZ "Ending Text 2.\n"
.FILL xFFFF
.FILL xFFFF
.FILL xFFFF
.STRINGZ "Story Text 3. Do you choose (1) or (2)?\n"
.FILL x0001
.FILL x0004
.FILL xFFFF
.STRINGZ "Story Text 4. Do you choose (1) or (2)?\n"
.FILL x0006
.FILL x0002
.FILL xFFFF
.STRINGZ "Ending Text 5.\n"
.FILL xFFFF
.FILL xFFFF
.FILL xFFFF
.STRINGZ "Ending Text 6.\n"
.FILL xFFFF
.FILL xFFFF
.FILL xFFFF
.STRINGZ "Story Text 7. Press (1) to continue story.\n"
.FILL x0004
.FILL xFFFF
.FILL xFFFF
.FILL x0000

.END


