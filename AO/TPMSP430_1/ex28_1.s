.section .init9

main:
	/* initialisation du buzzer */
	mov.b #32, &26
	mov #32, r15

loop:
	/* transférer r15 vers le buzzer */
	mov.b r15, &25
	
	/* switch r15 */
	xor #32, r15


/************************************************************************/

	/* valeur initiale de la valeur du compteur de wait */
	mov #100, r13
	
wait:
	/* incrémentation r13 */
	dec r13
		
	/* si r13 nul on va à loop */
	jz loop
	
	/* cas par défaut on va à wait */
	jmp wait
