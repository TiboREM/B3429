/*************************************************************************
                                 Graphe
                             -------------------
    début                : 9/01/2018
    copyright            : (C) 2018 par B3429 : - Aina RASOLDIER
												- Florian MUTIN
												- Thibault REMY
    e-mail               : aina.rasoldier@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
			   			   thibault.remy@insa-lyon.fr
*************************************************************************/

//-------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) --------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe (const string & nomFichier, const bool optionE, 
							const bool optionG, const unsigned int heure)
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe

Graphe::~Graphe ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe

//----------------------------------------------------- Méthodes publiques
void Graphe::AfficherPlusConsultes()
// Algorithme : aucun
{
} //----- Fin de AfficherPlusConsultes

bool Graphe::Exporter(const string & nomFichier)
// Algorithme : aucun
{
	return true;
} //----- Fin de Exporter

//------------------------------------------------------------------ PRIVE
//-------------------------------------------------------- Méthodes privés
void ajouterLien(const string & pageArrivee, const string & pageDepart)
// Algorithme : aucun
{
} //----- Fin de ajouterLien
