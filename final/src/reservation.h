#include <gtk/gtk.h>

typedef struct 
{
int jour;
int mois;
int annee;
}DA;

typedef struct 
{
//char resv[50];
char type[20];
char v_depart[20];
char v_arr[20];
int bebe;
int adult;
int enf;
char idc[20];
char idr[20];
DA dt_res;
int nbj;
}reserve;

void ReservationAgence(reserve a);
//void ReservationExcursion(reserve b);
//void ReservationHeb(reserve c);
//void ReservationLoc(reserve d);




 
void afficherreservation(GtkWidget *liste);
void modifierResVol(char id1[], char client1[], char type1[], char depart1[], char arrivee1[], char passager1[], char date1[]);


void supprimReserVol(char identifiant[]);


/*typedef struct 
{
char type[20];
char v_depart[20];
char v_arr[20];
char passager[50]
char idc[20];
char idr[20];
char date[50];
}Reserve;
*/

