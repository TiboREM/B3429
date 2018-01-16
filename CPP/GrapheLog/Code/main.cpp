/*************************************************************************
                                 	Main
                             -------------------
    début                : 9/01/2018
    copyright            : (C) 2018 par B3429 : - Aina RASOLDIER
												- Florian MUTIN
												- Thibault REMY
    e-mail               : aina.rasoldier@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
			   			   thibault.remy@insa-lyon.fr
*************************************************************************/
using namespace std;
#include <iostream>
#include "Graphe.h"

int main (){
	Graphe monGraphe("test.log",true,true,11);
#ifdef TEST_FLO
	monGraphe.AfficheTEST_FLO();
#endif
	monGraphe.Exporter("test.dot");
	return 0;
}
