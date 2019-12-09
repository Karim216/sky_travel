#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "modifier_prest_vol.h"




//modification d'une prestation pour le vol
void modifierPrestVol(char id1[],char comp1[],char avion1[],char classe1[],char dpt_ville1[],char date_dpt1[],char heure_dpt1[],char arr_ville1[],char date_arr1[],char heure_arr1[],char pr_class1[],char econ1[])

{


FILE *f;
FILE* f_tmp;

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

f=fopen("prestVol.txt","r");
  f_tmp=fopen("prestVol_tmp.txt","a+");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",id,comp,avion,classe,dpt_ville,date_dpt,heure_dpt,
			arr_ville,date_arr,heure_arr,pr_class,econ)!=EOF)
          {
                if (strcmp(id,id1)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",id,comp,avion,classe,dpt_ville,date_dpt,
				heure_dpt,arr_ville,date_arr,heure_arr,pr_class,econ);
                   
                   }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",id1,comp1,avion1,classe1,dpt_ville1,date_dpt1,heure_dpt1,arr_ville1,date_arr1,heure_arr1,pr_class1,econ1);
                  }
          }
     }
    	  fclose(f);
          fclose(f_tmp);

     
          rename("prestVol_tmp.txt","prestVol.txt");
}




//modification d'une prestation pour l'hébergement

void  modifierPrestHbr(char id1[], char categ1[], char hotel1[], char dispo1[], char chamb1[], char ville1[], char prix1[], char com1[])

{


FILE *f;
FILE* f_tmp;
	char id[50];
	char categ[50];
	char hotel[50];
	char dispo[50];
	char chamb[50];
	char ville[50];
	char prix[50];
	char com[50];

f=fopen("hebergement.txt","r");
  f_tmp=fopen("tmpHbr.txt","a+");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,categ,hotel,dispo,chamb,ville,prix,com)!=EOF)
          {
                if (strcmp(id,id1)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s\n",id,categ,hotel,dispo,chamb,ville,prix,com);
                   
                   }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s\n",id1,categ1,hotel1,dispo1,chamb1,ville1,prix1,com1);
                  }
          }
     }
    	  fclose(f);
          fclose(f_tmp);

     
          rename("tmpHbr.txt","hebergement.txt");
}

void modifierVoiture(char id1[], char marq1[], char type1[], char km1[], char vitesse1[], char dispo1[], char com1[], char prix1[]){

FILE *f;
FILE* f_tmp;
	char id[50];
	char marq[50];
	char type[50];
	char km[50];
	char vitesse[50];
	char dispo[50];
	char com[50];
	char prix[50];

f=fopen("voiture.txt","r");
  f_tmp=fopen("tmpVoi.txt","a+");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,marq,type,km,vitesse,dispo,com,prix)!=EOF)
          {
                if (strcmp(id,id1)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s\n",id,marq,type,km,vitesse,dispo,com,prix);
                   
                   }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s\n",id1,marq1,type1,km1,vitesse1,dispo1,com1,prix1);
                  }
          }
     }
    	  fclose(f);
          fclose(f_tmp);

     
          rename("tmpVoi.txt","voiture.txt");

}



void modifierOffre(char num1[], char offre1[], char date1[], char ville1[], char carac1[], char prix1[]){

FILE *f;
FILE* f_tmp;
	char num[50];
	char offre[50];
	char ville[50];
	char carac[50];
	char prix[50];
	char date[50];

	f=fopen("Toffre.txt","r");
 	f_tmp=fopen("tmp.txt","a+");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s\n",num,offre,date,ville,carac,prix)!=EOF)
          {
                if (strcmp(num,num1)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s\n",num,offre,date,ville,carac,prix);
                   
                   }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s\n",num1,offre1,date1,ville1,carac1,prix1);
                  }
          }
     }
    	  fclose(f);
          fclose(f_tmp);

     
          rename("tmp.txt","Toffre.txt");

}

//modifier offre spécial
void modifierSoffre(char nom1[], char jour1[], char desc11[], char desc21[], char desc31[], char desc41[], char desc51[]){

	char nom[50];
	char jour[5];
	char desc1[50];
	char desc2[50];
	char desc3[50];
	char desc4[50];
	char desc5[50];

	FILE *f;
	FILE* f_tmp;

	f=fopen("Soffre.txt","r");
 	f_tmp=fopen("tmp.txt","a+");
  	if (f!=NULL)
  	{
    		while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,jour,desc1,desc2,desc3,desc4,desc5)!=EOF){
                	if (strcmp(nom,nom1)!=0){
                    		fprintf(f_tmp,"%s %s %s %s %s %s %s\n",nom,jour,desc1,desc2,desc3,desc4,desc5);
                   
                   	}
                	else{
                    		fprintf(f_tmp,"%s %s %s %s %s %s %s\n",nom1,jour1,desc11,desc21,desc31,desc41,desc51);
                  	}
          	}
     	}
	fclose(f);
	fclose(f_tmp);

     
        rename("tmp.txt","Soffre.txt");
	
}
