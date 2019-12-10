#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "facture.h"
#include "payement.h"


void on_buttonlogfac_clicked                (GtkWidget       *obj, gpointer         user_data) 
{

GtkWidget *window1;
GtkWidget *window2; 
GtkWidget *label;
GtkWidget *entry1; 
GtkWidget *entry2;
int a;
char username[50];
char password[50];
int role;
entry1=lookup_widget(obj,"entryuserfac");
entry2=lookup_widget(obj,"entrypassfac");

strcpy(username,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(entry2)));

label=lookup_widget(obj,"erreurauth");
a = verifier(username,password,role);
switch (a)
{
	case 3:
		window1=lookup_widget(obj,"windowauthfac");
        	window2=lookup_widget(obj,"windowespfac");
		
		window2=create_windowespfac();
		gtk_widget_destroy(window1);
		gtk_widget_show(window2);
		break;
	default:
		gtk_label_set_text(GTK_LABEL(label),"vérifier les entrées");
}
}



void
on_buttonajfac_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{GtkWidget *entry1;
GtkWidget  *entry2; 
GtkWidget  *entry3;
GtkWidget  *entry4; 
GtkWidget  *entry5;
GtkWidget  *entry6;
GtkWidget  *entry7;
//GtKWidget  *label1;

GtkWidget *combobox1;
GtkWidget  *spin1;
GtkWidget  *spin2;
GtkWidget  *spin3;

facture f;

Date fact;

entry1=lookup_widget(obj,"entryidaj");
entry2=lookup_widget(obj,"entryNfac");
entry3=lookup_widget(obj,"entryagentfac");
spin1=lookup_widget(obj,"spinbuttonaj_dt_fac");
spin2=lookup_widget(obj,"spinbuttonaj_fac_mois");
spin3=lookup_widget(obj,"spinbutton_aj_an_fac");
combobox1=lookup_widget(obj,"comboboxAjfac");
entry4=lookup_widget(obj,"entryIdprestationfact");
entry5=lookup_widget(obj,"entrycodecoupan");
entry6=lookup_widget(obj,"entryMantantHT");
entry7=lookup_widget(obj,"entryMantantTTC");

strcpy(f.id,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(f.n,gtk_entry_get_text(GTK_ENTRY(entry2)));
strcpy(f.emis_par,gtk_entry_get_text(GTK_ENTRY(entry3)));
strcpy(f.prestation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(f.id_prestation,gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(f.code_coupan,gtk_entry_get_text(GTK_ENTRY(entry5)));
strcpy(f.mantant_HT,gtk_entry_get_text(GTK_ENTRY(entry6)));
strcpy(f.mantant_TTC,gtk_entry_get_text(GTK_ENTRY(entry7)));
f.fact.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
f.fact.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
f.fact.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));




ajouter_facture(f);


}



void
on_buttonrefrefac_clicked              (GtkWidget      *obj,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *treeview;

	window1=lookup_widget(obj,"windowespfac");
	treeview=lookup_widget(window1,"treeviewfacturation");

	afficher_facture(treeview);
}






void
on_buttonsuppfac_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
	char id[50];

	GtkWidget *entry1;
	entry1=lookup_widget(obj,"entryIDsupfac");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry1)));

	supprimer_facture(id);
	

}




void
on_client_payement_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{ 
	GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(obj,"windowespfac");
        window2=lookup_widget(obj,"windowesppayement");
		
	window2=create_windowesppayement();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}




void
on_buttonpaye_clicked                  (GtkWidget      *obj,
                                        gpointer         user_data)
{
char codecarte[30];
GtkWidget *entry1;
GtkWidget  *entry2; 
GtkWidget  *entry3;
GtkWidget  *entry4; 
GtkWidget *entry5;

GtkWidget *combobox1;

payement p;

entry1=lookup_widget(obj,"entryIDpayement");
entry2=lookup_widget(obj,"entrynomclientayement");
entry3=lookup_widget(obj,"entrynomclientayement");
entry4=lookup_widget(obj,"entrynumerocarte");
entry5=lookup_widget(obj,"entrycodecarte");
combobox1=lookup_widget(obj,"comboboxpayer");

strcpy(p.id_,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(p.nom_,gtk_entry_get_text(GTK_ENTRY(entry2)));
strcpy(p.prenom_,gtk_entry_get_text(GTK_ENTRY(entry3)));
strcpy(p.type_payement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(p.num_carte,gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(codecarte,gtk_entry_get_text(GTK_ENTRY(entry5)));
 ajouter_payement(p);
}




void
on_buttonrecherchefacture_clicked      (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *entry1;
GtkWidget  *entry2; 
GtkWidget  *entry3;
GtkWidget  *entry4; 
GtkWidget *entry5;
GtkWidget *entry6;
GtkWidget *entry20;
FILE *fa;
char id1[50];
facture f;
char date[50];
fa=fopen("facture.txt","r");
entry20=lookup_widget(obj,"entryidmodif");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry20)));
if (fa!=NULL)
 {
    	while(fscanf(fa,"%s %s %s %s %s %s %s %s %s \n",f.id,f.n,f.emis_par,date,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC)!=EOF)
 {
			if(strcmp(id1,f.id)==0){

				entry1=lookup_widget(obj,"entryidmodif");
				entry2=lookup_widget(obj,"entryNtmodif");
				entry3=lookup_widget(obj,"entryemisparmodif");
				entry4=lookup_widget(obj,"entrydatemodif");
				entry5=lookup_widget(obj,"entryprestationmodif");
				entry6=lookup_widget(obj,"entrymntmod");
				gtk_entry_set_text(GTK_ENTRY(entry1),f.id);
				gtk_entry_set_text(GTK_ENTRY(entry2),f.n);
				gtk_entry_set_text(GTK_ENTRY(entry3),f.emis_par);
				gtk_entry_set_text(GTK_ENTRY(entry4),date);
				gtk_entry_set_text(GTK_ENTRY(entry5),f.prestation);
				gtk_entry_set_text(GTK_ENTRY(entry6),f.mantant_TTC);
			
			}
				
				
		}
	}
}




void
on_buttonespacepayement_espaceagent_clicked
                                        (GtkWidget      *obj,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(obj,"windowesppayement");
        window2=lookup_widget(obj,"windowespfac");
		
	window2=create_windowespfac();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}


void
on_buttonquitterfacture_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(obj,"windowespfac");
        window2=lookup_widget(obj,"windowauthfac");
		
	window2=create_windowauthfac();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);


}


void
on_buttonmodifier1facture_clicked      (GtkWidget     *obj,
                                        gpointer         user_data)

{
char idd[50];
	char nouvmontant[50];
	char n[50];
	char prest[50];
	char agent[50];
	char date1[50];

	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *entry3; 
	GtkWidget *entry4;
	GtkWidget *entry5;
	GtkWidget *entry6;
	entry1=lookup_widget(obj,"entryidmodif");
	strcpy(idd,gtk_entry_get_text(GTK_ENTRY(entry1)));
	entry2=lookup_widget(obj,"entryNtmodif");
	strcpy(n,gtk_entry_get_text(GTK_ENTRY(entry2)));
	entry3=lookup_widget(obj,"entryemisparmodif");
	strcpy(agent,gtk_entry_get_text(GTK_ENTRY(entry3)));
	entry4=lookup_widget(obj,"entrydatemodif");
	strcpy(date1,gtk_entry_get_text(GTK_ENTRY(entry4)));
	entry5=lookup_widget(obj,"entryprestationmodif");
	strcpy(prest,gtk_entry_get_text(GTK_ENTRY(entry5)));
	entry6=lookup_widget(obj,"entrymntmod");
	strcpy(nouvmontant,gtk_entry_get_text(GTK_ENTRY(entry6)));
	
	 modifier_f(idd,nouvmontant,n,prest,agent,date1);

}

