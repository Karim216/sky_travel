#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "reservation.h"

void ReservationAgence(reserve a)
{
	FILE *f;
	f=fopen("reservationVol.txt","a+");
	//g=fopen("reservations.txt","a+");
	if (f!= NULL){
		fprintf(f,"%s %s %s %s %s %d_Bebe(s)/%d_enfant(s)/%d_adulte(s) %d/%d/%d\n",a.idr,a.idc,a.type,a.v_depart,a.v_arr,a.bebe,a.enf,a.adult,a.dt_res.jour,a.dt_res.mois,a.dt_res.annee);
		//fprintf(g,"%s %s %s\n",a.resv,a.idr,a.idc);
	}
	fclose(f);
	//fclose(g);
}


//Affichage de hébergements
enum
{
	IDENTIFIANT,
	CLIENT,
	TYPE,
	DEPART,
	ARRIVEE,
	PASSAGER,
	DATE,
	COLUMNS
};

void afficherreservation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	char identifiant[50];
	char client[50];
	char type[50];
	char depart[50];
	char arrivee[30];
	char passager[30];
	char date[20];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",IDENTIFIANT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id client", renderer, "text",CLIENT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" type", renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" arrivee", renderer, "text",ARRIVEE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" passager", renderer, "text",PASSAGER, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}

	

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("reservationVol.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("reservationVol.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s",identifiant,client,type,depart,arrivee,passager,date)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter, IDENTIFIANT, identifiant, CLIENT, client, TYPE, type, DEPART, depart, ARRIVEE, arrivee, PASSAGER, passager, DATE, date,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}



//modifier une reservation pour le vol
void modifierResVol(char id1[], char client1[], char type1[], char depart1[], char arrivee1[], char passager1[], char date1[]){

	char id[50];
	char client[50];
	char type[50];
	char depart[50];
	char arrivee[50];
	char passager[50];
	char date[50];

	FILE *f;
	FILE* f_tmp;

	f=fopen("reservationVol.txt","r");
 	f_tmp=fopen("tmp.txt","a+");
  	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s %s\n",id,client,type,depart,arrivee,passager,date)!=EOF){
                	if (strcmp(id,id1)!=0){
                    		fprintf(f_tmp,"%s %s %s %s %s %s %s\n",id,client,type,depart,arrivee,passager,date);
                   
                   	}
                	else{
                    		fprintf(f_tmp,"%s %s %s %s %s %s %s\n",id1,client1,type1,depart1,arrivee1,passager1,date1);
                  	}
          	}
     	}
	fclose(f);
	fclose(f_tmp);

     
        rename("tmp.txt","reservationVol.txt");
}


void supprimReserVol(char identifiant[])
{
	char id[50];
	char client[50];
	char type[50];
	char depart[50];
	char arrivee[50];
	char passager[50];
	char date[50];

	FILE *f;
	FILE *g;

	f=fopen("reservationVol.txt","a+");
	g=fopen("supprReserVol.txt","a+");

	while(fscanf(f,"%s %s %s %s %s %s %s\n",id,client,type,depart,arrivee,passager,date)!=EOF)
	{
		if (strcmp(identifiant,id)!=0)
			fprintf(g,"%s %s %s %s %s %s %s\n",id,client,type,depart,arrivee,passager,date);
	}
	fclose(f);
	fclose(g);

	remove("reservationVol.txt");
	rename("supprReserVol.txt","reservationVol.txt");
}
