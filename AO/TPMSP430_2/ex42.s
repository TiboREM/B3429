.section .init9

main:
	/* initialisation du boutton poussoir */
	mov.b #0, &34
	
	/* initialisation de la diode*/
	mov.b #2, &50
	mov.b #0, &49
	
loop:
	call #waitBoutton
	call #switchDiode
	jmp loop	
	

switchDiode:
	xor.b #2, &49
	ret
	
waitBoutton:
	mov.b r13, r14
	mov.b &32, r13
	and.b #1, r13
	xor.b r13, r14
	jz waitBoutton
	ret
	
