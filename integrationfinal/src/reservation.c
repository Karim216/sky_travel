#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <gtk/gtk.h>
#include "reservation.h"

void ReservationAgence(reserve a)
{
	FILE *f, *g;
	f=fopen("reservationVol.txt","a+");
	g=fopen("reservations.txt","a+");
	if (f!= NULL && g!=NULL){
		fprintf(f,"%s %s %s %s %s %s %d_Bebe(s)/%d_enfant(s)/%d_adulte(s) %d/%d %d \n",a.resv,a.idr,a.idc,a.type,a.v_depart,a.v_arr,&a.bebe,&a.enf,&a.adult,&a.dt_res.jour,&a.dt_res.mois,&a.dt_res.annee);
		fprintf(g,"%s %s %s\n",a.resv,a.idr,a.idc);
	}
	fclose(f);
	fclose(g);
}

/*
enum
{
	RESV,
	IDR,
	IDC,	
	COLUMNS
};



//Affichage de hébergements

void afficherreservation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	//char type[20];
	//char v_depart[20];
	//char v_arr[20];
	//char passager[50];
	char resv[20];
	char idc[20];
	char idr[20];
	//char date[20];
	
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Réservation", renderer, "text",RESV, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id reservation", renderer, "text",IDR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id client", renderer, "text",IDC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("/home/nada/pro/w1/src/reservations.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("/home/nada/pro/w1/src/reservations.txt", "a+");
		while(fscanf(f,"%s %s %s\n",resv,idr,idc)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter,RESV, resv, IDR, idr, IDC, idc,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}



void ReservationExcursion(reserve b)
{
	FILE *f;
        FILE *g;
	f=fopen("/home/nada/pro/w1/src/reservationExcursion.txt","a+");
        g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
	if (f!= NULL){
		fprintf(f,"%s %s %s %d_Bébé(s)/%d_enfant(s)/%d_adulte(s) %d/%d/%d %s %s\n",b.type,b.v_depart,b.v_arr,
b.bebe,b.enf,b.adult,b.dt_res.jour,b.dt_res.mois,b.dt_res.annee,b.idr,b.idc);
                fprintf(g,"%s %s %s\n",b.resv,b.idr,b.idc);

	}
fclose(f);
fclose(g);
	
}
	

void afficherreservation1(GtkWidget *liste)
{

	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	
	char resv[20];
	char idc[20];
	char idr[20];
	
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Réservation", renderer, "text",RESV, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id reservation", renderer, "text",IDR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id client", renderer, "text",IDC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("/home/nada/pro/w1/src/reservation.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("/home/nada/pro/w1/src/reservation.txt", "a+");
		while(fscanf(f,"%s %s %s",resv,idr,idc)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter,RESV, resv, IDR, idr, IDC, idc,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}

	


void ReservationHeb(reserve c)
	
{
	FILE *f, *g;
	f=fopen("/home/nada/pro/w1/src/reservationHeb.txt","a+");
	g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
	if (f!= NULL && g!=NULL)
{
		fprintf(f,"%s %s %s %s %s %d  %d_Bébé(s)/%d_enfant(s)/%d_adulte(s) %d/%d \n",c.resv,c.idr,c.idc,c.type,c.v_arr,c.bebe,c.enf,c.adult,c.dt_res.jour,c.dt_res.mois,c.dt_res.annee);
		fprintf(g,"%s %s %s\n",c.resv,c.idr,c.idc);
	}
	fclose(f);
	fclose(g);
}





//Affichage de hébergements

void afficherreservationH(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	
	char resv[20];
	char idc[20];
	char idr[20];
	
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Réservation", renderer, "text",RESV, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id reservation", renderer, "text",IDR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id client", renderer, "text",IDC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("/home/nada/pro/w1/src/reservation.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("/home/nada/pro/w1/src/reservation.txt", "a+");
		while(fscanf(f,"%s %s %s",resv,idr,idc)!=EOF)


		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter,RESV, resv, IDR, idr, IDC, idc,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}

void ReservationLoc(reserve d)
{
	FILE *f, *g;
	f=fopen("/home/nada/pro/w1/src/reservationLoc.txt","a+");
	g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
	if (f!= NULL && g!=NULL){
		fprintf(f,"%s %s %s %s %d %d %d %d \n",d.resv,d.idr,
d.idc,d.type,d.dt_res.jour,d.dt_res.mois,d.dt_res.annee,d.nbj);
		fprintf(g,"%s %s %s\n",d.resv,d.idr,d.idc);
	}
	fclose(f);
	fclose(g);
}


void afficherreservationL(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	
	char resv[20];
	char idc[20];
	char idr[20];
	
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Réservation", renderer, "text",RESV, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id reservation", renderer, "text",IDR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id client", renderer, "text",IDC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("/home/nada/pro/w1/src/reservation.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("/home/nada/pro/w1/src/reservation.txt", "a+");
		while(fscanf(f,"%s %s %s",resv,idr,idc)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter,RESV, resv, IDR, idr, IDC, idc,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}

void supprimer1(char idrr[])
{
  FILE *f, *g;
  FILE *ftemp, *gtemp;
char resv[50];
char type[20];
char v_depart[20];
char v_arr[20];
int bebe;
int adult;
int enf;
char idc[20];
char idr[20];
Date dt_res;



 

  f = fopen("/home/nada/pro/w1/src/reservationVol.txt","r");
  ftemp = fopen("/home/nada/pro/w1/src/voltemp.txt","w+");
  g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
  gtemp=fopen("/home/nada/pro/w1/src/reservationstemp.txt","a+");

  
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d  %d %d %d ",resv,idr,idc,type,v_depart,v_arr,&bebe,&enf,&adult,&dt_res.jour,&dt_res.mois,&dt_res.annee) != EOF)
    {
      if (strcmp(idrr,idr)!=0)
       
   
          fprintf(ftemp,"%s %s %s %s %s %s %d %d %d  %d %d %d  ",resv,idr,idc,type,v_depart,v_arr,bebe,enf,adult,dt_res.jour,dt_res.mois,dt_res.annee);
          fprintf(gtemp,"%s %s %s",resv,idr,idc);
    }


  fclose(f);
  fclose(ftemp);
remove("/home/nada/pro/w1/src/reservationvol.txt");
remove("/home/nada/pro/w1/src/reservations.txt");
  rename("/home/nada/pro/w1/src/voltemp.txt","/home/nada/pro/w1/src/reservationvol.txt");
rename("/home/nada/pro/w1/src/reservationstemp.txt","/home/nada/pro/w1/src/reservations.txt");
}



void supprimer2(char idrr[])
{
  FILE *f, *g;
  FILE *ftemp, *gtemp;
char resv[50];
char type[20];

char v_arr[20];
int bebe;
int adult;
int enf;
char idc[20];
char idr[20];
Date dt_res;



 

  f = fopen("/home/nada/pro/w1/src/reservationHeb.txt","r");
  ftemp = fopen("/home/nada/pro/w1/src/Hebtemp.txt","w+");
  g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
  gtemp=fopen("/home/nada/pro/w1/src/reservationstemp.txt","a+");

  
    while(fscanf(f,"%s %s %s %s %s %d %d %d  %d %d %d ",resv,idr,idc,type,v_arr,&bebe,&enf,&adult,&dt_res.jour,&dt_res.mois,&dt_res.annee) != EOF)
    {
      if (strcmp(idrr,idr)!=0)
       
   
          fprintf(ftemp,"%s %s %s %s %s %d %d %d  %d %d %d ",resv,idc,idr,type,v_arr,bebe,enf,adult,dt_res.jour,dt_res.mois,dt_res.annee);
          fprintf(gtemp,"%s %s %s",resv,idr,idc);
    }


  fclose(f);
  fclose(ftemp);
remove("/home/nada/pro/w1/src/reservationHeb.txt");
remove("/home/nada/pro/w1/src/reservations.txt");
  rename("/home/nada/pro/w1/src/Hebtemp.txt","/home/nada/pro/w1/src/reservationHeb.txt");
rename("/home/nada/pro/w1/src/reservationstemp.txt","/home/nada/pro/w1/src/reservations.txt");
}


void supprimer3(char idrr[])
{
  FILE *f, *g;
  FILE *ftemp, *gtemp;
char resv[50];
char type[20];
char v_depart[20];
char v_arr[20];
int bebe;
int adult;
int enf;
char idc[20];
char idr[20];
Date dt_res;



 

  f = fopen("/home/nada/pro/w1/src/reservationExcursion.txt","r");
  ftemp = fopen("/home/nada/pro/w1/src/Excursiontemp.txt","w+");
  g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
  gtemp=fopen("/home/nada/pro/w1/src/Excursiontemp.txt","a+");

  
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d  %d %d %d ",resv,idr,idc,type,v_depart,v_arr,&bebe,&enf,&adult,&dt_res.jour,&dt_res.mois,&dt_res.annee)!=EOF)
    {
      if (strcmp(idrr,idr)!=0)
       
   
          fprintf(ftemp,"%s %s %s %s %s %s %d %d %d  %d %d %d  ",resv,idr,idc,type,v_depart,v_arr,bebe,enf,adult,dt_res.jour,dt_res.mois,dt_res.annee);
          fprintf(gtemp,"%s %s %s",resv,idr,idc);
    }


  fclose(f);
  fclose(ftemp);
remove("/home/nada/pro/w1/src/reservationExcursion.txt");
remove("/home/nada/pro/w1/src/reservations.txt");
  rename("/home/nada/pro/w1/src/Excursiontemp.txt","/home/nada/pro/w1/src/reservationExcursion.txt");
rename("/home/nada/pro/w1/src/reservationstemp.txt","/home/nada/pro/w1/src/reservations.txt");
}


void supprimer4(char idrr[])
{
  FILE *f, *g;
  FILE *ftemp, *gtemp;
char resv[50];
char type[20];
char idc[20];
char idr[20];
int nbj;
Date dt_res;



 

  f = fopen("/home/nada/pro/w1/src/reservationLoc.txt","r");
  ftemp = fopen("/home/nada/pro/w1/src/Locationtemp.txt","w+");
  g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
  gtemp=fopen("/home/nada/pro/w1/src/Locationtemp.txt","a+");

  
    while(fscanf(f,"%s %s %s %s %d %d %d %d \n",resv,idr,
idc,type,&dt_res.jour,&dt_res.mois,&dt_res.annee,&nbj)!=EOF)
    {
      if (strcmp(idrr,idr)!=0)
       
   
          fprintf(ftemp,"%s %s %s %s %d %d %d %d \n",resv,idr,
idc,type,dt_res.jour,dt_res.mois,dt_res.annee,nbj);
          fprintf(gtemp,"%s %s %s",resv,idr,idc);
    }


  fclose(f);
  fclose(ftemp);
remove("/home/nada/pro/w1/src/reservationLoc.txt");
remove("/home/nada/pro/w1/src/reservations.txt");
  rename("/home/nada/pro/w1/src/Locationtemp.txt","/home/nada/pro/w1/src/reservationLoc.txt");
rename("/home/nada/pro/w1/src/reservationstemp.txt","/home/nada/pro/w1/src/reservations.txt");
}


 reserve recherche_reservationV (char idrr[30])
{
   FILE *f;

   reserve a;
   
 f = fopen("/home/nada/pro/w1/src/reservationVol.txt","r");
if(f!=NULL)
    {
   while(fscanf(f,"%s %s %s %s %s %s %d %d %d  %d %d %d ",a.resv,a.idr,a.idc,a.type,a.v_depart,a.v_arr,a.bebe,a.enf,a.adult,a.dt_res.jour,a.dt_res.mois,a.dt_res.annee) != EOF)
    {
      if (strcmp(idrr,a.idr)!=0)
        {
return a;
        fclose(f);
}
    }

    fclose (f);}
    return a;
}

*/

/*
void modifier_vol(char [])
{
    FILE *f, *g;
  FILE *ftemp, *gtemp;
     f = fopen("/home/nada/pro/w1/src/reservationVol.txt","r");
  ftemp = fopen("/home/nada/pro/w1/src/voltemp.txt","w+");
  g=fopen("/home/nada/pro/w1/src/reservations.txt","a+");
  gtemp=fopen("/home/nada/pro/w1/src/reservationstemp.txt","a+");
   
    if(f!=NULL)
    { if(ftemp!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s  %d %d   ",a.resv,a.idr,a.idc,a.type,a.v_depart,a.v_arr,a.bebe,a.dt_res.jour !=EOF)
        {
            if (strcmp(idrr,a.idr)!=0)
            {
                fprintf(ftemp,"%s %s %s %s %s %s  %d %d   ",a.resv1,a.idr1,a.idc1,a.type1,a.v_depart1,a.v_arr1,a.bebe1,a.dt_res.jour1);

            }
            else
            {
                fprintf(ftemp,"%s %s %s %s %s %s  %d %d   ",a.resv,a.idr,a.idc,a.type,a.v_depart,a.v_arr,a.bebe,a.dt_res.jour);
            }
        }
        fclose(f);
        fclose(ftemp);
remove("/home/nada/pro/w1/src/reservationvol.txt");
remove("/home/nada/pro/w1/src/reservations.txt");
rename("/home/nada/pro/w1/src/voltemp.txt","/home/nada/pro/w1/src/reservationvol.txt");
rename("/home/nada/pro/w1/src/reservationstemp.txt","/home/nada/pro/w1/src/reservations.txt");  

    }
    }

}

*/
