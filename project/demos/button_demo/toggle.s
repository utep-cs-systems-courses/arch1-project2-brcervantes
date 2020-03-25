	.file	"state_machine.c"
.text
	.balign 2
	.global	toggle
	
toggle:
	MOV.B	&state, R12 	; Move current state to register 12
	CMP	#1, R12		; Compare immediate value 1 with register 12
	JEQ	state2		; If state = 1 jump to state1

	MOV.B	#1, R13		; Move immediate value 1 to register 13
	CMP	R12, R13	; Compare register 12 with register 13
	JL	switch		; If less than that means register 12 is greater than 1 jump to switch.

	CMP	#0, R12		; Compare immediate value 0 with current state in register 12
	JEQ	state1		; Jump to state1 if equal to 0
	JMP	end		; If it is not equal to zero than jump to end

switch:
	CMP	#2, R12		; Current state is greater than 1 so we compare to immediate value 2
	JEQ	state3 		; Jump to state3 if equal to 2

	CMP	#3, R12		; Compare immediate value 3 to current state in register 12
	JEQ	state4		; Jump to state4 if equal to 3
	JMP	end		

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
	
	POP r0			; return to program counter
	.size	toggle, .-toggle
	.local  state		; local static variable state
	.comm	state,1,1
	
