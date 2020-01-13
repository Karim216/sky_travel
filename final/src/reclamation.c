#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include <gtk/gtk.h>


//ajouter reclammation

void reclamer(reclamation r)
{
FILE *f;
f=fopen("reclamation.txt","a+");
if(f!=NULL)
{
fprintf(f,"%d/%d/%d %s %s\n",r.dt.jour,r.dt.mois,r.dt.annee,r.objet,r.reclamation);
fclose(f);
}
} 
//afficher reclamation 
enum{
DATE,
OBJET,
RECLAMATION,
COLUMNS
};

void afficherreclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;
        char date[10];
        
	char objet[20];
	char reclamation[100];
        store=NULL;
FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();


 column  =gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" objet",renderer,"text",OBJET, NULL); 		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" reclamation", renderer, "text",RECLAMATION, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("reclamation.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
f = fopen("reclamation.txt", "a+");
		while(fscanf(f,"%s %s %s  ",date,objet,reclamation)!=EOF)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,DATE,date,OBJET,objet,RECLAMATION,reclamation,-1);
}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	
}

