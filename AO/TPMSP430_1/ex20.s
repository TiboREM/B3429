.section .init9

main:
	/* initialisation de la diode rouge */
	mov.b #2, &50
	
	/* valeur initiale de la valeur de la diode */
	mov #2, r15
	
	/* valeur initiale de la valeur du compteur */
	mov #0, r14

loop:
	/* transférer r15 vers la diode */
	mov.b r15, &49
	
	/* incrémentation r14 */
	add.b #1, r14
	
	/* switch r15 */
	xor #2, r15
	
	jmp loop
