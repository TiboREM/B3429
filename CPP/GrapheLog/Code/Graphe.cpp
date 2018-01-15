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
#include <fstream>

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
	
	//Vérifications
	unsigned int indexPoint = nomFichier.find_last_of('.');
	if(indexPoint != nomFichier.find_first_of('.')  ||
							nomFichier.substr(indexPoint).compare(".log"))
	{
		cerr << "GRAPHE::GRAPHE : Le nom de fichier " << nomFichier <<
										" n'est pas conforme." << endl;
		return;
	}
	if(heure > 24)
	{
		cerr << "GRAPHE::GRAPHE : L'heure " << heure <<
										" n'est pas conforme." << endl;
		return;
	}

	//Construction
	ifstream fichier(nomFichier, ios::in);
	if(!fichier)
	{
		cerr << "GRAPHE::GRAPHE : Le fichier " << nomFichier <<
					" n'existe pas ou ne peut pas être ouvert." << endl;
		return;
	}
	
	string ligne;
	while(getline(fichier, ligne))
	{
		cout << ligne << endl;
		/*
		code à faire
		*/
	}
} //----- Fin de Graphe

Graphe::~Graphe ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe

//----------------------------------------------------- Méthodes publiques
void Graphe::AfficherPlusConsultes() const
// Algorithme : aucun
{
} //----- Fin de AfficherPlusConsultes

bool Graphe::Exporter(const string & nomFichier) const
// Algorithme : aucun
{
	//Vérifications
	unsigned int indexPoint = nomFichier.find_last_of('.');
	if(indexPoint != nomFichier.find_first_of('.')  ||
							nomFichier.substr(indexPoint).compare(".dot"))
	{
		cerr << "GRAPHE::EXPORTER : Le nom de fichier " << nomFichier <<
										" n'est pas conforme." << endl;
		return false;
	}
	
	//Exportation
	fstream fs;
	fs.open(nomFichier, fstream::out | fstream::app);
	if(!fs.is_open())
	{
		fs.close();
		cerr << "GRAPHE::EXPORTER : Le fichier " << nomFichier <<
									" ne peut pas être ouvert." << endl;
		return false;
	}
	
	/*
	code à faire
	*/
	
	fs.close();
	return true;
} //----- Fin de Exporter

//------------------------------------------------------------------ PRIVE
//-------------------------------------------------------- Méthodes privés
void ajouterLien(const string & pageArrivee, const string & pageDepart)
// Algorithme : aucun
{
} //----- Fin de ajouterLien
