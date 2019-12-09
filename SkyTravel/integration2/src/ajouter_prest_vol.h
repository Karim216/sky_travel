#include <gtk/gtk.h>


//ajouter une prestation pour le Vol
typedef struct
{
	int jour_dpt;
	int mois_dpt;
	int annee_dpt;
	int jour_arr;
	int mois_arr;
	int annee_arr;
	int heure_dpt;
	int minute_dpt;
	int heure_arr;
	int minute_arr;
}Date;

typedef struct
{
	char id[50];
	char comp[50];
	char avion[50];
	char classe[50];
	char dpt_ville[50];
	char arr_ville[50];
	char pr_class[50];
	Date dt_vol;
	char econ[50];

}Ajouter;

void ajouterPrestVol(Ajouter a);


//ajouter une prestation pour l'hébergement
typedef struct
{
	char id[50];
	char categ[50];
	char hotel[50];
	char dispo[50];
	char nbrChamb[50];
	char ville[50];
	char varPrix[50];
	char com[50];
	
}AjouterHbr;

void ajouterPrestHbr(AjouterHbr h);

//ajouter une prestation pour location de voiture

typedef struct
{
	char id[50];
	char marq[50];
	char type[50];
	char km[50];
	char vitesse[50];
	char dispo[50];
	char com[50];
	char prix[50];
	
}AjouterPrestVoit;

void ajouterPrestVoit(AjouterPrestVoit v);

typedef struct
{
	int jour;
	int mois;
	int annee;
	
}Date_of;


typedef struct
{
	char num[50];
	char offre[50];
	Date_of of;
	char ville[50];
	char carac[50];
	char prix[50];
	
}Offre;

void ajouterOffre(Offre o);


//apout offre spécial

typedef struct
{
	char nom[50];
	int jour1;
	char desc1[50];
	char desc2[50];
	char desc3[50];
	char desc4[50];
	char desc5[50];
	
}special;

void ajoutOffreSpecial(special s);
