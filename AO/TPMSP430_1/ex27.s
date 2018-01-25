.section .init9

main:
	/* diode rouge */
	/* initialisation */
	mov.b #2, &50
	
	/* eteindre */
	mov.b #0, &49
	
	/* allumer */
	mov.b #2, &49
	
	/* les autres diodes P2.1 et P2.2 */
	/* initialisation (6 = 00000110) */
	mov.b #6, &42

	/* eteindre */
	mov.b #0, &41
	
	/* allumer */
	mov.b #6, &41
loop:
	jmp loop
