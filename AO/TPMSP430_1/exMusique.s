/*programme pour jouer une musique*/
/*r14 contient la fréquence de la note à jouer*/
/*startJouer permet de jouer la note*/
/*r11 le numero de la note dans la partition*/

.section .init9

main:
	/* initialisation du buzzer */
	mov.b #32, &26
	mov #32, r15
	clr r11
	
/************************************************************************/
	
partition:
	note0:
		cmp #0, r11
		jnz note1
			mov #102, r14
			jmp startJouer

	note1:
		cmp #1, r11
		jnz note2
			mov #76, r14
			jmp startJouer
	note2:
		cmp #2, r11
		jnz note3
			mov #76, r14
			jmp startJouer
	note3:
		cmp #3, r11
		jnz note4
			mov #76, r14
			jmp startJouer
	note4:
		cmp #4, r11
		jnz note5
			mov #68, r14
			jmp startJouer
	
	note5:
		cmp #5, r11
		jnz note6
			mov #76, r14
			jmp startJouer

	note6:
		cmp #6, r11
		jnz note7
			mov #76, r14
			jmp startJouer
			

	note7:
		cmp #7, r11
		jnz note8
			mov #76, r14
			jmp startJouer


	note8:
		cmp #8, r11
		jnz note9
			mov #25000, r12
			mov #76, r14
			jmp jouer
	
	note9:
		cmp #9, r11
		jnz end
			mov #68, r14
			jmp startJouer
	
/************************************************************************/

/*waitOneSec = attente avant de changer la fréquence */
startJouer:
mov #50000, r12
jouer:
	/* initialisation de la fréquence */
	xor #32, r15
	mov.b r15, &25

			/*waitFrequence = attente pour faire */
			/*un son d'une fréquence donnée */
				mov r14, r13
			waitFrequence:
			
				dec r12
				jz finJouer /*sortie jouer*/
				
				dec r13
				jz sortieWaitFrequence /*sortie waitFrequence*/
				jmp waitFrequence
			/*fin waitFrequence*/
	sortieWaitFrequence:
		jmp jouer
/*fin jouer*/
		
finJouer:
	inc r11
	clr.b &25
	jmp partition
	
end:
	jmp end
