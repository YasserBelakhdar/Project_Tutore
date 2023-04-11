/***********************************************************
 Interface de la classe Cliste.
 Cette classe permet de cr�er des listes d��l�ments dont le type peut �tre fix�
de fa�on centralis�e.
* **********************************************************/

// D�finition des valeurs des exceptions pouvant �tre lev�es dans cette classe
#define Ajout impossible 101
#define Suppression impossible 102
#define Position hors liste 103

// D�finition du type d�un �l�ment de la liste
// Il faut modifier le type de base ci-dessous pour changer
// le type des �l�ments de la liste
typedef int Telement;

class Cliste
	{
	// Cette classe repr�sente une ou plusieurs listes d��l�ments
	
		// Attributs :
private:
	unsigned int uiLIStaille; //Cet attribut contient le nombre d��l�ments de la liste
	Telement* pTeLISliste;

	// Primitives :
public:
		
			Cliste();
		/* Constructeur par d�faut de la classe
		E : n�ant
		n�cessite : n�ant
		S : n�ant
		entra�ne : la liste est initialis�e � vide */


			Cliste(const Cliste&);
		/* Constructeur de recopie de la classe
		E : l�objet que l�on recopie dans l�objet en cours
		n�cessite : n�ant
		S : n�ant
		entra�ne : L�objet en cours contient une copie de l�objet pass� en param�tre */


			Cliste();
		/* Destructeur de la classe
		E : n�ant
		n�cessite : n�ant
		S : n�ant
		entra�ne : l�exception est d�truite*/


			Cliste & operator=(const Cliste&);
		/* Surcharge de l�op�rateur d�affectation
		E : l�objet que l�on affecte dans l�objet en cours
		n�cessite : n�ant
		S : L�objet en cours qui a �t� recopi�
		entra�ne : (L�objet en cours contient une copie de l�objet pass� en param�tre) ou
		(Exception Ajout impossible : pas assez de m�moire libre) */


			void LISajouter_element(Telement elem, unsigned int pos);
		/* Cette fonction permet d�ajouter un �l�ment dans la liste � la position sp�cifi�e
		E : elem, la valeur � ajouter
		pos, la position d�insertion
		n�cessite : n�ant
		S : n�ant
		entra�ne : (l��l�ment est ajout� � la position requise) ou
		(Exception Ajout impossible : pas assez de m�moire libre) ou
		(Exception Position hors liste : pos>taille) */


			unsigned int LISlire_taille();
		/* Cette fonction permet de conna�tre la taille de la liste
		E : rien
		n�cessite : n�ant
		S : la taille de la liste
		entra�ne : (la taille de la liste est retourn�e) */
			Telement LISlire_element(unsigned int pos);
			/* Cette fonction permet de lire la valeur d�un �l�ment dans la liste
		E : la position de l��l�ment � lire
		n�cessite : n�ant
		S : la valeur de l��l�ment
		entra�ne : (la valeur de l��l�ment est retourn�e) ou
		(Exception Position hors liste : pos>=taille) */


			void LISmodifier_element(Telement elem, unsigned int pos);
		 /* Cette fonction permet de modifier la valeur d�un �l�ment dans la liste
		 E : elem, la nouvelle valeur
		pos, la position de l��l�ment � modifier
		n�cessite : n�ant
		S : n�ant
		entra�ne : (L��l�ment est modifi�) ou
		(Exception Position hors liste : pos>=taille) */


			Telement & operator[ ](unsigned int pos);
		/* Cette fonction permet d�acc�der � la valeur d�un �l�ment dans la liste
		E : la position de l��l�ment � lire
		n�cessite : n�ant
		S : l��l�ment
		entra�ne : (l��l�ment est accessible) ou
		(Exception Position hors liste : pos>=taille) */


			void LISsupprimer_element(unsigned int pos);
		/* Cette fonction permet de supprimer un �l�ment dans la liste � la position sp�cifi�e
		E : pos, la position de suppression
		n�cessite : n�ant
		S : n�ant
		entra�ne : (l��l�ment est supprim� � la position requise) ou
		(Exception Suppression impossible : taille=0) ou
		(Exception Position hors liste : pos>=taille) */
	};