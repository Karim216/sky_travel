#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifAuthentif.h"
#include "ajouter_prest_vol.h"
#include "afficherPrest.h"
#include "affichageHbr.h"
#include "affichageVoiture.h"
#include "afficherOffres.h"
#include "supprPrest.h"
#include "modifier_prest_vol.h"
#include "agent.h"
#include "facture.h"
#include "payement.h"

GtkWidget *windowclose;
GtkWidget *windowopen;
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *window4;
GtkWidget *window5;
GtkWidget *window6;
GtkWidget *window7;
GtkWidget *window8;
GtkWidget *window9;
GtkWidget *window10; 


GtkWidget *entry1;
GtkWidget *entry2;
GtkWidget *entry3;
GtkWidget *entry4;
GtkWidget *entry5;
GtkWidget *entry6;
GtkWidget *entry7;
GtkWidget *entry8;
GtkWidget *entry9;
GtkWidget *entry10;
GtkWidget *entry11;
GtkWidget *entry12;
GtkWidget *entry13;

GtkWidget *combobox1;
GtkWidget *combobox2;

GtkWidget *comboboxentry1;
GtkWidget *comboboxentry2;
GtkWidget *comboboxentry3;

GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;
GtkWidget *spinbutton4;
GtkWidget *spinbutton5;
GtkWidget *spinbutton6;
GtkWidget *spinbutton7;
GtkWidget *spinbutton8;
GtkWidget *spinbutton9;
GtkWidget *spinbutton10;

GtkWidget *treeview1;
GtkWidget *treeview2;
GtkWidget *treeview3;

GtkWidget *notebook1;
GtkWidget *notebook2;

GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;
GtkWidget *label5;
GtkWidget *label6;
GtkWidget *label7;
GtkWidget *label8;

GtkWidget *image1;
GtkWidget *image2;
GtkWidget *image3;
GtkWidget *image4;
GtkWidget *image5;
GtkWidget *image6;

GtkWidget *table1;
GtkWidget *table2;
GtkWidget *table3;
GtkWidget *table4;
GtkWidget *table5;
GtkWidget *table6;



//lien espace_accueil espace_authentification
void on_buttonConnectAgent_clicked (GtkWidget *obj, gpointer user_data)
{

	windowclose = lookup_widget(obj,"windowAccueil");
	gtk_widget_destroy(windowclose);

	windowopen = lookup_widget(obj,"windowAuthenti");
	windowopen = create_windowAuthenti();

	table1=gtk_table_new(0,0,TRUE);
	gtk_container_add(GTK_CONTAINER(windowopen),GTK_WIDGET(table1));
	image1=create_pixmap(windowopen,"./auth3.jpg");
	image1=gtk_image_new_from_file("./auth3.jpg");
	gtk_table_attach_defaults(GTK_TABLE(table1),image1,0,0,0,0);

	
	gtk_widget_show_all(windowopen);

}

//lien espace_authentification espace_accueil (quitter la fenêtre d'authentification)
void on_buttonQuitAuthentif_clicked (GtkWidget *obj, gpointer user_data)
{
	windowclose = lookup_widget(obj,"windowAuthenti");
	windowopen = lookup_widget(obj,"windowAccueil");

	windowopen = create_windowAccueil();
	gtk_widget_destroy(windowclose);
	gtk_widget_show(windowopen);
}

//authentification pour la connexion à la fenêtre espace utilisateur
void on_buttonAuthentification_clicked (GtkWidget *obj, gpointer user_data)
{

	GtkWidget *entryNom;
	GtkWidget *entryPass;
	GtkWidget *labelErreur;

	char user[50];
	char password[50];
	int role;

	entryNom = lookup_widget(obj,"entryUserAuthentif");
	entryPass = lookup_widget(obj,"entryPassAuthentif");
	labelErreur = lookup_widget(obj,"label195");

	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entryNom)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(entryPass)));

	role = verifAuthentification(user,password);

	switch (role){
	case 1:
		window2 = lookup_widget(obj,"windowAuthenti");
		window1 = lookup_widget(obj,"window1");

		window1 = create_window1();
		gtk_widget_destroy(window2);


		gtk_widget_show(window1);
		break;
	case 2:
		windowclose = lookup_widget(obj,"windowAuthenti");
		windowopen = lookup_widget(obj,"windowPrestataire");

		windowopen = create_windowPrestataire();
		gtk_widget_destroy(windowclose);

		table1=gtk_table_new(0,0,TRUE);
		gtk_container_add(GTK_CONTAINER(windowopen),GTK_WIDGET(table1));
		image1=create_pixmap(windowopen,"./okay.jpg");
		image1=gtk_image_new_from_file("./okay.jpg");
		gtk_table_attach_defaults(GTK_TABLE(table1),image1,0,0,0,0);

		table2=gtk_table_new(0,0,TRUE);
		gtk_container_add(GTK_CONTAINER(windowopen),GTK_WIDGET(table2));
		image2=create_pixmap(windowopen,"./voyage3.jpg");
		image2=gtk_image_new_from_file("./voyage3.jpg");
		gtk_table_attach_defaults(GTK_TABLE(table2),image2,0,0,0,0);


		gtk_widget_show_all(windowopen);
		break;
	case 3:
		window2 = lookup_widget(obj,"windowAuthenti");
		window7 = lookup_widget(obj,"window7");

		window7 = create_window7();
		gtk_widget_destroy(window2);


		gtk_widget_show(window7);
		break;
	/*
	.
	.
	.
	case n:
		...*/
	default: 
		gtk_label_set_text(GTK_LABEL(labelErreur),"mot de passe ou nom d'utilisateur incorect");
	}

	
}

//déconnexion prestataire de servive
void on_buttonDeconnPrestataire_clicked (GtkWidget *obj, gpointer user_data)
{
	windowclose = lookup_widget(obj,"windowPrestataire");
	windowopen = lookup_widget(obj,"windowAccueil");

	windowopen = create_windowAccueil();
	gtk_widget_destroy(windowclose);
	gtk_widget_show(windowopen);
}




void on_buttonConsultPrestOffre_clicked (GtkWidget *obj, gpointer user_data)
{

	FILE *f;
	f=fopen("tmp","w");

	if(f!=NULL){
		fprintf(f,"1");
		fclose(f);
	}	
		
	windowclose = lookup_widget(obj,"windowPrestataire");
	windowopen = lookup_widget(obj,"windowPrestEtOffre");

	windowopen = create_windowPrestEtOffre();
	gtk_widget_destroy(windowclose);
	gtk_widget_show_all(windowopen);
}

//ajout de vol
void
on_buttonAjouterVol_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
	Date dt_vol;

	Ajouter a;
	

	//récupération des widgets
	entry1=lookup_widget(obj,"entryIdAjoutVol");
	entry2=lookup_widget(obj,"entryComAjouVol");
	entry3=lookup_widget(obj,"entryAvAjouVol");
	entry4=lookup_widget(obj,"entryVilleAjouVol");
	entry5=lookup_widget(obj,"entryAvilleAjouVol");
	entry6=lookup_widget(obj,"entryPrixPrClassAjouVol");
	entry7=lookup_widget(obj,"entryPrixEconAjouVol");

	combobox1=lookup_widget(obj,"comboboxClassAJouVol");

	spinbutton1=lookup_widget(obj,"spinbuttonJourAjouVol");
	spinbutton2=lookup_widget(obj,"spinbuttonMoisAjouVol");
	spinbutton3=lookup_widget(obj,"spinbuttonAnnAjouVol");
	spinbutton4=lookup_widget(obj,"spinbuttonHrAjouVol");
	spinbutton5=lookup_widget(obj,"spinbuttonMinAjouVol");
	spinbutton6=lookup_widget(obj,"spinbuttonAjourAjouVol");
	spinbutton7=lookup_widget(obj,"spinbuttonAmoisAjouVol");
	spinbutton8=lookup_widget(obj,"spinbuttonAannAjouVol");
	spinbutton9=lookup_widget(obj,"spinbuttonAhrAjouVol");
	spinbutton10=lookup_widget(obj,"spinbuttonAminAjouVol");

	//comboboxentry1=lookup_widget(obj,"comboboxentryMoiAjouVol");
	//comboboxentry1=lookup_widget(obj,"comboboxentryAmoiAjouVol");

	
	//affectation aux variables de la fonction ajouter
	strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(a.comp,gtk_entry_get_text(GTK_ENTRY(entry2)));
	strcpy(a.avion,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(a.dpt_ville,gtk_entry_get_text(GTK_ENTRY(entry4)));
	strcpy(a.arr_ville,gtk_entry_get_text(GTK_ENTRY(entry5)));
	strcpy(a.pr_class,gtk_entry_get_text(GTK_ENTRY(entry6)));
	strcpy(a.econ,gtk_entry_get_text(GTK_ENTRY(entry7)));
	
	strcpy(a.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));


	a.dt_vol.jour_dpt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
	a.dt_vol.mois_dpt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));
	a.dt_vol.annee_dpt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));
	a.dt_vol.heure_dpt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton4));
	a.dt_vol.minute_dpt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton5));
	a.dt_vol.jour_arr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton6));
	a.dt_vol.mois_arr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton7));
	a.dt_vol.annee_arr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton8));
	a.dt_vol.heure_arr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton9));
	a.dt_vol.minute_arr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton10));

	
	label1=lookup_widget(obj,"label221");
	if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry1)),"")==0){

		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vide");
	}

	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry2)),"")==0){
		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vides");	
	}
	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry3)),"")==0){
		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vides");
	}
	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry4)),"")==0){
		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vides");
	}
	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry5)),"")==0){
		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vides");
	}
	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry6)),"")==0){
		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vides");
	}
	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(entry7)),"")==0){
		gtk_label_set_text(GTK_LABEL(label1),"vos entrées contiennent des champs vides");
	}
	else{
		gtk_label_set_text(GTK_LABEL(label1),"ajouter avec succès");
		ajouterPrestVol(a);
	}
	//ajouterPrestVol(a);
	//strcpy(a.moi_dpt,gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_ENTRY(comboboxentry1)));
	//strcpy(a.moi_arr,gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_ENTRY(comboboxentry2)));
	
	
	
}


void
on_buttonConsultPrestClient_clicked    (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


//Affichage de tous les prestations
/*void
on_buttonAffPrestations_clicked        (GtkWidget       *obj,
                                       gpointer         user_data)
{
		char hbr[20]="Hébergements";
		char vol[20]="Vols";
		char combo[20];

		
	
		
		
		//window1 = lookup_widget(obj,"windowPrestEtOffre");
		//notebook1 = lookup_widget(window1,"notebookAffPrestOffre");
		
		label1=lookup_widget(obj,"labelErrAffPrestation");
		combobox1=lookup_widget(obj,"comboboxPrestations");	

		strcpy(combo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));	
		
		if(strcmp(vol,combo)==0){
			window1 = lookup_widget(obj,"windowPrestEtOffre");
			notebook1 = lookup_widget(window1,"notebookAffPrestOffre");
			treeview1=lookup_widget(notebook1,"treeviewAffPrestations");
		
			afficherPrestations(treeview1);
		}
		else if(strcmp(hbr,combo)==0){

				window1 = lookup_widget(obj,"windowPrestEtOffre");
				notebook1 = lookup_widget(window1,"notebookAffPrestOffre");
				treeview2=lookup_widget(notebook1,"treeviewAffPrestations");
		
				afficherPrestationHbr(treeview2);
						
		}
		/*else if(strcmp("Excursions",gtk_combo_box_get_entry_text_column(comboboxentry1))==0)
							...
		else if(strcmp("Hébergements",gtk_combo_box_entry_get_text_column(comboboxentry1))==0)
							...
		else gtk_label_set_text(GTK_LABEL(label1),"veuillez délectionner une prestation valide");

}*/


//supprimer prestation de vols
void
on_buttonSupprPrestVol_clicked (GtkWidget *obj, gpointer user_data)
{

		char identifiant[30];

		entry1=lookup_widget(obj,"entryIdSupprVol");
		strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(entry1)));
		
		supprimPrest(identifiant);
}


//modification de prestation de vol
void
on_buttonVerifModifPrestVol_clicked (GtkWidget *obj, gpointer user_data)
{

	

	FILE *f;
	char id[50];
	char comp[50];
	char avion[50];
	char classe[50];
	char dpt_ville[50];
	char arr_ville[50];
	char pr_class[50];
	char econ[50];
	char date_dpt[50];
	char heure_dpt[50];
	char date_arr[50];
	char heure_arr[50];

	char id1[50];

	f=fopen("prestVol.txt","r");

	entry13=lookup_widget(obj,"entryIdModifVol");

	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry13)));

	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",id,comp,avion,classe,dpt_ville,date_dpt,heure_dpt,
									arr_ville,date_arr,heure_arr,pr_class,econ)!=EOF){
			if(strcmp(id1,id)==0){

				entry1=lookup_widget(obj,"entryIdModifVol");
				entry2=lookup_widget(obj,"entryComModifVol");
				entry3=lookup_widget(obj,"entryAvionModifVol");
				entry4=lookup_widget(obj,"entryClasseModifPrestVol");
				entry5=lookup_widget(obj,"entryVilleModifVol");
				entry6=lookup_widget(obj,"entryDateModifPrestVol");
				entry7=lookup_widget(obj,"entryHeureModifPrestVol");
				entry8=lookup_widget(obj,"entryAvilleModifVol");
				entry9=lookup_widget(obj,"entryAdateModifPrestVol");
				entry10=lookup_widget(obj,"entryAheureModifPrestVol");
				entry11=lookup_widget(obj,"entryPrixPrModifVol");
				entry12=lookup_widget(obj,"entryPrixEconModifVol");

				
				gtk_entry_set_text(GTK_ENTRY(entry1),id);
				gtk_entry_set_text(GTK_ENTRY(entry2),comp);
				gtk_entry_set_text(GTK_ENTRY(entry3),avion);
				gtk_entry_set_text(GTK_ENTRY(entry4),classe);
				gtk_entry_set_text(GTK_ENTRY(entry5),dpt_ville);
				gtk_entry_set_text(GTK_ENTRY(entry6),date_dpt);
				gtk_entry_set_text(GTK_ENTRY(entry7),heure_dpt);
				gtk_entry_set_text(GTK_ENTRY(entry8),arr_ville);
				gtk_entry_set_text(GTK_ENTRY(entry9),date_arr);
				gtk_entry_set_text(GTK_ENTRY(entry10),heure_arr);
				gtk_entry_set_text(GTK_ENTRY(entry11),pr_class);
				gtk_entry_set_text(GTK_ENTRY(entry12),econ);
			}
				
				
		}
	}
}



//modification de prestation de vol
void
on_buttonModifierPerstVol_clicked (GtkWidget *obj, gpointer user_data)
{
	char id1[50];
	char comp1[50];
	char avion1[50];
	char classe1[50];
	char dpt_ville1[50];
	char arr_ville1[50];
	char pr_class1[50];
	char econ1[50];
	char date_dpt1[50];
	char heure_dpt1[50];
	char date_arr1[50];
	char heure_arr1[50];
	
	entry1=lookup_widget(obj,"entryIdModifVol");
		strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry1)));

	entry2=lookup_widget(obj,"entryComModifVol");
		strcpy(comp1,gtk_entry_get_text(GTK_ENTRY(entry2)));

	entry3=lookup_widget(obj,"entryAvionModifVol");
		strcpy(avion1,gtk_entry_get_text(GTK_ENTRY(entry3)));

	entry4=lookup_widget(obj,"entryClasseModifPrestVol");
		strcpy(classe1,gtk_entry_get_text(GTK_ENTRY(entry4)));

	entry5=lookup_widget(obj,"entryVilleModifVol");
		strcpy(dpt_ville1,gtk_entry_get_text(GTK_ENTRY(entry5)));

	entry6=lookup_widget(obj,"entryDateModifPrestVol");
		strcpy(date_dpt1,gtk_entry_get_text(GTK_ENTRY(entry6)));

	entry7=lookup_widget(obj,"entryHeureModifPrestVol");
		strcpy(heure_dpt1,gtk_entry_get_text(GTK_ENTRY(entry7)));

	entry8=lookup_widget(obj,"entryAvilleModifVol");
		strcpy(arr_ville1,gtk_entry_get_text(GTK_ENTRY(entry8)));

	entry9=lookup_widget(obj,"entryAdateModifPrestVol");
		strcpy(date_arr1,gtk_entry_get_text(GTK_ENTRY(entry9)));

	entry10=lookup_widget(obj,"entryAheureModifPrestVol");
		strcpy(heure_arr1,gtk_entry_get_text(GTK_ENTRY(entry10)));

	entry11=lookup_widget(obj,"entryPrixPrModifVol");
		strcpy(pr_class1,gtk_entry_get_text(GTK_ENTRY(entry11)));

	entry12=lookup_widget(obj,"entryPrixEconModifVol");
		strcpy(econ1,gtk_entry_get_text(GTK_ENTRY(entry12)));

	modifierPrestVol(id1,comp1,avion1,classe1,dpt_ville1,date_dpt1,
			heure_dpt1,arr_ville1,date_arr1,heure_arr1,pr_class1,econ1);

}

//ferméture de la page du catalogue des prestations et offres 
void
on_buttonRetourPrestEtOffre_clicked    (GtkWidget       *obj,
                                        gpointer         user_data)
{
		FILE *f;
		char test[5];
		f=fopen("tmp","r");
		if(f!=NULL){
			while(fscanf(f,"%s\n",test)!=EOF){
			
				if (strcmp(test,"0")==0){
					window3=lookup_widget(obj,"windowPrestEtOffre");
					window4=lookup_widget(obj,"windowAccueil");

					window4=create_windowAccueil();
					gtk_widget_destroy(window3);
					gtk_widget_show(window4);

				}
				else{

					window1=lookup_widget(obj,"windowPrestEtOffre");
					window2=lookup_widget(obj,"windowPrestataire");

					window2=create_windowPrestataire();
					gtk_widget_destroy(window1);
					gtk_widget_show(window2);

				}
			}
			fclose(f);
		}

}


//ajout d'une prestation pour les hébergements
void
on_buttonAjoutHebergement_clicked      (GtkWidget       *obj,
                                        gpointer         user_data)
{
	AjouterHbr h;

	entry1=lookup_widget(obj,"entryIdAjoutHbr");
	entry2=lookup_widget(obj,"entryHotelAjoutHbr");
	entry3=lookup_widget(obj,"entryChambAjoutHbr");
	entry4=lookup_widget(obj,"entryVilleAjoutHbr");
	entry5=lookup_widget(obj,"entryPrixAjoutHbr");
	entry6=lookup_widget(obj,"entryComAjoutHbr");

	combobox1=lookup_widget(obj,"comboboxCategAjoutHbr");
	combobox2=lookup_widget(obj,"comboboxDispoAjoutHbr");
	
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(h.hotel,gtk_entry_get_text(GTK_ENTRY(entry2)));
	strcpy(h.nbrChamb,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(h.ville,gtk_entry_get_text(GTK_ENTRY(entry4)));
	strcpy(h.varPrix,gtk_entry_get_text(GTK_ENTRY(entry5)));
	strcpy(h.com,gtk_entry_get_text(GTK_ENTRY(entry6)));

	strcpy(h.categ,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	strcpy(h.dispo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

	ajouterPrestHbr(h);
}



//affichage de tout les offres
void
on_buttonPagePrestOffre_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{	

				window1 = lookup_widget(obj,"windowPrestEtOffre");

				notebook1=lookup_widget(window1,"notebookAffPrestOffre");
				treeview1=lookup_widget(window1,"treeviewOffres");

				afficherPrestationOffre(treeview1);
}


void
on_buttonRetourAccPrest_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{
			windowclose=lookup_widget(obj,"windowPrestationsEToffres");
			windowopen=lookup_widget(obj,"windowPrestEtOffre");

			windowopen=create_windowPrestEtOffre();
			gtk_widget_destroy(windowclose);
			gtk_widget_show(windowopen);

}


void
on_buttonActuaOffresEtPrest_clicked    (GtkWidget       *obj,
                                       gpointer         user_data)
{

		

}


//Suppréssion d'une prestation de l'hébergement
void
on_buttonValideSupprHbr_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{
		char identifiant[30];
		//int x;

		entry1=lookup_widget(obj,"entryIdSupprHbr");
		strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(entry1)));

		//label1=lookup_widget(obj,"label1SupprHbr");
		
		supprimHbr(identifiant);

		/*if(x==1)	gtk_label_set_text(GTK_LABEL(label1),"supprimé avec succès");
		else	gtk_label_set_text(GTK_LABEL(label1),"non existant");*/
		

		
}


//véfification d'une prestation de l'hébergement
void
on_buttonVerifierIdModifHbr_clicked    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	FILE *f;
	char id[50];
	char categ[50];
	char hotel[50];
	char dispo[50];
	char chamb[50];
	char ville[50];
	char prix[50];
	char com[50];

	char id1[50];

	f=fopen("hebergement.txt","r");

	entry10=lookup_widget(obj,"entryIdModifHbr");

	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry10)));

	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,categ,hotel,dispo,chamb,ville,prix,com)!=EOF){
			if(strcmp(id1,id)==0){

				entry1=lookup_widget(obj,"entryIdModifHbr");
				entry2=lookup_widget(obj,"entryCategModifHbr");
				entry3=lookup_widget(obj,"entryHotelModifHbr");
				entry4=lookup_widget(obj,"entryDispoModifHbr");
				entry5=lookup_widget(obj,"entryChamModifHbr");
				entry6=lookup_widget(obj,"entryVilleModifHbr");
				entry7=lookup_widget(obj,"entryPrixModifHbr");
				entry8=lookup_widget(obj,"entryComModifHbr");

				
				gtk_entry_set_text(GTK_ENTRY(entry1),id);
				gtk_entry_set_text(GTK_ENTRY(entry2),categ);
				gtk_entry_set_text(GTK_ENTRY(entry3),hotel);
				gtk_entry_set_text(GTK_ENTRY(entry4),dispo);
				gtk_entry_set_text(GTK_ENTRY(entry5),chamb);
				gtk_entry_set_text(GTK_ENTRY(entry6),ville);
				gtk_entry_set_text(GTK_ENTRY(entry7),prix);
				gtk_entry_set_text(GTK_ENTRY(entry8),com);
			}
				
				
		}
	}
}

//Modification d'une prestation de l'hébergement
void
on_buttonModifHbr_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
	char id1[50];
	char categ1[50];
	char hotel1[50];
	char dispo1[50];
	char chamb1[50];
	char ville1[50];
	char prix1[50];
	char com1[50];

	
	entry1=lookup_widget(obj,"entryIdModifHbr");
		strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry1)));

	entry2=lookup_widget(obj,"entryCategModifHbr");
		strcpy(categ1,gtk_entry_get_text(GTK_ENTRY(entry2)));

	entry3=lookup_widget(obj,"entryHotelModifHbr");
		strcpy(hotel1,gtk_entry_get_text(GTK_ENTRY(entry3)));

	entry4=lookup_widget(obj,"entryDispoModifHbr");
		strcpy(dispo1,gtk_entry_get_text(GTK_ENTRY(entry4)));

	entry5=lookup_widget(obj,"entryChamModifHbr");
		strcpy(chamb1,gtk_entry_get_text(GTK_ENTRY(entry5)));

	entry6=lookup_widget(obj,"entryVilleModifHbr");
		strcpy(ville1,gtk_entry_get_text(GTK_ENTRY(entry6)));

	entry7=lookup_widget(obj,"entryPrixModifHbr");
		strcpy(prix1,gtk_entry_get_text(GTK_ENTRY(entry7)));

	entry8=lookup_widget(obj,"entryComModifHbr");
		strcpy(com1,gtk_entry_get_text(GTK_ENTRY(entry8)));



	modifierPrestHbr(id1,categ1,hotel1,dispo1,chamb1,ville1,prix1,com1);	
}

//affichage des prestations dans le treeview 
void
on_buttonAfficherPrestations_clicked   (GtkWidget       *obj,
                                        gpointer         user_data)
{
}


void
on_buttonRafraichirPrestations_clicked (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window1 = lookup_widget(obj,"windowPrestEtOffre");
	window2 = lookup_widget(obj,"windowPrestEtOffre");
	
	gtk_widget_destroy(window2);
	window1=create_windowPrestEtOffre();
	gtk_widget_show(window1);
}

//ajout d'une prestation pour location
void
on_buttonAjoutVoiturePrest_clicked     (GtkWidget       *obj,
                                        gpointer         user_data)
{
	AjouterPrestVoit v;

	entry1=lookup_widget(obj,"entryIdVoiture");
	entry2=lookup_widget(obj,"entryMarqueVoiture");
	entry3=lookup_widget(obj,"entryKmVoiture");
	entry4=lookup_widget(obj,"entryComVoitute");
	entry5=lookup_widget(obj,"entryPrixVoiture");

	comboboxentry1=lookup_widget(obj,"comboboxentryVitesseVoiture");
	comboboxentry2=lookup_widget(obj,"comboboxentryDispoVoiture");
	comboboxentry3=lookup_widget(obj,"comboboxentryTypeVoiture");
	
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(v.marq,gtk_entry_get_text(GTK_ENTRY(entry2)));
	strcpy(v.km,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(v.com,gtk_entry_get_text(GTK_ENTRY(entry4)));
	strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(entry5)));

	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3)));
	strcpy(v.vitesse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
	strcpy(v.dispo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));

	ajouterPrestVoit(v);
}



//affichage des prestations dans le treeview
void
on_consulterPrestations_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{
		char prest[50];

		comboboxentry1=lookup_widget(obj,"comboboxentry2");

		strcpy(prest,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));

		if(strcmp("Vols",prest)==0){

				window2 = lookup_widget(obj,"windowPrestEtOffre");
				//gtk_widget_destroy(window2);

				window1 = lookup_widget(obj,"windowCatamogue");
				window1=create_windowCatamogue();
				
				gtk_widget_show(window1);

				treeview1=lookup_widget(window1,"treeview12Prestation2");
				afficherPrestations(treeview1);
					
		}
		else if(strcmp("Hébergements",prest)==0) {
				window2 = lookup_widget(obj,"windowPrestEtOffre");
				//gtk_widget_destroy(window2);

				window1 = lookup_widget(obj,"windowCatamogue");
				window1=create_windowCatamogue();
				
				gtk_widget_show(window1);

				treeview2=lookup_widget(window1,"treeview12Prestation2");

				afficherPrestationHbr(treeview2);
		}
		else /*if(strcmp("Location_voiture",prest)==0)*/ {
				window2 = lookup_widget(obj,"windowPrestEtOffre");
				//gtk_widget_destroy(window2);

				window1 = lookup_widget(obj,"windowCatamogue");
				window1=create_windowCatamogue();
				
				gtk_widget_show(window1);

				treeview3=lookup_widget(window1,"treeview12Prestation2");

				afficherPrestationVoiture(treeview3);
		}

		/*else if(strcmp("Hébergements",gtk_combo_box_entry_get_text_column(comboboxentry1))==0)
							...
				else gtk_widget_destroy(window1);*/
}


void
on_button1_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
	FILE *f;
	char id[50];
	char marq[50];
	char type[50];
	char km[50];
	char vitesse[50];
	char dispo[50];
	char com[50];
	char prix[50];

	char id1[50];

	f=fopen("voiture.txt","r");

	entry1=lookup_widget(obj,"entryIdModifVoi");

	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry1)));

	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,marq,type,km,vitesse,dispo,com,prix)!=EOF){
			if(strcmp(id1,id)==0){

				entry9=lookup_widget(obj,"entryIdModifVoi");
				entry8=lookup_widget(obj,"entryMarqModifVoi");
				entry2=lookup_widget(obj,"entryTypeModifVoi");
				entry3=lookup_widget(obj,"entryKmModifVoi");
				entry4=lookup_widget(obj,"entryVitesseModifVoi");
				entry5=lookup_widget(obj,"entryDispoModifVoi");
				entry6=lookup_widget(obj,"entryComModifVoi");
				entry7=lookup_widget(obj,"entryPrixModifVoi");


				gtk_entry_set_text(GTK_ENTRY(entry9),id);
				gtk_entry_set_text(GTK_ENTRY(entry8),marq);
				gtk_entry_set_text(GTK_ENTRY(entry2),type);
				gtk_entry_set_text(GTK_ENTRY(entry3),km);
				gtk_entry_set_text(GTK_ENTRY(entry4),vitesse);
				gtk_entry_set_text(GTK_ENTRY(entry5),dispo);
				gtk_entry_set_text(GTK_ENTRY(entry6),com);
				gtk_entry_set_text(GTK_ENTRY(entry7),prix);
			}
				
				
		}
	}
}

//Modifer une prestation de location de voiture
void
on_buttonModifVoiturePrest_clicked     (GtkWidget       *obj,
                                        gpointer         user_data)
{
	char id1[50];
	char marq1[50];
	char type1[50];
	char km1[50];
	char vitesse1[50];
	char dispo1[50];
	char com1[50];
	char prix1[50];

	
	entry1=lookup_widget(obj,"entryIdModifVoi");
		strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry1)));

	entry2=lookup_widget(obj,"entryMarqModifVoi");
		strcpy(marq1,gtk_entry_get_text(GTK_ENTRY(entry2)));

	entry3=lookup_widget(obj,"entryTypeModifVoi");
		strcpy(type1,gtk_entry_get_text(GTK_ENTRY(entry3)));

	entry4=lookup_widget(obj,"entryKmModifVoi");
		strcpy(km1,gtk_entry_get_text(GTK_ENTRY(entry4)));

	entry5=lookup_widget(obj,"entryVitesseModifVoi");
		strcpy(vitesse1,gtk_entry_get_text(GTK_ENTRY(entry5)));

	entry6=lookup_widget(obj,"entryDispoModifVoi");
		strcpy(dispo1,gtk_entry_get_text(GTK_ENTRY(entry6)));

	entry7=lookup_widget(obj,"entryComModifVoi");
		strcpy(com1,gtk_entry_get_text(GTK_ENTRY(entry7)));

	entry8=lookup_widget(obj,"entryPrixModifVoi");
		strcpy(prix1,gtk_entry_get_text(GTK_ENTRY(entry8)));



	modifierVoiture(id1,marq1,type1,km1,vitesse1,dispo1,com1,prix1);
}



//Supprimer une prestation de location de voiture
void
on_buttonSupprVoiturePrest_clicked     (GtkWidget       *obj,
                                        gpointer         user_data)
{
		char identifiant[30];
		//int x;

		entry1=lookup_widget(obj,"entryIdSupprVoiture");
		strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(entry1)));

		//label1=lookup_widget(obj,"label1SupprHbr");
		
		supprimVoiture(identifiant);
}



//Ajouter les offres
void
on_button5_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
	Date_of of;

	Offre o;
	

	//récupération des widgets
	entry1=lookup_widget(obj,"entry17");
	entry2=lookup_widget(obj,"entry18");
	entry3=lookup_widget(obj,"entry19");
	entry4=lookup_widget(obj,"entry20");
	entry5=lookup_widget(obj,"entry21");

	spinbutton1=lookup_widget(obj,"spinbutton9l");
	spinbutton2=lookup_widget(obj,"spinbutton10");
	spinbutton3=lookup_widget(obj,"spinbutton11");

	
	//affectation aux variables de la fonction ajouter
	strcpy(o.num,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(o.offre,gtk_entry_get_text(GTK_ENTRY(entry2)));
	strcpy(o.ville,gtk_entry_get_text(GTK_ENTRY(entry5)));
	strcpy(o.carac,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(entry4)));

	o.of.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
	o.of.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));
	o.of.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));

	
	ajouterOffre(o);


	//offres spécial
	
	special s;

	entry5=lookup_widget(obj,"entry29");
	entry6=lookup_widget(obj,"entry30");
	entry7=lookup_widget(obj,"entry31");
	entry8=lookup_widget(obj,"entry32");
	entry9=lookup_widget(obj,"entry33");
	entry10=lookup_widget(obj,"entry34");
	

	spinbutton4=lookup_widget(obj,"spinbutton12");


	strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(entry5)));
	strcpy(s.desc1,gtk_entry_get_text(GTK_ENTRY(entry6)));
	strcpy(s.desc2,gtk_entry_get_text(GTK_ENTRY(entry7)));
	strcpy(s.desc3,gtk_entry_get_text(GTK_ENTRY(entry8)));
	strcpy(s.desc4,gtk_entry_get_text(GTK_ENTRY(entry9)));
	strcpy(s.desc5,gtk_entry_get_text(GTK_ENTRY(entry10)));

	s.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton4));

	ajoutOffreSpecial(s);
	

	
}



//Supprimer un offre
void
on_button6_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{

	char numero[20];
	entry1 = lookup_widget(obj,"entry28");

	strcpy(numero,gtk_entry_get_text(GTK_ENTRY(entry1)));

	supprimOffre(numero);
}

//Frecherche des offres
void
on_button7_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
	FILE *f;
	FILE *g;

	char num[50];
	char offre[50];
	char ville[50];
	char carac[50];
	char prix[50];
	char date[50];

	char nom[50];
	char jour[5];
	char desc1[50];
	char desc2[50];
	char desc3[50];
	char desc4[50];
	char desc5[50];

	char num1[50];

	char nom1[50];

	f=fopen("Toffre.txt","r");
	g=fopen("Soffre.txt","r");

	entry1=lookup_widget(obj,"entry22");
	entry7=lookup_widget(obj,"entry42");

	strcpy(num1,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(entry7)));

	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s\n",num,offre,date,ville,carac,prix)!=EOF){
			if(strcmp(num1,num)==0){

				entry1=lookup_widget(obj,"entry22");
				entry2=lookup_widget(obj,"entry23");
				entry3=lookup_widget(obj,"entry24");
				entry4=lookup_widget(obj,"entry25");
				entry5=lookup_widget(obj,"entry26");
				entry6=lookup_widget(obj,"entry27");

				
				gtk_entry_set_text(GTK_ENTRY(entry1),num);
				gtk_entry_set_text(GTK_ENTRY(entry2),offre);
				gtk_entry_set_text(GTK_ENTRY(entry3),date);
				gtk_entry_set_text(GTK_ENTRY(entry4),ville);
				gtk_entry_set_text(GTK_ENTRY(entry5),carac);
				gtk_entry_set_text(GTK_ENTRY(entry6),prix);
			}
				
				
		}
		fclose(f);
	}
	if (g!=NULL)
  	{
    		while(fscanf(g,"%s %s %s %s %s %s %s\n",nom,jour,desc1,desc2,desc3,desc4,desc5)!=EOF){
			if(strcmp(nom1,nom)==0){

				entry7=lookup_widget(obj,"entry42");
				entry8=lookup_widget(obj,"entry36");
				entry9=lookup_widget(obj,"entry37");
				entry10=lookup_widget(obj,"entry38");
				entry11=lookup_widget(obj,"entry39");
				entry12=lookup_widget(obj,"entry40");
				entry13=lookup_widget(obj,"entry41");

				
				gtk_entry_set_text(GTK_ENTRY(entry7),nom);
				gtk_entry_set_text(GTK_ENTRY(entry8),jour);
				gtk_entry_set_text(GTK_ENTRY(entry9),desc1);
				gtk_entry_set_text(GTK_ENTRY(entry10),desc2);
				gtk_entry_set_text(GTK_ENTRY(entry11),desc3);
				gtk_entry_set_text(GTK_ENTRY(entry12),desc4);
				gtk_entry_set_text(GTK_ENTRY(entry13),desc5);
			}
				
				
		}
		fclose(g);
	}
}



//modifier un offre
void
on_button8_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
	char num1[50];
	char offre1[50];
	char ville1[50];
	char carac1[50];
	char prix1[50];
	char date1[50];

	
	entry1=lookup_widget(obj,"entry22");
		strcpy(num1,gtk_entry_get_text(GTK_ENTRY(entry1)));

	entry2=lookup_widget(obj,"entry23");
		strcpy(offre1,gtk_entry_get_text(GTK_ENTRY(entry2)));

	entry3=lookup_widget(obj,"entry24");
		strcpy(ville1,gtk_entry_get_text(GTK_ENTRY(entry3)));

	entry4=lookup_widget(obj,"entry25");
		strcpy(carac1,gtk_entry_get_text(GTK_ENTRY(entry4)));

	entry5=lookup_widget(obj,"entry26");
		strcpy(prix1,gtk_entry_get_text(GTK_ENTRY(entry5)));

	entry6=lookup_widget(obj,"entry27");
		strcpy(date1,gtk_entry_get_text(GTK_ENTRY(entry6)));

	modifierOffre(num1,offre1,date1,ville1,carac1,prix1);


	char nom1[50];
	char jour1[5];
	char desc11[50];
	char desc21[50];
	char desc31[50];
	char desc41[50];
	char desc51[50];

	
	entry7=lookup_widget(obj,"entry42");
		strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(entry7)));

	entry8=lookup_widget(obj,"entry36");
		strcpy(jour1,gtk_entry_get_text(GTK_ENTRY(entry8)));

	entry9=lookup_widget(obj,"entry37");
		strcpy(desc11,gtk_entry_get_text(GTK_ENTRY(entry9)));

	entry10=lookup_widget(obj,"entry38");
		strcpy(desc21,gtk_entry_get_text(GTK_ENTRY(entry10)));

	entry11=lookup_widget(obj,"entry39");
		strcpy(desc31,gtk_entry_get_text(GTK_ENTRY(entry11)));

	entry12=lookup_widget(obj,"entry40");
		strcpy(desc41,gtk_entry_get_text(GTK_ENTRY(entry12)));

	entry13=lookup_widget(obj,"entry41");
		strcpy(desc51,gtk_entry_get_text(GTK_ENTRY(entry13)));


	modifierSoffre(nom1,jour1,desc11,desc21,desc31,desc41,desc51);
}


//consutation du catalogue par le visiteur
void
on_buttonAccCatalogue_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
	FILE *f;
	f=fopen("tmp","w");

	if(f!=NULL){
		fprintf(f,"0");
		fclose(f);
	}	
	windowclose = lookup_widget(obj,"windowAccueil");
	gtk_widget_destroy(windowclose);
	
	windowopen = lookup_widget(obj,"windowPrestEtOffre");
	windowopen=create_windowPrestEtOffre();
	gtk_widget_show(windowopen);

	treeview1=lookup_widget(windowopen,"treeviewOffres");
	afficherPrestationOffre(treeview1);
	
}


void
on_calendarOffresPrests_day_selected   (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

	guint day;
	guint month;
	guint year;

	char nom[50];
	int jour;
	char desc1[50];
	char desc2[50];
	char desc3[50];
	char desc4[50];
	char desc5[50];

	label1=lookup_widget(calendar,"label198");
	label2=lookup_widget(calendar,"label199");
	label3=lookup_widget(calendar,"label200");
	label4=lookup_widget(calendar,"label201");
	label5=lookup_widget(calendar,"label202");
	label6=lookup_widget(calendar,"label203");
	label7=lookup_widget(calendar,"label204");

	//windowPrestEtOffre=lookup_widget(calendar,"windowPrestEtOffre");

	FILE *f;
	f=fopen("Soffre.txt","r");


	calendar=lookup_widget(calendar,"calendarOffresPrests");


	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	
	if(f!=NULL){
		while(fscanf(f,"%s %d %s %s %s %s %s\n",nom,&jour,desc1,desc2,desc3,desc4,desc5)!=EOF){
			if(jour==day){
				switch (day){
				case 1:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"1");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;
					
				
					
				case 2:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"2");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;
				case 3:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"3");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 4:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"4");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 5:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"5");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 6:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"6");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 7:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"7");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 8:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"8");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;
				case 9:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"9");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;
				case 10:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"10");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 11:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"11");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 12:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"12");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 13:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"13");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 14:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"14");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;
				case 15:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"15");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 16:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"16");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 17:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"17");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;



				case 18:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"18");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;



				case 19:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"19");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;


				case 20:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"20");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;


				case 21:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"21");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 22:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"22");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 23:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"23");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;


				case 24:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"24");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;


				case 25:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"25");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 26:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"26");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 27:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"27");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 28:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"28");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 29:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"29");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 30:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"30");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				case 31:
					gtk_label_set_text(GTK_LABEL(label1),nom);
					gtk_label_set_text(GTK_LABEL(label2),"31");
					gtk_label_set_text(GTK_LABEL(label3),desc1);
					gtk_label_set_text(GTK_LABEL(label4),desc2);
					gtk_label_set_text(GTK_LABEL(label5),desc3);
					gtk_label_set_text(GTK_LABEL(label6),desc4);
					gtk_label_set_text(GTK_LABEL(label7),desc5);
					break;

				default:					
					gtk_label_set_text(GTK_LABEL(label1),"r");
					gtk_label_set_text(GTK_LABEL(label2),"r");
					gtk_label_set_text(GTK_LABEL(label3),"r");
					gtk_label_set_text(GTK_LABEL(label4),"r");
					gtk_label_set_text(GTK_LABEL(label5),"r");
					gtk_label_set_text(GTK_LABEL(label6),"r");
					gtk_label_set_text(GTK_LABEL(label7),"r");

				}
	
			
			}

		}
		fclose(f);	
	}
}

//gestion des agents
void
on_button13_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window1=lookup_widget(obj,"window1");
	window2=lookup_widget(obj,"window2");

	window2=create_window2();
	gtk_widget_destroy(window1);	
	gtk_widget_show(window2); 
}


void
on_button10_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	windowclose = lookup_widget(obj,"windowAccueil");
	gtk_widget_destroy(windowclose);

	windowopen = lookup_widget(obj,"windowAuthenti");
	windowopen = create_windowAuthenti();

	table1=gtk_table_new(0,0,TRUE);
	gtk_container_add(GTK_CONTAINER(windowopen),GTK_WIDGET(table1));
	image1=create_pixmap(windowopen,"./auth3.jpg");
	image1=gtk_image_new_from_file("./auth3.jpg");
	gtk_table_attach_defaults(GTK_TABLE(table1),image1,0,0,0,0);

	
	gtk_widget_show_all(windowopen);
}

//gestion des cilents
void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}



//gestion des réclammations
void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

//sortir de l'espace admin
void
on_button12_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"windowAccueil");
	window1=lookup_widget(obj,"window1");

	window2=create_windowAccueil();
	gtk_widget_destroy(window1);	
	gtk_widget_show(window2); 	
}


void
on_button16_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"window2");
	window3=lookup_widget(obj,"window3");

	window3=create_window3();
	gtk_widget_destroy(window2);	
	gtk_widget_show(window3); 
}


void
on_button22_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window3=lookup_widget(obj,"window3");
	window2=lookup_widget(obj,"window2");

	window2=create_window2();
	gtk_widget_destroy(window3);	
	gtk_widget_show(window2); 
}


void
on_button23_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	
	window3=lookup_widget(obj,"window3");
	window2=lookup_widget(obj,"window2");

	window2=create_window2();
	gtk_widget_destroy(window3);	
	gtk_widget_show(window2); 
}

//ajout agent
void
on_button21_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	agent agen;
	GtkWidget *combobox_sex;
	GtkWidget *input1,*input2, *input3, *input4, *input5;
	GtkWidget *window_ajout_agent;

	window_ajout_agent=lookup_widget(obj,"window_ajout_agent");

	input1=lookup_widget(obj, "entry43");
	input2=lookup_widget(obj, "entry44");
	input3=lookup_widget(obj, "entry45");
	combobox_sex=lookup_widget(obj, "combobox1");
	//spinbutton_age=lookup_widget(obj, "spinbutton_age");
	input4=lookup_widget(obj, "entry46");
	input5=lookup_widget(obj, "entry47");


	strcpy(agen.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(agen.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(agen.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(agen.sex,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_sex)));
	//strcpy(agen.age,gtk_spin_button_get_value_as_text(GTK_SPIN_BUTTON(spinbutton_age)));
	strcpy(agen.login,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(agen.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input5)));
	
	
	ajouter_agent(agen);
}

//afficher agent
void
on_button17_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	GtkWidget *window_accueil;
	GtkWidget *window_afficher_agent;
	GtkWidget *treeview1;

	window_accueil=lookup_widget(obj,"window2");

	gtk_widget_destroy(window_accueil);
	window_afficher_agent=lookup_widget(obj,"window4");
	window_afficher_agent=create_window4();

	gtk_widget_show(window_afficher_agent);

	treeview1=lookup_widget(window_afficher_agent,"treeview1");
	afficher_agent(treeview1);
}

//retour accueil agent
void
on_button24_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"window2");
	window4=lookup_widget(obj,"window4");

	window2=create_window2();
	gtk_widget_destroy(window4);	
	gtk_widget_show(window2); 
}

//accès page modification agent
void
on_button18_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"window2");
	window5=lookup_widget(obj,"window5");

	window5=create_window5();
	gtk_widget_destroy(window2);	
	gtk_widget_show(window5); 
}

//button rechercher
void
on_button25_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	GtkWidget *rechcin,*cin,*nom,*prenom,*sex,*age,*login,*mot_de_passe;
 	agent agen;
 	char cin1[30];
 
 	rechcin=lookup_widget (obj,"entry48");
 	strcpy(cin1,gtk_entry_get_text (GTK_ENTRY(rechcin)));
  
 	agen = rechercher_agent(cin1);

	FILE* f;
  	f=fopen("agents.txt","r");
 
  	cin=lookup_widget (obj,"entry49");
  	nom=lookup_widget (obj,"entry53");
  	prenom=lookup_widget (obj,"entry51");
  	sex=lookup_widget (obj,"entry54");
  	//age=lookup_widget (obj,"entry_nouveau_age");
  	login=lookup_widget (obj,"entry50");
  	mot_de_passe=lookup_widget (obj,"entry52");

  	gtk_entry_set_text (GTK_ENTRY(cin),agen.cin);
  	gtk_entry_set_text (GTK_ENTRY(nom),agen.nom);
  	gtk_entry_set_text (GTK_ENTRY(prenom),agen.prenom);
  	//gtk_entry_set_text (GTK_ENTRY(sex),agen.sex);
  	//gtk_combo_box_set_active(GTK_COMBO_BOX(sex),agen.sex);
  	//gtk_combo_box_get_active_text(GTK_COMBO_BOX(sex));
  	gtk_entry_set_text (GTK_ENTRY(sex),agen.sex);
  	//gtk_entry_set_text (GTK_ENTRY(age),agen.age);
  	gtk_entry_set_text (GTK_ENTRY(login),agen.login);
  	gtk_entry_set_text (GTK_ENTRY(mot_de_passe),agen.mot_de_passe); 
    
  	fclose(f);
}

//button valider ma modification
void
on_button26_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	GtkWidget *cin,*nom,*prenom,*sex,*age,*login,*mot_de_passe;
  
  	agent agen;
  	FILE* f;
  	f=fopen("agents.txt","r");

 	cin=lookup_widget (obj,"entry49");
  	nom=lookup_widget (obj,"entry53");
  	prenom=lookup_widget (obj,"entry51");
  	sex=lookup_widget (obj,"entry54");
  	//age=lookup_widget (obj,"entry_nouveau_age");
  	login=lookup_widget (obj,"entry50");
  	mot_de_passe=lookup_widget (obj,"entry52");

  	strcpy(agen.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  	strcpy(agen.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  	strcpy(agen.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  	//strcpy(agen.sex,gtk_entry_get_text(GTK_ENTRY(sex)));
  	//strcpy(agen.sex,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sex)));
  	strcpy(agen.sex,gtk_entry_get_text(GTK_ENTRY(sex)));
  	//strcpy(agen.age,gtk_entry_get_text(GTK_ENTRY(age)));
  	strcpy(agen.login,gtk_entry_get_text(GTK_ENTRY(login)));
  	strcpy(agen.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(mot_de_passe)));
	
	modifier_agent(agen);
  	fclose(f);
}


void
on_button27_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"window2");
	window5=lookup_widget(obj,"window5");

	window2=create_window2();
	gtk_widget_destroy(window5);	
	gtk_widget_show(window2); 
}

//accès page suppression agent
void
on_button19_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"window2");
	window6=lookup_widget(obj,"window6");

	window6=create_window6();
	gtk_widget_destroy(window2);	
	gtk_widget_show(window6); 
}


void
on_button29_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window2=lookup_widget(obj,"window2");
	window6=lookup_widget(obj,"window6");

	window2=create_window2();
	gtk_widget_destroy(window6);	
	gtk_widget_show(window2);
}

//supprimer agent
void
on_button28_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	char cin[30];
	GtkWidget *input1;
	GtkWidget *window_supprimer_agent;

	window_supprimer_agent=lookup_widget(obj,"window6");
	input1=lookup_widget(obj, "entry55");
	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
	supprimer_agent(cin);
}


//ajouter facture
void
on_button33_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	GtkWidget *entry1;
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
	
	DT fact;

	entry1=lookup_widget(obj,"entry56");
	entry2=lookup_widget(obj,"entry57");
	entry3=lookup_widget(obj,"entry58");
	spin1=lookup_widget(obj,"spinbutton14");
	spin2=lookup_widget(obj,"spinbutton15");
	spin3=lookup_widget(obj,"spinbutton16");
	combobox1=lookup_widget(obj,"combobox2");
	entry4=lookup_widget(obj,"entry59");
	entry5=lookup_widget(obj,"entry61");
	entry6=lookup_widget(obj,"entry60");
	entry7=lookup_widget(obj,"entry62");

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



//suppression facture
void
on_button34_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	char id[50];

	GtkWidget *entry1;
	entry1=lookup_widget(obj,"entry63");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry1)));

	supprimer_facture(id);
	
}

//recherche modif facture
void
on_button35_clicked                    (GtkWidget       *obj,
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
entry20=lookup_widget(obj,"entry64");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry20)));
if (fa!=NULL)
 {
    	while(fscanf(fa,"%s %s %s %s %s %s %s %s %s \n",f.id,f.n,f.emis_par,date,f.prestation,f.id_prestation,f.code_coupan,f.mantant_HT,f.mantant_TTC)!=EOF)
 {
			if(strcmp(id1,f.id)==0){

				entry1=lookup_widget(obj,"entry64");
				entry2=lookup_widget(obj,"entry66");
				entry3=lookup_widget(obj,"entry67");
				entry4=lookup_widget(obj,"entry69");
				entry5=lookup_widget(obj,"entry68");
				entry6=lookup_widget(obj,"entry65");
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
on_button36_clicked                    (GtkWidget       *obj,
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
	entry1=lookup_widget(obj,"entry64");
	strcpy(idd,gtk_entry_get_text(GTK_ENTRY(entry1)));
	entry2=lookup_widget(obj,"entry66");
	strcpy(n,gtk_entry_get_text(GTK_ENTRY(entry2)));
	entry3=lookup_widget(obj,"entry67");
	strcpy(agent,gtk_entry_get_text(GTK_ENTRY(entry3)));
	entry4=lookup_widget(obj,"entry69");
	strcpy(date1,gtk_entry_get_text(GTK_ENTRY(entry4)));
	entry5=lookup_widget(obj,"entry68");
	strcpy(prest,gtk_entry_get_text(GTK_ENTRY(entry5)));
	entry6=lookup_widget(obj,"entry65");
	strcpy(nouvmontant,gtk_entry_get_text(GTK_ENTRY(entry6)));
	
	 modifier_f(idd,nouvmontant,n,prest,agent,date1);
}

//affichage de toutes les factures 
void
on_button30_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *treeview;

	window1=lookup_widget(obj,"window7");
	treeview=lookup_widget(window1,"treeview2");

	afficher_facture(treeview);
}

//deconnect fact
void
on_button32_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window7=lookup_widget(obj,"window7");
	window1=lookup_widget(obj,"windowAccueil");

	window1=create_windowAccueil();
	gtk_widget_destroy(window7);	
	gtk_widget_show(window1);
}


//accès formulaire facture client
void
on_button31_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window7=lookup_widget(obj,"window7");
	window8=lookup_widget(obj,"window8");

	window8=create_window8();
	gtk_widget_destroy(window7);	
	gtk_widget_show(window8);
}


void
on_button39_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window7=lookup_widget(obj,"window7");
	window8=lookup_widget(obj,"window8");

	window7=create_window7();
	gtk_widget_destroy(window8);	
	gtk_widget_show(window7);
}


void
on_button37_clicked                    (GtkWidget       *obj,
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

entry1=lookup_widget(obj,"entry70");
entry2=lookup_widget(obj,"entry71");
entry3=lookup_widget(obj,"entry72");
entry4=lookup_widget(obj,"entry73");
entry5=lookup_widget(obj,"entry74");
combobox1=lookup_widget(obj,"combobox3");

strcpy(p.id_,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(p.nom_,gtk_entry_get_text(GTK_ENTRY(entry2)));
strcpy(p.prenom_,gtk_entry_get_text(GTK_ENTRY(entry3)));
strcpy(p.type_payement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(p.num_carte,gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(codecarte,gtk_entry_get_text(GTK_ENTRY(entry5)));
 ajouter_payement(p);
}


void
on_button20_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
	window1=lookup_widget(obj,"window1");
	window2=lookup_widget(obj,"window2");

	window1=create_window1();
	gtk_widget_destroy(window2);	
	gtk_widget_show(window1);
}

