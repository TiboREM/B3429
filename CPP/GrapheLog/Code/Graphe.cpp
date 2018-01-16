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
#include <map>

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe (const string & nomFichier, const bool optionE, 
					const bool optionG, const unsigned int optionHeure)
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
	if(optionHeure > 24)
	{
		cerr << "GRAPHE::GRAPHE : L'heure " << optionHeure <<
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
#ifdef TEST_FLO
		cout << "Traitement de la ligne : " << ligne << endl;
#endif
		bool aEnregistrer = true;
		
		//récupération de la page d'arrivée
		size_t indexDebutPageArrivee = ligne.find_first_of('"');
		indexDebutPageArrivee = ligne.find_first_of(' ',
											indexDebutPageArrivee + 1);
		size_t indexFinPageArrivee = ligne.find_first_of(' ',
											indexDebutPageArrivee + 1);
		string pageArrivee = ligne.substr(indexDebutPageArrivee + 1,
					indexFinPageArrivee - indexDebutPageArrivee - 1);
#ifdef TEST_FLO
		cout << "    Page d'arrivée : " << pageArrivee << endl;
#endif

		//récupération de l'heure
		if(optionHeure != 24)
		{
			size_t indexDebutHeure = ligne.find_first_of(':');
			size_t indexFinHeure = ligne.find_first_of(':',
													indexDebutHeure + 1);
			string heureTexte = ligne.substr(indexDebutHeure + 1,
									indexFinHeure - indexDebutHeure - 1);
			unsigned int heure = stoul(heureTexte);
#ifdef TEST_FLO
			cout << "    Option heure : " << heure << endl;
#endif
			if(optionHeure != heure)
			{
				aEnregistrer = false;
#ifdef TEST_FLO
			cout << "    L'heure ne convient pas." << endl;
#endif
			}
		}
		
		//récupération extension  de la page d'arrivée
		if(aEnregistrer &&  optionE)
		{
			size_t indexExtension =pageArrivee.find_last_of('.');
			if(indexExtension != string::npos)
			{
				string extension = pageArrivee.substr(indexExtension);
#ifdef TEST_FLO
				cout << "    Option extension : " << extension << endl;
#endif
				if(extension == ".css"  ||  extension == ".js"  ||
						extension == ".jpeg"  ||  extension == ".gif"  ||
						extension == "jpg")
				{
					aEnregistrer = false;
#ifdef TEST_FLO
				cout << "    L'extension ne convient pas." << endl;
#endif
				}
			}
#ifdef TEST_FLO
			else
			{
				cout << "    Option extension : pas d'extentsion." << endl;
			}
#endif
		}
		
		//récupération de la page de départ
		string pageDepart = "";
		if(aEnregistrer  && optionG)
		{
			size_t indexDebutPageDepart = ligne.find_first_of('"',
												indexFinPageArrivee + 1);
			indexDebutPageDepart = ligne.find_first_of('"',
												indexDebutPageDepart + 1);
			size_t indexFinPageDepart = ligne.find_first_of('"',
												indexDebutPageDepart + 1);
			pageDepart = ligne.substr(indexDebutPageDepart + 1,
						indexFinPageDepart - indexDebutPageDepart - 1);
#ifdef TEST_FLO
			cout << "    Option avec page de départ : " << pageDepart <<
																	endl;
#endif
		}
		
		//ajout du lien
		if(aEnregistrer)
		{
			ajouterLien(pageArrivee, pageDepart);
#ifdef TEST_FLO
			cout << "    Ajout du lien : " << pageArrivee << " <- " <<
														pageDepart << endl;
#endif
		}
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
	// int : nombre de visites
	// string : nom de la page
	multimap<unsigned int, string> classement;
	
	//cout << "taille : " << index.size() << endl;
	for(auto &it : index)
	{
		string nomPage = it.first;
		if(liensPages.count(it.second))
			LienPage lienPage = liensPages.at(it.second);
		unsigned int nbLiens = 0;//lienPage.NbLiens;
		
		//cout << nomPage << " " << nbLiens << "---" << it.second << endl;
		
		classement.insert({nbLiens, nomPage});

	}
	
	
	for(auto it = classement.end();	it != classement.begin(); --it)
	{
		// it->first  : nom de la page
		// it->second : struc de type LienPage
		// it->second.NbLiens : nombre d'accès à la page
		
		cout << it->second << " (" << it->first << " hits)" << endl;
	}
} //----- Fin de AfficherPlusConsultes

bool Graphe::Exporter(const string & nomFichier) const
// Algorithme : aucun
{
	//Vérifications
	size_t indexPoint = nomFichier.find_last_of('.');
	if(indexPoint != nomFichier.find_first_of('.')  ||
							nomFichier.substr(indexPoint).compare(".dot"))
	{
		cerr << "GRAPHE::EXPORTER : Le nom de fichier " << nomFichier <<
										" n'est pas conforme." << endl;
		return false;
	}
	
	//Exportation
	fstream fs;
	fs.open(nomFichier, fstream::trunc | fstream::out);
	if(!fs.is_open())
	{
		fs.close();
		cerr << "GRAPHE::EXPORTER : Le fichier " << nomFichier <<
									" ne peut pas être ouvert." << endl;
		return false;
	}
	
	//Exportation
	fs << "digraph {" << endl;
	for(auto it = index.begin(); it != index.end(); ++it)
	{
		fs << "node" << it->second << " [label=\"" << it->first << "\"];"
																<< endl;
	}
	for(auto jt = index.begin(); jt != index.end(); ++jt)
	{
		if(liensPages.count(jt->second))
			fs << liensPages.at(jt->second);
	}
	fs << "}";
	fs.close();
	return true;
} //----- Fin de Exporter

#ifdef TEST_FLO
void Graphe::AfficheTEST_FLO()
// Algorithme : aucun
{
	cout << "---- AFFICHAGE -----" <<endl;
	for(auto it = index.begin(); it != index.end(); ++it)
	{
		LienPage lienPage = liensPages[it->second];
		cout << it->second << " - " << it->first << endl;
		cout << "    NbLiens = " << lienPage.NbLiens << endl;
		for(auto jt = lienPage.Liens.begin(); jt != lienPage.Liens.end();
																	++jt)
		{
			cout << "        " << jt->first << " x" <<jt->second << endl;
		}
	}
	cout << "--------------------" <<endl;
} //----- Fin de AfficheTEST_FLO
#endif

//------------------------------------------------------------------ PRIVE
//-------------------------------------------------------- Méthodes privés
void Graphe::ajouterLien(const string & pageArrivee,
												const string & pageDepart)
// Algorithme : aucun
{
	if(!index.count(pageArrivee))
	{
		index[pageArrivee] = maxIndex++;
	}
	
	unsigned int indexPageArrivee = index[pageArrivee];
	LienPage * lienPage = &liensPages[indexPageArrivee];
	++lienPage->NbLiens;
	
	if(!pageDepart.empty())
	{
		if(!index.count(pageDepart))
		{
			index[pageDepart] = maxIndex++;
		}
		unsigned int indexPageDepart = index[pageDepart];
		
		if(!lienPage->Liens.count(indexPageDepart))
		{
			lienPage->Liens[indexPageDepart] = 1;
		}
		else
		{
			++lienPage->Liens[indexPageDepart];
		}
	}
} //----- Fin de ajouterLien
