/*CLASSE Cliste
DOCUMENTATION
Attributs : uiLIStaille, entier, contient le nombre d’éléments dans la liste
pTeliste, pointeur, contient les éléments de la liste
Structure : Cette classe contient des méthodes permettant l’ajout, la suppression,
la modification et la consultation d’éléments dans la liste.
Méthode : L’allocation de la liste est gérée dynamiquement par pointeur
Modules internes :*/
//#include <fstream.h>
#include <malloc.h>
#include "Cliste.h"
//#include "Cexception.h"

//CORPS

   /**************************************************************
Nom : Cliste
***************************************************************
Constructeur par défaut de la classe Cliste : permet d’initialiser un objet
***************************************************************
Entrée : rien
Nécessite : néant
Sortie : rien
Entraîne : la liste est initialisée à vide
***************************************************************/
Cliste : : Cliste()
{
	uiLIStaille = 0;
	pTeLISliste = NULL;
	// la liste est vide
		}



/**************************************************************
Nom :  ̃Cliste
***************************************************************
Destructeur de la classe Cliste : permet de détruire un objet
***************************************************************
Entrée : rien
Nécessite : néant
Sortie : rien
Entraîne : la liste est désallouée
***************************************************************/
Cliste : : ̃Cliste()
{
	free(pTeLISliste);
	// la liste est désallouée
		}



/**************************************************************
Nom : Cliste (R)
***************************************************************
Constructeur de recopie de la classe Cliste : permet
d’initialiser un objet par recopie à partir d’un autre
***************************************************************
Entrée : l’objet que l’on recopie dans l’objet en cours
Nécessite : néant
Sortie : rien
Entraîne : L’objet en cours contient une copie de l’objet passé en paramètre
***************************************************************/
Cliste : : Cliste(const Cliste & objet)
{
	int iBoucle;
	
		uiLIStaille = objet.uiLIStaille;
	pTeLISliste = (Telement*)malloc(uiLIStaille * sizeof(Telement));
	// pTeliste pointe sur une zone mémoire allouée mais “vide”
		for (iBoucle = 0; iBoucle < uiLIStaille; iBoucle++)
			pTeLISliste[iBoucle] = objet.pTeLISliste[iBoucle];
	// la liste objet est recopiée dans l’objet en cours
		}



/**************************************************************
Nom : operator=
***************************************************************
Surcharge de l’opérateur d’affectation
***************************************************************
Entrée : l’objet que l’on affecte dans l’objet en cours
Nécessite : néant
Sortie : L’objet en cours qui a été recopié
Entraîne : (L’objet en cours contient une copie de l’objet passé en paramètre) ou
(Exception Ajout impossible : pas assez de mémoire libre)
***************************************************************/
Cliste& Cliste : : operator=(const Cliste& objet)
{
	int iBoucle;

	if (uiLIStaille != 0)
	{ // Il faut vider la liste en cours
		uiLIStaille = 0;
		free(pTeLISliste);
	}

	uiLIStaille = objet.uiLIStaille;
	pTeLISliste = (Telement*)malloc(uiLIStaille * sizeof(Telement));
	if (pTeLISliste == NULL)
	{ // L’agrandissement de la liste est impossible : levée d’une exception
		Cexception pasmemoire;
		pasmemoire.EXCmodifier valeur(Ajout impossible);
		throw(pasmemoire);
	}
	// pTeliste pointe sur une zone mémoire allouée mais “vide”

	for (iBoucle = 0; iBoucle < uiLIStaille; iBoucle++)
		pTeLISliste[iBoucle] = objet.pTeLISliste[iBoucle];
	// la liste objet est recopiée dans l’objet en cours
	return *this;
}
	



/**************************************************************
Nom : LISajouter element
***************************************************************
Cette fonction permet d’ajouter un élément dans la liste à la position spécifiée
***************************************************************
Entrée : elem, la valeur à ajouter
pos, la position d’insertion
Nécessite : néant
Sortie : rien
Entraîne : (l’élément est ajouté à la position requise) ou
(Exception Ajout impossible : pas assez de mémoire libre) ou
(Exception Position hors liste : pos>taille)
***************************************************************/
void Cliste : : LISajouter element(Telement elem, unsigned int pos)
{
	Telement * pTetmp;
	int iBoucle;
	
		if (pos > uiLIStaille)
		{ // L’insertionalieu hors tableau : levée d’une exception
		Cexception horstableau;
		horstableau.EXCmodifier valeur(Position hors liste);
		throw(horstableau);
		}
	
	pTetmp = (Telement*)realloc(pTeLISliste, (uiLIStaille + 1) * sizeof(Telement));
	if (pTetmp == NULL)
		{ // L’agrandissement de la liste est impossible : levée d’une exception
		Cexception pasmemoire;
		pasmemoire.EXCmodifier valeur(Ajout impossible);
		throw(pasmemoire);
		}
	
		uiLIStaille++;
	pTeLISliste = pTetmp;
	for (iBoucle = uiLIStaille; iBoucle > pos; iBoucle−−)
		pTeLISliste[iBoucle] = pTeLISliste[iBoucle−1];
	pTeLISliste[pos] = elem;
	// L’élément est inséré dans la liste à la position demandée
		}



/**************************************************************
Nom : LISlire element
***************************************************************
Cette fonction permet de connaître la taille de la liste
***************************************************************
Entrée : rien
Nécessite : néant
Sortie : la taille de la liste
Entraîne : (la taille de la liste est retournée)
***************************************************************/
unsigned int Cliste : : LISlire taille()
	{
	return (uiLIStaille);
	}



/**************************************************************
Nom : LISlire element
***************************************************************
Cette fonction permet de lire la valeur d’un élément dans la liste
***************************************************************
Entrée : la position de l’élément à lire
Nécessite : néant
Sortie : la valeur de l’élément
Entraîne : (la valeur de l’élément est retournée) ou
(Exception Position hors liste : pos>=taille)
***************************************************************/
Telement Cliste : : LISlire element(unsigned int pos)
{
	if (pos >= uiLIStaille)
		{ // L’insertionalieu hors tableau : levée d’une exception
		Cexception horstableau;
		horstableau.EXCmodifier valeur(Position hors liste);
		throw(horstableau);
		}
	
		// La position est dans le tableau : on retourne l’élément demandé
		return pTeLISliste[pos];
	}



/**************************************************************
Nom : LISmodifier element
***************************************************************
Cette fonction permet de modifier la valeur d’un élément dans la liste
***************************************************************
Entrée : elem, la nouvelle valeur
pos, la position de l’élément à modifier
Nécessite : néant
Sortie : rien
Entraîne : (L’élément est modifié) ou
(Exception Position hors liste : pos>=taille)
***************************************************************/
void Cliste : : LISmodifier element(Telement elem, unsigned int pos)
{
	if (pos >= uiLIStaille)
		// L’insertionalieu hors tableau : levée d’une exception
		Cexception horstableau;
		horstableau.EXCmodifier valeur(Position hors liste);
		throw(horstableau);
		}
	
	// La position est dans le tableau : on modifie l’élément demandé
		pTeLISliste[pos] = elem;
	}



/**************************************************************
Nom : operator[]
***************************************************************
Cette fonction permet d’accéder à la valeur d’un élément dans la liste
***************************************************************
Entrée : la position de l’élément à lire
Nécessite : néant
Sortie : l’élément
Entraîne : (L’élément est accessible) ou
(Exception Position hors liste : pos>=taille)
***************************************************************/
Telement & Cliste : : operator[ ](unsigned int pos)
{
	if (pos >= uiLIStaille)
		{ // L’insertionalieu hors tableau : levée d’une exception
		Cexception horstableau;
		horstableau.EXCmodifier valeur(Position hors liste);
		throw(horstableau);
		}
	
		// La position est dans le tableau : on accède à l’élément demandé
		return(pTeLISliste[pos]);
	}



/**************************************************************
Nom : LISsupprimer element
***************************************************************
Cette fonction permet de supprimer un élément dans la liste à la position spécifiée
***************************************************************
Entrée : la position de l’élément à supprimer
Nécessite : néant
Sortie : rien
Entraîne : (l’élément est supprimé à la position requise) ou
(Exception Position hors liste : pos>=taille)
***************************************************************/
void Cliste : : LISsupprimer element(unsigned int pos)
{int iBoucle;

if (pos >= uiLIStaille)
{ // L’insertionalieu hors tableau : levée d’une exception
	Cexception horstableau;
	horstableau.EXCmodifier valeur(Position hors liste);
	throw(horstableau);
	}

for (iBoucle = pos; iBoucle < uiLIStaille−1; iBoucle++)
	pTeLISliste[iBoucle] = pTeLISliste[iBoucle + 1];
uiLIStaille−−;

// L’élément est supprimé
}