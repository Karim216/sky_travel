#include <gtk/gtk.h>
typedef struct
{

        int jour;
	int mois;
	int annee;


}DT;


typedef struct
{

        char id [30];
        char n [30];
	char emis_par [30];
        char prestation [30];
	char id_prestation [30];
        char code_coupan [30];
        char mantant_HT[30] ;
	char mantant_TTC[30] ;
	DT fact;


}facture;



void ajouter_facture(facture f);
void afficher_facture(GtkWidget *liste);

void supprimer_facture(char id[]);


void modifier_f(  char idd[], char montant[],char n[],char prest[],char agent[],char date[] );
