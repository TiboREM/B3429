.section .init9

main:
	/* initialisation du buzzer */
	mov.b #32, &26
	mov #32, r15

	/* initialisation du compteur */
	mov #100, r14
	
	
loop:
	/* incrémentation du compteur */
	inc r14
	
		/*waitIncrementCompteur = attente avant de changer la fréquence */
			mov #300, r12
		waitIncrementCompteur:
			/*changement on/off du buzzer*/
			xor #32, r15
			mov.b r15, &25

					/*waitFrequence = attente pour faire */
					/*un son d'une fréquence donnée */
						mov r14, r13
					waitFrequence:
						dec r13
						jz sortieWaitFrequence /*sortie waitFrequence*/
						jmp waitFrequence
					/*fin waitFrequence*/
			sortieWaitFrequence:
			dec r12
			jz loop /*sortie waitIncrementCompteur*/
			jmp waitIncrementCompteur
		/*fin waitIncrementCompteur*/
