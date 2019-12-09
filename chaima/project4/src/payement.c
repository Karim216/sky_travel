#include <stdio.h>
#include <string.h>
#include "payement.h"
#include <gtk/gtk.h>
//Ajouter une payement

void ajouter_payement(payement p)
{
 	
FILE *fp;
fp=fopen("payement.txt","a+");
if(fp!=NULL) 
{
fprintf(fp,"%s %s %s %s %s %s \n",p.id_,p.nom_,p.prenom_,p.num_carte,p.type_payement,"paye");
fclose(fp);
	
}
}


