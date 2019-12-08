#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verifAuthentif.h"


int verifAuthentification(char user_name[], char pwd[]){

	char us[50], pass[50];
	int role;
	FILE *f;

	f=fopen("authentification.txt","r");
	if(f!=NULL){
		while (fscanf(f,"%s %s %d\n", us, pass, &role)!=EOF){
			if(strcmp(user_name,us)==0 && strcmp(pwd,pass)==0){
				return role;
			}
			/*else{
				role=0;
				return role;
			
			}*/
		
		}
		fclose(f);
	}
	
}
