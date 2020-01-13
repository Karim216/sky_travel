#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichageHbr.h"
#include <gtk/gtk.h>

enum
{
	IDENTIFIANT_HBR,
	CATEGORIE,
	HOTEL,
	DISPONIBILITE,
	NBR_CHAMBRE,
	VILLE,
	VAR_PRIX,
	COMMENTAIRE,
	COLUMNS
};



//Affichage de hébergements

void afficherPrestationHbr(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	char id[50];
	char categ[50];
	char hotel[50];
	char dispo[50];
	char nbrChamb[50];
	char ville[50];
	char varPrix[50];
	char com[50];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",IDENTIFIANT_HBR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" catégorie", renderer, "text",CATEGORIE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" hotel", renderer, "text",HOTEL, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Disponibilité", renderer, "text",DISPONIBILITE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Nombre de chambre", renderer, "text",NBR_CHAMBRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Ville", renderer, "text",VILLE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Variation des prix", renderer, "text",VAR_PRIX, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Commentaire", renderer, "text",COMMENTAIRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("hebergement.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("hebergement.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s",id,categ,hotel,dispo,nbrChamb,ville,varPrix,com)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter, IDENTIFIANT_HBR, id, CATEGORIE, categ, HOTEL, hotel, DISPONIBILITE,dispo,NBR_CHAMBRE,nbrChamb,VILLE,ville,VAR_PRIX,varPrix,COMMENTAIRE,com,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}
