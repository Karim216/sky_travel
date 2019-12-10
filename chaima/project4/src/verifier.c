#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "verifier.h"

int verifier(char username[], char password[], int role){
	char nom[50];
	char mdp[50];
	int x; 
	FILE *f;
	f=fopen("authentification.txt","r");
	while (fscanf(f,"%s %s %d",nom,mdp,&x)!=EOF){
		if (strcmp(nom,username)==0 && strcmp(mdp,password)==0){
			return x;
		}
		else{
			return role;
		}
		fclose(f);
	}
}
