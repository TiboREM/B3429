.section .init9

main:
	/* initialisation du boutton poussoir */
	mov.b #0, &34
	
	/* initialisation de la diode rouge */
	mov.b #2, &50
	mov.b #0, &49
	
	/* valeur initiale de la valeur de la diode */
	mov.b #2, r15
	
	mov.b #1, r14
boucle:
	/* switch rdiode */
	xor.b #2, r15
	mov.b r15, &49
	mov #20000, r13
	call #pause
	
	dec r14
	jz waitappui
	
	jmp boucle

waitappui:
	/* test du bouton poussoir (appui) */
	mov.b &32, r13
	and.b #1, r13
	
	/* si r13 nul on va à loop */
	jz waitrelache

	/* cas par défaut on va à wait */
	jmp waitappui
	
waitrelache:
	mov #20000, r13
	call #pause
	inc r14
	
	/* test du bouton poussoir (relachement) */
	mov.b &32, r13
	and.b #1, r13
	dec r13
	
	/* si r13 nul on va à loop */
	jz boucle
	
	/* cas par défaut on va à waitrelache */
	jmp waitrelache

pause:
	
	dec r13
	jnz pause
	
	ret
