	.arch msp430g2553
	.p2align 1,0	
	
	.data
state:
	.word 1
	
	.text
jt:
	.word state1
	.word state2
	.word state3
	.word state4
	
	.global	toggle
toggle:

	MOV &state, r12
	ADD r12, r12
	MOV jt(r12), r0

;; both leds are off to represent the number 0 in binary
state1:
	MOV.B	#0, &red_on	; red_on   = 0;
	MOV.B	#0, &green_on   ; green_on = 0;
	MOV.B	#1, &state	; state    = 1;
	JMP	end

;; turns on the red led to represent the number 1 in binary
state2:
	MOV.B	#1, &red_on	; red_on   = 1;
	MOV.B	#0, &green_on	; green_on = 0;
	MOV.B	#2, &state	; state    = 2;
	JMP	end

;; turns on the green led to represent the number 2 in binary 
state3:
	MOV.B	#0, &red_on	; red_on   = 0;
	MOV.B	#1, &green_on 	; green_on = 1;
	MOV.B	#3, &state	;state     = 3
	JMP	end

;; turns on both leds to represent the number 3 in binary
state4:
	MOV.B	#1, &red_on	;red_on   = 1;
	MOV.B	#1, &green_on	;green_on = 1;
	MOV.B	#0, &state	;state    = 0;
	JMP	end
end:	
	
	POP r0 ; return to program counter
	
