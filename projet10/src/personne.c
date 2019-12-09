#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "personne.h"
#include <gtk/gtk.h>

enum   
{       
        CIN,
        NOM,
	PRENOM,
        DATE,
        ADRESSE,
	MAIL,
	PAYS,
	PASS,
        COLUMNS
};

void ajouter_personne(Personne p)
{

 FILE *f;
  f=fopen("utilisateur.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.date_naissance,p.adresse,p.mail,p.pays,p.pass);
  fclose(f);

}

}



void afficher_personne(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char prenom [30];
        char cin[30];
	char date[30];
	char adresse[30];
	char mail[30];
	char pays[30];
	char pass[30];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          	
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  pays", renderer, "text",PAYS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  pass", renderer, "text",PASS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("utilisateur.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("utilisateur.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n" , cin,nom,prenom,date,adresse,mail,pays,pass)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, CIN, cin, NOM, nom, PRENOM, prenom,DATE,date,ADRESSE,adresse,MAIL,mail,PAYS,pays,PASS,pass -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
void supprimer(char cinn[])
{
  FILE *f;
  FILE *f1;
	char cin[30];
	char nom [30];
	char prenom [30];
	char date_naissance[30];
	char adresse[30];
	char mail[30];
	char pays[30];
	char pass[30];
 

  f = fopen("utilisateur.txt","r");
  f1 = fopen("temp.txt","w+");

  
    while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,date_naissance,adresse,mail,pays,pass) != EOF)
    {
      if (strcmp(cin,cinn)!=0 )
       {
   
          fprintf(f1,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,date_naissance,adresse,mail,pays,pass);
	}
    }


  fclose(f);
  fclose(f1);
  remove("utilisateur.txt");
  rename("temp.txt","utilisateur.txt");
}

void modifier(Personne p)
{

Personne a ;
FILE *f;
FILE *ftemp;
ftemp=NULL;
f=fopen("utilisateur.txt","r");
ftemp=fopen("temp.txt","w");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s\n",a.cin,a.nom,a.prenom,a.date_naissance,a.adresse,a.mail,a.pays,a.pass)!=EOF)
 {

            if(strcmp(a.cin,p.cin)!=0)
            {
                fprintf(ftemp,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.adresse,p.mail,p.pays,p.pass);

            }
            else if (strcmp(p.cin,a.cin)==0)
           {
               fprintf(ftemp,"%s %s %s %s %s %s %s %s\n",a.cin,a.nom,a.prenom,a.date_naissance,a.adresse,a.mail,a.pays,a.pass);
            }

              
        


    }

    fclose(ftemp);
    fclose(f);

     remove("utilisateur.txt");
     rename("temp.txt","utilisateur.txt");
     
}

}
