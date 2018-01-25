.section .init9

main:
	/* initialisation de la diode rouge */
	mov.b #2, &50
	
	/* valeur initiale de la valeur de la diode */
	mov #2, r15

loop:
	/* transférer r15 vers la diode */
	mov.b r15, &49
	
	/* switch r15 */
	xor #2, r15
	
	/* valeur initiale de la valeur du compteur de wait */
	mov #20000, r13
	
wait:
	/* incrémentation r13 */
	dec r13
		
	/* si r13 nul on va à loop */
	jz loop
	
	/* cas par défaut on va à wait */
	jmp wait
