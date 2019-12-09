#include <gtk/gtk.h>

typedef struct
{

char cin[20];
char nom[20];
char prenom[30];
char date_naissance[30];
char adresse[10];
char mail[30];
char pays[30];
char pass[30];


}Personne;

void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
void modifier(Personne p);
void supprimer(char cinn[]);
