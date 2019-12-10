//#include <gtk/gtk.h>

typedef struct 
{
int jour;
int mois;
int annee;
}DA;

typedef struct 
{
char resv[50];
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

//reserve recherche_reservationV (char idrr[30]);
void ReservationAgence(reserve a);
/*void ReservationExcursion(reserve b);
void ReservationHeb(reserve c);
void ReservationLoc(reserve d);




 
void afficherreservation(GtkWidget *liste);
void afficherreservation1(GtkWidget *liste);
void afficherreservationH(GtkWidget *liste);
void afficherreservationL(GtkWidget *liste);


void supprimer1(char idrr[]);
void supprimer2(char idrr[]);
void supprimer3(char idrr[]);
void supprimer4(char idrr[]);*/


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

