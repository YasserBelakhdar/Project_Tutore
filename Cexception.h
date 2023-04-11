// D�finition de la valeur initiale d�une exception
#define FAUX 0

class Cexception
{
	// Cette classe repr�sente une ou plusieurs exceptions lev�es
		// par le programme
		
		//Attributs :

private:
		unsigned int uiEXCvaleur; //Cette variable contient la valeur de l�exception
	
		/*ETAT INITIAL
		uiEXCvaleur = FAUX*/
		
		//Primitives :
public:

		Cexception();
	/* Constructeur par d�faut de la classe
	E : n�ant
	 n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est initialis� � FAUX */


		~Cexception() {}
	/* Destructeur de la classe
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est d�truite*/


		void EXCmodifier valeur(unsigned int);
	/* Cette fonction permet de modifier la valeur de l�exception
	E : nouvelle valeur
	n�cessite : n�ant
	S : n�ant
	entra�ne : la valeur de l�exception est modifi�e*/


		unsigned int EXClire valeur();
	/* Cette fonction permet de consulter la valeur de l�exception
	E : n�ant
	n�cessite : n�ant
	S : valeur de l�exception
	entra�ne : la valeur de l�exception est retourn�e*/
		};