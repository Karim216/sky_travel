#include <gtk/gtk.h>

#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct
{
	int jour;
	int mois;
	int annee;

}DateR;


typedef struct
{
	char reclamation[200];
	char objet[30];
	DateR dt;
        

}reclamation;


void reclamer(reclamation r);
void afficherreclamation(GtkWidget *liste);
