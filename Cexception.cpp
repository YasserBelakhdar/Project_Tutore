/*CLASSE Cexception
DOCUMENTATION
Attributs : uiEXCvaleur, entier, contient la valeur de l�exception
Structure : Cette classe contient une m�thode de modification et une m�thode
de consultation de la valeur de l�exception
M�thode : n�ant
Modules internes :*/
#include <fstream.h>
#include "Cexception.h"

//CORPS

/**************************************************************
Nom : Cexception
***************************************************************
Constructeur par d�faut de la classe Cexception : permet
d�initialiser un objet
***************************************************************
Entr�e : rien
N�cessite : n�ant
Sortie : rien
Entra�ne : L�exception est intialis�e � FAUX
***************************************************************/
Cexception : : Cexception()
{
	uiEXCvaleur = FAUX;
	// l�exception est initialis�e
		}



/**************************************************************
Nom : EXCmodifier valeur
***************************************************************
Cette fonction permet de modifier la valeur de l�exception
***************************************************************
Entr�e : la nouvelle valeur de l�exception
N�cessite : n�ant
Sortie : rien
Entra�ne : L�exception est modifi�e
***************************************************************/
void Cexception : : EXCmodifier valeur(unsigned int val)
{
	uiEXCvaleur = val;
	// l�exception est modifi�e
		}



/**************************************************************
Nom : EXClire valeur
***************************************************************
Cette fonction permet de consulter la valeur de l�exception
***************************************************************
Entr�e : rien
N�cessite : n�ant
Sortie : la valeur de l�exception
Entra�ne : L�exception est retourn�e
***************************************************************/
inline unsigned int Cexception : : EXClire valeur()
{
	return(uiEXCvaleur);
	}