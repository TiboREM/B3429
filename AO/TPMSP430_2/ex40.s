.section .init9

main:
	/* initialisation du boutton poussoir */
	mov.b #0, &34
	
	/* initialisation de la diode rouge */
	mov.b #2, &50
	mov.b #0, &49
	
	/* valeur initiale de la valeur de la diode */
	mov.b #2, r15
	
boucle:
	/* compteur */
	mov.b #10, r14
	
	call #blinkn

	jmp end
pause:
	
	dec r13
	jnz pause
	
	ret

blinkn:
	mov #20000, r13
	call #pause
	
	/* switch rdiode */
	xor.b #2, r15
	mov.b r15, &49
	
	dec r14
	jnz blinkn
	
	ret

end:
	jmp end
