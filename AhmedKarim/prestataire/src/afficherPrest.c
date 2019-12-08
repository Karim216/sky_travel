#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afficherPrest.h"
#include <gtk/gtk.h>


//Affichage des vols
enum
{
	IDENTIFIANT,
	COMPAGNIE,
	AVION,
	CLASSE,
	VILLE_DEPART,
	DATE_DEPART,
	HEURE_DEPART,
	VILLE_ARRIVE,
	DATE_ARRIVE,
	HEURE_ARRIVE,
	PRIX_PREMIERE_CLASSE,
	PRIX_CLASSE_ECONOMIQUE,
	COLUMNS
};



void afficherPrestations(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	char identifiant[50];
	char compagnie[50];
	char avion[50];
	char classe[50];
	char ville_depart[30];
	char date_depart[50];
	char heure_depart[50];
	char ville_arrive[30];
	char date_arrive[50];
	char heure_arrive[50];
	char prix_premiere_classe[50];
	char prix_classe_economique[50];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",IDENTIFIANT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" compagnie", renderer, "text",COMPAGNIE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" avion", renderer, "text",AVION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" classe", renderer, "text",CLASSE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ville depart", renderer, "text",VILLE_DEPART, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date depart", renderer, "text",DATE_DEPART, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" heure depart", renderer, "text",HEURE_DEPART, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ville arrive", renderer, "text",VILLE_ARRIVE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date arrive", renderer, "text",DATE_ARRIVE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" heure arrive", renderer, "text",HEURE_ARRIVE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix premiere classe", renderer, "text",PRIX_PREMIERE_CLASSE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix classe economique", renderer, "text",PRIX_CLASSE_ECONOMIQUE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}

	

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("prestVol.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("prestVol.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s",identifiant,compagnie,avion,classe,ville_depart,date_depart,heure_depart,ville_arrive,date_arrive,heure_arrive,prix_premiere_classe,prix_classe_economique)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter, IDENTIFIANT, identifiant, COMPAGNIE, compagnie, AVION, avion, CLASSE,classe,VILLE_DEPART,ville_depart,DATE_DEPART,date_depart,HEURE_DEPART,heure_depart,VILLE_ARRIVE,ville_arrive,DATE_ARRIVE,date_arrive,HEURE_ARRIVE,heure_arrive,PRIX_PREMIERE_CLASSE,prix_premiere_classe,
PRIX_CLASSE_ECONOMIQUE,prix_classe_economique,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}
