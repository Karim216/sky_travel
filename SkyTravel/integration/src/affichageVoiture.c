#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichageVoiture.h"
#include <gtk/gtk.h>

enum
{
	IDENTIFIANT_VOIT,
	MARQUE_VOIT,
	TYPE_VOIT,
	KM_VOIT,
	VITESSE,
	DISPO,
	COMMENTAIRE,
	PRIX,
	COLUMNS
};



//Affichage de hébergements

void afficherPrestationVoiture(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;


	char id[50];
	char marq[50];
	char type[50];
	char km[50];
	char vitesse[50];
	char dispo[50];
	char com[50];
	char prix[50];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",IDENTIFIANT_VOIT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" marque", renderer, "text",MARQUE_VOIT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" type", renderer, "text",TYPE_VOIT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" kilométrage", renderer, "text",KM_VOIT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" vitesse", renderer, "text",VITESSE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("disponibilité", renderer, "text",DISPO, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" remaque", renderer, "text",COMMENTAIRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}

	

	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("voiture.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("voiture.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s",id,marq,type,km,vitesse,dispo,com,prix)!=EOF)
		{
			gtk_list_store_append (store,&iter);

			gtk_list_store_set (store, &iter, IDENTIFIANT_VOIT, id, MARQUE_VOIT, marq, TYPE_VOIT, type, KM_VOIT,km,VITESSE,vitesse,DISPO,dispo,COMMENTAIRE,com,PRIX,prix,-1);
		}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}
