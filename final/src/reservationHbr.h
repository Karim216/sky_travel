#include <gtk/gtk.h>

typedef struct 
{
int jour;
int mois;
int annee;
}DH;

typedef struct 
{
char type[20];
char ville[20];
int bebe;
int adult;
int enf;
DH dt_ent;
char idc[20];
char idr[20];
}Reserve;

void ReservationHbr(Reserve h);
void afficherreservationHbr(GtkWidget *liste);
void modifierResHbr(char id1[], char client1[], char ville1[], char type1[], char personne1[], char date1[]);
void supprimReserHbr(char identifiant[]);
