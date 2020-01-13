#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajouter_prest_vol.h"



//ajouter une prestation pour le Vol
void ajouterPrestVol(Ajouter a)
{
	FILE *f;
	f=fopen("prestVol.txt","a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %d/%d/%d %dH%dMn %s %d/%d/%d %dH%dMn %s %s\n",
						a.id,a.comp,a.avion,a.classe,a.dpt_ville,
						a.dt_vol.jour_dpt,a.dt_vol.mois_dpt,a.dt_vol.annee_dpt,
						a.dt_vol.heure_dpt,a.dt_vol.minute_dpt,
						a.arr_ville,
						a.dt_vol.jour_arr,a.dt_vol.mois_arr,a.dt_vol.annee_arr,
						a.dt_vol.heure_arr,a.dt_vol.minute_arr,
						a.pr_class,a.econ);
		fclose(f);
	}
}

//ajouter une prestation pour l'hébergement

void ajouterPrestHbr(AjouterHbr h){
	FILE *hb;
	hb=fopen("hebergement.txt","a+");
	if(hb!=0){
		fprintf(hb,"%s %s %s %s %s %s %s %s\n",h.id,h.categ,h.hotel,h.dispo,h.nbrChamb,h.ville,h.varPrix,h.com);
		fclose(hb);
	}
	
}


//ajouter une prestation pour l'hébergement

void ajouterPrestVoit(AjouterPrestVoit v){

	FILE *voi;
	voi=fopen("voiture.txt","a+");
	if(voi!=0){
		fprintf(voi,"%s %s %s %s %s %s %s %s\n",v.id,v.marq,v.type,v.km,v.vitesse,v.dispo,v.com,v.prix);
		fclose(voi);
	}



}


//ajouter une offre
void ajouterOffre(Offre o){

	FILE *of;
	of=fopen("Toffre.txt","a+");
	if(of!=0){
		fprintf(of,"%s %s %d/%d/%d %s %s %s\n",o.num,o.offre,o.of.jour,o.of.mois,o.of.annee,o.ville,o.carac,o.prix);
		fclose(of);
	}



}


void ajoutOffreSpecial(special s){


	FILE *sp;
	sp=fopen("Soffre.txt","a+");

	if(sp!=0){
		fprintf(sp,"%s %d %s %s %s %s %s %s\n",s.nom,s.jour1,s.desc1,s.desc2,s.desc3,s.desc4,s.desc4,s.desc5);
		fclose(sp);

	}
}
