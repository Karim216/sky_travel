#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "personne.h"


void
on_ajouter_clicked                     (GtkWidget       *objet,

                                        gpointer         user_data)
{



Personne p;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

input1=lookup_widget(objet,"cin");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"prenom");
input4=lookup_widget(objet,"date");
input5=lookup_widget(objet,"adresse");
input6=lookup_widget(objet,"mail");
input7=lookup_widget(objet,"pays");
input8=lookup_widget(objet,"pass");


strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.mail,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.pays,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(p.pass,gtk_entry_get_text(GTK_ENTRY(input8)));


ajouter_personne(p);


}




void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *fenetre_window1, *fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher");


gtk_widget_destroy(fenetre_afficher);
fenetre_window1=create_window1();
gtk_widget_show(fenetre_window1);


}


void
on_button5_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *window1, *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");


gtk_widget_destroy(fenetre_ajout);
window1=create_window1();
gtk_widget_show(window1);


}


void
on_button2_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *Modifie;

window1=lookup_widget(objet,"window1");


gtk_widget_destroy(window1);
Modifie=create_Modifie();
gtk_widget_show(Modifie);

}


void
on_button1_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *fenetre_ajout;

window1=lookup_widget(objet,"window1");


gtk_widget_destroy(window1);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);

}


void
on_button4_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

window1=lookup_widget(objet,"window1");


gtk_widget_destroy(window1);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);
      

treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_personne(treeview1);
}


void
on_button3_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *Sup;

window1=lookup_widget(objet,"window1");


gtk_widget_destroy(window1);
Sup=create_Sup();
gtk_widget_show(Sup);
}


void
on_supprimer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
		GtkWidget *input1;
		char cinn[30];
		GtkWidget *Sup;
		Sup=lookup_widget(objet,"Sup");
		input1 = lookup_widget(objet,"suppriner");
		strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(cinn);		
}


void
on_Modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{

}


void
on_Modif_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
		GtkWidget *input1;
		//GtkWidget *windowlogin;
		//GtkWidget *window11;
		char cin[30];
		char cinn[30];

		GtkWidget *Modifie;
		GtkWidget *window3;
		input1 = lookup_widget(objet,"Modifier");
		strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		FILE*f;
		f=fopen("utilisateur.txt","r");
		while((fscanf(f,"%s \n",cinn)!=EOF))
		if (strcmp(cin,cinn)==0)
		{
		Modifie=lookup_widget(objet,"Modifie");
		window3=lookup_widget(objet,"window3");
		window3=create_window3();
		gtk_widget_destroy(Modifie);
		gtk_widget_show(window3);
		}
}


void
on_button6_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)

{
GtkWidget *window1, *Sup;

Sup=lookup_widget(objet,"Sup");


gtk_widget_destroy(Sup);


window1=create_window1();
gtk_widget_show(window1);
}


void
on_button10_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *Modifie;

Modifie=lookup_widget(objet,"Modifie");


gtk_widget_destroy(Modifie);
window1=create_window1();
gtk_widget_show(window1);
}


void
on_Confirmer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
		GtkWidget *input1;
		char cinn[30];
		Personne p;
		GtkWidget *Sup;
		GtkWidget *window2;
		window2=lookup_widget(objet,"window2");
		Sup=lookup_widget(objet,"Sup");
		input1 = lookup_widget(objet,"suppriner");
		strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(cinn);
}
		


void
on_button11_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2, *Sup;

window2=lookup_widget(objet,"window2");


gtk_widget_destroy(window2);
Sup=create_Sup();
gtk_widget_show(Sup);
}


void
on_button8_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
Personne a;
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *window3;


window3=lookup_widget(objet,"window3");

input1=lookup_widget(objet,"cin1");
input2=lookup_widget(objet,"nom1");
input3=lookup_widget(objet,"prenom1");
input4=lookup_widget(objet,"adresse1");
input5=lookup_widget(objet,"pays1");
input6=lookup_widget(objet,"pass1");
input7=lookup_widget(objet,"entry2");
input8=lookup_widget(objet,"entry1");

strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(a.pays,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.pass,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.date_naissance,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(a.mail,gtk_entry_get_text(GTK_ENTRY(input8)));
modifier(a);
}


void
on_button9_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{


}

