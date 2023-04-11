// Définition de la valeur initiale d’une exception
#define FAUX 0

class Cexception
{
	// Cette classe représente une ou plusieurs exceptions levées
		// par le programme
		
		//Attributs :

private:
		unsigned int uiEXCvaleur; //Cette variable contient la valeur de l’exception
	
		/*ETAT INITIAL
		uiEXCvaleur = FAUX*/
		
		//Primitives :
public:

		Cexception();
	/* Constructeur par défaut de la classe
	E : néant
	 nécessite : néant
	S : néant
	entraîne : l’exception est initialisé à FAUX */


		~Cexception() {}
	/* Destructeur de la classe
	E : néant
	nécessite : néant
	S : néant
	entraîne : l’exception est détruite*/


		void EXCmodifier valeur(unsigned int);
	/* Cette fonction permet de modifier la valeur de l’exception
	E : nouvelle valeur
	nécessite : néant
	S : néant
	entraîne : la valeur de l’exception est modifiée*/


		unsigned int EXClire valeur();
	/* Cette fonction permet de consulter la valeur de l’exception
	E : néant
	nécessite : néant
	S : valeur de l’exception
	entraîne : la valeur de l’exception est retournée*/
		};