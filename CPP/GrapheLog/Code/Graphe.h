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

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------
#if ! defined ( Graphe_H )
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <unordered_map>

//------------------------------------------------------------------ Types
struct LienPage
{
	// ID de la page concernée
	unsigned int Id;
	
	// Nombre d'accès vers cette page
	unsigned int NbLiens;
	
	
	// Structure de données contenant les accès vers la page d'id Id.
	// Premier entier : Id de page de départ
	// Deuxième entier : nb d'accès
	unordered_map<unsigned int, unsigned int> Liens;
	
	
	// Surcharge de l'opérateur << pour l'écriture dans le fichier .dot.
	friend ostream& operator << (ostream& o, const LienPage& lp)
	{
		for (pair<unsigned int, unsigned int> element : lp.Liens)
			o << "node" << element.first << " -> node" << lp.Id 
				<< " [label=\"" << element.second << "\"]" << endl;
		return o;
	}
};

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
// Cettre classe permet de lire à partir d'un fichier .log :
//		- les pages qui ont été accédées
//		- combien de fois elle ont étés accédées
//		- à partir de quelles pages elles ont été accedées
//
// puis de fournir ces informations sous un formart plus lisible.
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC
public:
//-------------------------------------------- Constructeurs - destructeur
	Graphe (const string & nomFichier, const bool optionE = false, 
		const bool optionG = false, const unsigned int optionHeure = 24);
    // Mode d'emploi : Construit un objet Graphe à partir du fichier qui
    //		se situe à l'adresse nomFichier. Les paramêtres optionE et
    //		optionG indiquent respectivement si l'option e et g est
    //		activée. Le paramêtre heure indique si l'option t est active
    //		et quelle est sa valeure. Si heure est compris entre 0 et 23
    //		inclus alors l'option t est active et a pour valeure heure. Si
    //		heure est égal à 24 alors l'option est inactive.
    // Contrat : Le fichier correspondant à nomFichier est un fichier .log
    //		bien écrit. L'entier naturel heure est compris entre 0 et 24.

    virtual ~Graphe ();
    // Mode d'emploi : aucun
    // Contrat : aucun
    
//----------------------------------------------------- Méthodes publiques
	void AfficherPlusConsultes() const;
    // Mode d'emploi : Affiche les dix pages du graphes qui ont le plus
    //		liens dans leur direction. L'affichage se fait selon l'ordre
    //		décroissant du nombre de liens.
    // Contrat : Aucun.
    
	bool Exporter(const string & nomFichier) const;
    // Mode d'emploi : Si le fichier d'adresse absolue ou relative
    //		nomFichier existe alors il est écrasé, sinon il est créé. Le
    //		Ce même fichier est ensuite remplit du code permettant la
    //		réalisation du Graphe sous forme d'image.
    // Contrat : Le paramêtre nomFichier est l'adresse abolue ou relative
    //		d'un fichier .dot.

#ifdef TEST_FLO
	void AfficheTEST_FLO();
    // Mode d'emploi : Affiche l'objet dans la console.
    // Contrat : Le aucun.
#endif

//------------------------------------------------------------------ PRIVE
private:
//-------------------------------------------------------- Méthodes privés
	void ajouterLien(const string & pageArrivee,
										const string & pageDepart = "");
    // Mode d'emploi : Ajoute au Graphe un lien vers la page pageArrivee.
    //		Si une page pageDepart non vide est renseignée alors la source
    //		du lien est renseignée comme étant pageDepart. Si l'une des
    //		pages pageArrivee ou pageDepart n'est pas présente dans le
    //		Graphe alors elle est ajoutée.
    // Contrat : Le paramêtre page Arrivee est non vide.
//------------------------------------------------------- Attributs privés
	unordered_map<string, unsigned int> index;
	unsigned int maxIndex = 0;
	unordered_map<unsigned int, LienPage> liensPages;
	const string LOCAL_HOST = "intranet-if.insa-lyon.fr";
};
#endif // Graphe_H
