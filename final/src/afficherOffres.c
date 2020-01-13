#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afficherOffres.h"
#include <gtk/gtk.h>

enum
{
	NUM,
	OFFRE,
	DATE,
	VILLE,
	CARAC,
	PRIX,
	COLUMNS
};



//Affichage de hébergements

void afficherPrestationOffre(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	char num[50];
	char offre[50];
	char date[50];
	char ville[50];
	char carac[50];
	char prix[50];

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" offre", renderer, "text",OFFRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ville", renderer, "text",VILLE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Description", renderer, "text",CARAC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("Toffre.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("Toffre.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s",num,offre,date,ville,carac,prix)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter, NUM, num, OFFRE, offre, DATE, date, VILLE,ville,CARAC,carac,PRIX,prix,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}
