#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bibliothèque pour le Rand
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "launcher.h"
#include <string.h>



int main(int argc, char** argv)
{

    if(argv[1] != NULL)  // si on tape quelque chose après l'executable, comme "-stats", la suite s'execute
    {
    system("clear");
    int nombre;  // initialise nombre
    printf("            ------            Menu Statistique            ------\n\n");
    printf("1.Trier par Date\n");
    printf("2.Trier par Type\n");
    printf("3.Trier par Extension\n");

    printf("Choissisez le menu que vous souhaitez afficher\n");

    scanf("%d", &nombre); // on choisit le nombre voulut pour le menu des Statistique.
    FILE *fichier = NULL;  // initialise le pointeur fichier à NULL
    fichier = fopen("historique.txt", "r");  // on ouvre le fichier historique.txt
    int i = 0;   // initialisation de i
    char* date = NULL;  // initialisation d'un pointeur sur date
    char* type= NULL;    //initialisation d'un pointeur sur type
    char* extension = NULL;   //initialisation d'un pointeur sur extension

    date = malloc(0 *sizeof(char));  // on alloue un tableau dynamique à date
    type = malloc(0 *sizeof(char));  //on alloue un tableau dynamique à type
    extension = malloc(0 *sizeof(char));  //on alloue un tableau dynamique à extension

    char* tab = NULL;   // initialisation de pointeur sur tab
    tab = (char *) malloc(1000);  // allocation du tableau de longeur 10000


        switch (nombre)    // va permetre de choisir un cas suivant le nombre choisis pour le menu des Statistique.
        {
          case 1:   // cas 1


                while(fgets(tab, 1000,fichier) != NULL)   // boucle qui va lire les lignes du fichier historique jusqu'à la fin des lignes
                {
                    strcpy(&date[0],strtok(tab,";"));  // va copier la ligne jusqu'au carractaire ";" dasn le tableau date
                    strcpy(&type[0],strtok(NULL,";"));  // va copier la ligne jusqu'au carractaire ";" dasn le tableau type
                    strcpy(&extension[0],strtok(NULL,";"));  // va copier la ligne jusqu'au carractaire ";" dasn le tableau extension

                    printf ("%s, %s, %s \n", date, type, extension);  // affichage du tableau date, type et extension

                    i++;  // on passe à la ligne suivante (et donc on revient au début du while)
                  }
          break;
          case 2:  // le cas 2 qui va fonctionner comme le premier, seul change l'ordre d'affichage des tableaux.

            while(fgets(tab, 1000,fichier) != NULL)
            {
                strcpy(&date[0],strtok(tab,";"));
                strcpy(&type[0],strtok(NULL,";"));
                strcpy(&extension[0],strtok(NULL,";"));

                printf ("%s, %s, %s \n", type, date, extension);

                i++;
              }

          break;
          case 3:  // --------Cas 3 comme les deux premiers-------------

          while(fgets(tab, 1000,fichier) != NULL)
          {
              strcpy(&date[0],strtok(tab,";"));
              strcpy(&type[0],strtok(NULL,";"));
              strcpy(&extension[0],strtok(NULL,";"));

              printf ("%s, %s, %s \n", extension, date, type);

              i++;
            }

          break;

            fclose(fichier);  // On ferme le fichier ouvert au début.
        }

    return 1;
  }           // fin du if de début, et donc fin du programme

    system("clear"); // Permet de nettoyer la console
    /*--------Nombre Random--------*/
    srand (time(NULL));
    int choix=rand()%3+1;

    int ch_image;
    ch_image = rand()%5+1;
    sauvegarde(choix,ch_image);

    /*--------Condition en fonction du mode choisis--------*/
    if (choix == 1)
    {
      printf("Lancement du type statique ! \n");

		if(ch_image == 1)
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/1.pbm",NULL);
		}
		if(ch_image == 2)
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/2.pbm",NULL);
		}
		if(ch_image == 3)
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/3.pbm",NULL);
		}
		if(ch_image == 4)
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/4.pbm",NULL);
		}
		if(ch_image == 5)
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/5.pbm",NULL);
		}
    }


    else if (choix == 2)
    {
      printf("Lancement du type dynamique ! \n");
	  execl ("Dynamique/dynamique","Dynamique/dynamique","",NULL);
    }
    else if (choix == 3)
    {
      printf("Lancement du type intéractif ! \n");
    }


return 0;

}

void sauvegarde(int fichier, int image)  // fonction qui va réaliser la sauvegarde des statiqtiques dans le fichier "historique.txt"
{
  FILE* historique = NULL; // Initialise le pointeur à NULL
  historique = fopen("historique.txt", "r+"); // Ouvre le fichier historique

  if (historique != NULL) // Permet de vérifier que le fichier soit bien ouvert.
  {
    /*--------Récupération de la date et de l'heure--------*/

    // Lire l'heure courante
    time_t Date;
    Date = time(NULL);
    // Conversion de l'heure en locale
    struct tm tm_Date = *localtime (&Date);
    // Créer une chaine JJ/MM/AAAA HH:MM:SS
    char s_Date[sizeof "JJ/MM/AAAA HH:MM:SS"];
    strftime (s_Date, sizeof s_Date, "%d/%m/%Y %H:%M:%S", &tm_Date);

    /*Permet d'écrire la date dans le bon format dans l'historique
    fseek 25 permet d'éviter de lire les 25 premiers caractères*/

    if (fichier == 1)
   {
    switch(image)
     {
       case 1:
         fseek(historique, 0, SEEK_END); // permet de commencer à écrire sur la ligne vide juste après la dernière ligne écrite
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/1.pbm;\n",s_Date,fichier);  // copie des statistiques sur l'historique.txt
       break;
       case 2:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/2.pbm;\n",s_Date,fichier);
       break;
       case 3:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/3.pbm;\n",s_Date,fichier);
       break;
       case 4:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/4.pbm;\n",s_Date,fichier);

       break;

     }

   }
   else if (fichier == 2)
   {
     fseek(historique,0, SEEK_END);
     fprintf(historique, "%s;%d;5x3;\n",s_Date,fichier);
   }
   else if (fichier == 3)
   {
     fseek(historique,0, SEEK_END);
     fprintf(historique, "%s;%d;rien;\n",s_Date,fichier);
   }

   fclose(historique);  //  on ferme le fichier

  }
  return;
}
