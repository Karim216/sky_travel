#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supprPrest.h"



//fonction suppression d'une prestation de vol
void supprimPrest(char identifiant[])
{
	char id[50];
	char comp[50];
	char avion[50];
	char classe[50];
	char dpt_ville[50];
	char arr_ville[50];
	char pr_class[50];
	char econ[50];

	char date_dpt[50];
	char date_arr[50];
	char heure_dpt[50];
	char heure_arr[50];

	FILE *f;
	FILE *g;

	f=fopen("prestVol.txt","a+");
	g=fopen("supprPrest.txt","a+");

	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",id,comp,avion,classe,dpt_ville,date_dpt,heure_dpt,
								arr_ville,date_arr,heure_arr,pr_class,econ)!=EOF)
	{
		if (strcmp(identifiant,id)!=0)
			fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %s\n",id,comp,avion,classe,dpt_ville,date_dpt,
									heure_dpt,arr_ville,date_arr,heure_arr,pr_class,econ);
	}
	fclose(f);
	fclose(g);

	remove("prestVol.txt");
	rename("supprPrest.txt","prestVol.txt");
}



//suppressionde d'une prestation pour les hébergements
int supprimHbr(char identifiant[])
{
	char id[50];
	char categ[50];
	char hotel[50];
	char dispo[50];
	char chamb[50];
	char ville[50];
	char prix[50];
	char com[50];

	

	FILE *f;
	FILE *g;

	f=fopen("hebergement.txt","a+");
	g=fopen("tmp.txt","a+");

	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,categ,hotel,dispo,chamb,ville,prix,com)!=EOF)
{
		if (strcmp(identifiant,id)!=0)
			fprintf(g,"%s %s %s %s %s %s %s %s\n",id,categ,hotel,dispo,chamb,ville,prix,com);
	}
	fclose(f);
	fclose(g);

	remove("hebergement.txt");
	rename("tmp.txt","hebergement.txt");
}


//Supprimer une prestation de location de voiture
int supprimVoiture(char identifiant[])
{
	char id[50];
	char marq[50];
	char type[50];
	char km[50];
	char vitesse[50];
	char dispo[50];
	char com[50];
	char prix[50];

	

	FILE *f;
	FILE *g;

	f=fopen("voiture.txt","a+");
	g=fopen("tmp.txt","a+");

	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,marq,type,km,vitesse,dispo,com,prix)!=EOF)
	{
		if (strcmp(identifiant,id)!=0)
			fprintf(g,"%s %s %s %s %s %s %s %s\n",id,marq,type,km,vitesse,dispo,com,prix);
	}
	fclose(f);
	fclose(g);

	remove("voiture.txt");
	rename("tmp.txt","voiture.txt");

}


int supprimOffre(char numero[])
{
	char num[50];
	char offre[50];
	char ville[50];
	char carac[50];
	char prix[50];
	char date[50];

	

	FILE *f;
	FILE *g;

	f=fopen("Toffre.txt","a+");
	g=fopen("tmp.txt","a+");

	while(fscanf(f,"%s %s %s %s %s %s\n",num,offre,date,ville,carac,prix)!=EOF)
	{
		if (strcmp(numero,num)!=0)
			fprintf(g,"%s %s %s %s %s %s\n",num,offre,date,ville,carac,prix);
	}
	fclose(f);
	fclose(g);

	remove("Toffre.txt");
	rename("tmp.txt","Toffre.txt");

}
