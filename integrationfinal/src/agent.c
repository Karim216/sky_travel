#include <stdio.h>
#include <string.h>
#include "agent.h"
#include <gtk/gtk.h>
#include <stdlib.h>


enum
{
		CIN,
		NOM,
		PRENOM,
		SEXE,
		//AGE,
		LOGIN,
		MOT_DE_PASSE,		
		COLUMNS
};


void ajouter_agent(agent agen)
{

	FILE *f;
	f=fopen("agents.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f,"%s %s %s %s %s %s \n",agen.cin, agen.nom, agen.prenom,agen.sex,agen.login,agen.mot_de_passe);
	 fclose(f);
	}
}

void afficher_agent(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char cin[30];
	char nom[30];
	char prenom[30];
	char sex[30];
	//char age[30];
	char login [30];
	char mot_de_passe[30];

	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("sex",renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("login",renderer, "text",LOGIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mot_de_passe",renderer, "text",MOT_DE_PASSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("agents.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("agents.txt","a+");
			while(fscanf(f,"%s %s %s %s %s  %s \n",cin,nom,prenom,sex,login,mot_de_passe)!=EOF)
			{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, CIN,cin, NOM, nom, PRENOM, prenom, SEXE, sex, LOGIN,login,MOT_DE_PASSE, mot_de_passe, -1);
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}}


void supprimer_agent(char cin[])
{

  FILE *f;
  FILE *ftemp;
	char cin1[30];
	char nom[30];
	char prenom[30];
	char sex[30];
	//char age;
	char login [30];
	char mot_de_passe[30];
  
 

  f = fopen("agents.txt","r");
  ftemp = fopen("agentstemp.txt","w+");

  
    while(fscanf(f,"%s %s %s %s %s %s\n",cin1,nom,prenom,sex,login,mot_de_passe) != EOF)
    {
      if (strcmp(cin1,cin)!=0 )
       
   
          fprintf(ftemp,"%s %s %s %s %s %s\n",cin1,nom,prenom,sex,login,mot_de_passe);
    }


  fclose(f);
  fclose(ftemp);
  remove("agents.txt");
  rename("agentstemp.txt","agents.txt");

}

agent rechercher_agent (char cin[30])
{
   FILE *f;

   agent agen;
    

    f=fopen("agents.txt","r");
    if(f!=NULL)
    {
    while((fscanf(f,"%s %s %s %s %s %s \n",agen.cin, agen.nom,agen.prenom,agen.sex,agen.login,agen.mot_de_passe)!=EOF))
    {
        if((strcmp(agen.cin,cin)==0))
        {
	return agen;
        fclose(f);
	}
    }
	
    fclose (f);}
    return agen;
}


void modifier_agent(agent agen)
{ 
    FILE *f;
    FILE *ftemp;
    agent agen1;
    f=fopen("agents.txt","r");
    ftemp=fopen("agentstemp.txt","a+");

    
    if(f!=NULL)
    { if(ftemp!=NULL)
    { 
        while(fscanf(f,"%s %s %s %s %s %s \n",agen1.cin,agen1.nom,agen1.prenom,agen1.sex,agen1.login,agen1.mot_de_passe)!=EOF)
        {
            if(strcmp(agen.cin,agen1.cin)!=0)
            {
                fprintf(ftemp,"%s %s %s %s %s %s \n",agen1.cin,agen1.nom,agen1.prenom,agen1.sex,agen1.login,agen1.mot_de_passe);	

            }
            else
            { 
                fprintf(ftemp,"%s %s %s %s %s %s \n",agen.cin,agen.nom,agen.prenom,agen.sex,agen.login,agen.mot_de_passe);
            }
        }
        fclose(f);
        fclose(ftemp);
	remove("agents.txt");
	rename("agentstemp.txt","agents.txt");

    }
    }

}


