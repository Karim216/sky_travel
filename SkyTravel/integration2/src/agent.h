#include <gtk/gtk.h>

/*typedef struct
{
int x
}agee;
*/
typedef struct
{

char cin[30];
char nom[30];
char prenom[30];
char sex[30];
//char age;
char login[30];
char mot_de_passe[30];

} agent;

void ajouter_agent(agent agen);
void afficher_agent(GtkWidget *liste);
void supprimer_agent(char cin[]);
agent rechercher_agent (char cin[30]);
void modifier_agent(agent agen);
