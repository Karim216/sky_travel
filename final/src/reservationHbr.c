#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "reservationHbr.h"

void ReservationHbr(Reserve h)
{
	FILE *f;
	f=fopen("reservationHbr.txt","a+");
	
	if (f!= NULL){
		fprintf(f,"%s %s %s %s %d_Bebe(s)/%d_enfant(s)/%d_adulte(s) %d/%d/%d\n",h.idr,h.idc,h.ville,h.type,h.bebe,h.enf,h.adult,h.dt_ent.jour,h.dt_ent.mois,h.dt_ent.annee);
	}
	fclose(f);
}


//Affichage de hébergements
enum
{
	IDENTIFIANT,
	CLIENT,
	TYPE,
	VILLE,
	PERSONNE,
	DATE,
	COLUMNS
};

void afficherreservationHbr(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	char identifiant[50];
	char client[50];
	char type[50];
	char ville[50];
	char personne[30];
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
		column = gtk_tree_view_column_new_with_attributes(" ville", renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" type", renderer, "text",VILLE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" personne", renderer, "text",PERSONNE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}

	

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("reservationHbr.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("reservationHbr.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s",identifiant,client,type,ville,personne,date)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter, IDENTIFIANT, identifiant, CLIENT, client, TYPE, type, VILLE, ville, PERSONNE, personne, DATE, date,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}



//modifier une reservation pour le HBR
void modifierResHbr(char id1[], char client1[], char ville1[], char type1[], char personne1[], char date1[]){

	char id[50];
	char client[50];
	char type[50];
	char ville[50];
	char personne[50];
	char date[50];

	FILE *f;
	FILE* f_tmp;

	f=fopen("reservationHbr.txt","r");
 	f_tmp=fopen("tmp.txt","a+");
  	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s\n",id,client,ville,type,personne,date)!=EOF){
                	if (strcmp(id,id1)!=0){
                    		fprintf(f_tmp,"%s %s %s %s %s %s\n",id,client,ville,type,personne,date);
                   
                   	}
                	else{
                    		fprintf(f_tmp,"%s %s %s %s %s %s\n",id1,client1,ville1,type1,personne1,date1);
                  	}
          	}
     	}
	fclose(f);
	fclose(f_tmp);

     
        rename("tmp.txt","reservationHbr.txt");
}


void supprimReserHbr(char identifiant[])
{
	char id[50];
	char client[50];
	char type[50];
	char ville[50];
	char personne[50];
	char date[50];

	FILE *f;
	FILE *g;

	f=fopen("reservationHbr.txt","a+");
	g=fopen("supprReserHbr.txt","a+");

	while(fscanf(f,"%s %s %s %s %s %s\n",id,client,ville,type,personne,date)!=EOF)
	{
		if (strcmp(identifiant,id)!=0)
			fprintf(g,"%s %s %s %s %s %s\n",id,client,ville,type,personne,date);
	}
	fclose(f);
	fclose(g);

	remove("reservationHbr.txt");
	rename("supprReserHbr.txt","reservationHbr.txt");
}
