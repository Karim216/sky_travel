#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "facture.h"
#include <gtk/gtk.h>
//Ajouter une facture

void ajouter_facture(facture f)
{

 FILE *fa;
  fa=fopen("facture.txt","a+");
  if(fa!=NULL) 
  {
  fprintf(fa,"%s %s %s %d/%d/%d %s %s %s %s %s\n",f.id,f.n,f.emis_par,f.fact.jour,f.fact.mois,f.fact.annee,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC);
  fclose(fa);

}

}

enum   
{       
        ID,
        N,
	EMIS_PAR,
        DATE,
        PRESTATION,
	ID_PREST,
        CODE_COUPAN,
        MONTANT_HT,
	MONTANT_TTC,
        COLUMNS
};
//Afficher une facture


void afficher_facture(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        char id [30];
        char n [30];
	char emis_par [30];
        char date [30];
        char prestation [30];
	char id_prest[30];
        char code_coupan [30];
        char montant_HT[30];
	char montant_TTC[30];
        store=NULL;
       FILE *f;
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" n° facture", renderer, "text",N, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  emis par", renderer, "text",EMIS_PAR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  prestation", renderer, "text",PRESTATION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  id prestation", renderer, "text",ID_PREST, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("   code coupan", renderer, "text",CODE_COUPAN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  montant HT", renderer, "text",MONTANT_HT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  montant TTC", renderer, "text",MONTANT_TTC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("facture.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("facture.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id,n,emis_par,date,prestation,id_prest,code_coupan,montant_HT,montant_TTC)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID, id, N, n, EMIS_PAR, emis_par, DATE, date, PRESTATION, prestation,ID_PREST,id_prest,  CODE_COUPAN, code_coupan, MONTANT_HT, montant_HT,MONTANT_TTC, montant_TTC,-1);
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


void supprimer_facture(char id[])
{

facture f;

FILE*fa;
FILE*ffact;

char date[50];
fa=fopen("facture.txt","r");
ffact=fopen("facture2.txt","w");

if (fa!=NULL)
{

while (fscanf(fa,"%s %s %s %s %s %s %s %s %s \n",f.id,f.n,f.emis_par,date,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC)!=EOF)
 {

            if(strcmp(f.id_prestation,id)!=0)
            {
                fprintf(ffact,"%s %s %s %s %s %s %s %s %s \n",f.id,f.n,f.emis_par,date,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC );
                
        }
        


    }

    fclose(ffact);
    fclose(fa);

     remove("facture.txt");
     rename("facture2.txt","facture.txt");
}}

void modifier_f(  char idd[], char montant[],char n[],char prest[],char agent[],char date1[] )
   {char date[30];
	facture f;
	FILE *fa;
	FILE *fmodif;
	fa=fopen("facture.txt","r");
	fmodif=fopen("modif.txt","a+");
	if (fa!=NULL)
	{
	while (fscanf(fa,"%s %s %s %s %s %s %s %s %s \n",f.id,f.n,f.emis_par,date,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC )!=EOF);
                
	{
		
		if(strcmp(idd,f.id)!=0)
		{
			fprintf(fmodif,"%s %s %s %s %s %s %s %s %s \n",f.id,f.n,f.emis_par,date,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC);
		}
		else
		{
			fprintf(fmodif,"%s %s %s %s %s %s %s %s %s\n",idd,n,agent,date1,prest,f.id_prestation,f.code_coupan,f.mantant_HT,montant);

		}
	}
	fclose(fmodif);
	fclose(fa);
	remove("facture.txt");
	rename("modif.txt","facture.txt");
	

	}}

/*void calculmontant(int montant1)
{
	return (atoi (montant1)*1.055);}
*/

