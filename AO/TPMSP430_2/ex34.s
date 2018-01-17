.section .init9

main:
	/* initialisation du boutton poussoir */
	mov.b #0, &34
	
	/* initialisation de la diode rouge */
	mov.b #2, &50
	mov.b #0, &49
	
	/* valeur initiale de la valeur de la diode */
	mov.b #2, r15
	
changement:
	/* switch r15 */
	xor.b #2, r15
	
	/* transférer r15 vers la diode */
	mov.b r15, &49
	
waitappui:
	/* test du bouton poussoir (appui) */
	mov.b &32, r13
	and.b #1, r13
	
	/* si r13 nul on va à loop */
	jz waitrelache

	/* cas par défaut on va à wait */
	jmp waitappui
	
waitrelache:
	/* test du bouton poussoir (relachement) */
	mov.b &32, r13
	and.b #1, r13
	dec r13
	
	/* si r13 nul on va à loop */
	jz changement
	
	/* cas par défaut on va à waitrelache */
	jmp waitrelache
