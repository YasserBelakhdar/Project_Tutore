/***********************************************************
 Interface de la classe Cliste.
 Cette classe permet de créer des listes d’éléments dont le type peut être fixé
de façon centralisée.
* **********************************************************/

// Définition des valeurs des exceptions pouvant être levées dans cette classe
#define Ajout impossible 101
#define Suppression impossible 102
#define Position hors liste 103

// Définition du type d’un élément de la liste
// Il faut modifier le type de base ci-dessous pour changer
// le type des éléments de la liste
typedef int Telement;

class Cliste
	{
	// Cette classe représente une ou plusieurs listes d’éléments
	
		// Attributs :
private:
	unsigned int uiLIStaille; //Cet attribut contient le nombre d’éléments de la liste
	Telement* pTeLISliste;

	// Primitives :
public:
		
			Cliste();
		/* Constructeur par défaut de la classe
		E : néant
		nécessite : néant
		S : néant
		entraîne : la liste est initialisée à vide */


			Cliste(const Cliste&);
		/* Constructeur de recopie de la classe
		E : l’objet que l’on recopie dans l’objet en cours
		nécessite : néant
		S : néant
		entraîne : L’objet en cours contient une copie de l’objet passé en paramètre */


			Cliste();
		/* Destructeur de la classe
		E : néant
		nécessite : néant
		S : néant
		entraîne : l’exception est détruite*/


			Cliste & operator=(const Cliste&);
		/* Surcharge de l’opérateur d’affectation
		E : l’objet que l’on affecte dans l’objet en cours
		nécessite : néant
		S : L’objet en cours qui a été recopié
		entraîne : (L’objet en cours contient une copie de l’objet passé en paramètre) ou
		(Exception Ajout impossible : pas assez de mémoire libre) */


			void LISajouter_element(Telement elem, unsigned int pos);
		/* Cette fonction permet d’ajouter un élément dans la liste à la position spécifiée
		E : elem, la valeur à ajouter
		pos, la position d’insertion
		nécessite : néant
		S : néant
		entraîne : (l’élément est ajouté à la position requise) ou
		(Exception Ajout impossible : pas assez de mémoire libre) ou
		(Exception Position hors liste : pos>taille) */


			unsigned int LISlire_taille();
		/* Cette fonction permet de connaître la taille de la liste
		E : rien
		nécessite : néant
		S : la taille de la liste
		entraîne : (la taille de la liste est retournée) */
			Telement LISlire_element(unsigned int pos);
			/* Cette fonction permet de lire la valeur d’un élément dans la liste
		E : la position de l’élément à lire
		nécessite : néant
		S : la valeur de l’élément
		entraîne : (la valeur de l’élément est retournée) ou
		(Exception Position hors liste : pos>=taille) */


			void LISmodifier_element(Telement elem, unsigned int pos);
		 /* Cette fonction permet de modifier la valeur d’un élément dans la liste
		 E : elem, la nouvelle valeur
		pos, la position de l’élément à modifier
		nécessite : néant
		S : néant
		entraîne : (L’élément est modifié) ou
		(Exception Position hors liste : pos>=taille) */


			Telement & operator[ ](unsigned int pos);
		/* Cette fonction permet d’accéder à la valeur d’un élément dans la liste
		E : la position de l’élément à lire
		nécessite : néant
		S : l’élément
		entraîne : (l’élément est accessible) ou
		(Exception Position hors liste : pos>=taille) */


			void LISsupprimer_element(unsigned int pos);
		/* Cette fonction permet de supprimer un élément dans la liste à la position spécifiée
		E : pos, la position de suppression
		nécessite : néant
		S : néant
		entraîne : (l’élément est supprimé à la position requise) ou
		(Exception Suppression impossible : taille=0) ou
		(Exception Position hors liste : pos>=taille) */
	};