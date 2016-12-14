#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bibliothèque pour le Rand
#include <sys/stat.h>
#include "launcher.h"

int main(int argc, char** argv)
{
    if(argv[1]=="-stat")
    {
      printf("Programme menu Stat");
    }

    system("clear"); // Permet de nettoyer la console
    /*--------Nombre Random--------*/
    srand (time(NULL));
    int choix=rand()%3+1;

    int ch_image;
    ch_image = rand()%4+1;

    /*--------Condition en fonction du mode choisis--------*/

    if (choix == 1)
    {
      printf("Lancement du type statique ! \n");
      switch (ch_image)
      {
        case 1:
          printf("TEST1");
          FILE* fichier = NULL;
          int caractereActuel = 0;
          fichier = fopen("EXIASAVER1_PBM/1.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel = fgetc(fichier);
              printf("%c", caractereActuel);
            } while (caractereActuel != EOF);
            fclose(fichier);
          }
        break;
        case 2:
          printf("TEST2");
          FILE* fichier2 = NULL;
          int caractereActuel2 = 0;
          fichier2 = fopen("EXIASAVER1_PBM/2.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel2 = fgetc(fichier2);
              printf("%c", caractereActuel2);
            } while (caractereActuel2 != EOF);
            fclose(fichier2);
          }
        break;
        case 3:
          printf("TEST3");
          FILE* fichier3 = NULL;
          int caractereActuel3 = 0;
          fichier3 = fopen("EXIASAVER1_PBM/3.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel3 = fgetc(fichier3);
              printf("%c", caractereActuel3);
            } while (caractereActuel3 != EOF);
            fclose(fichier3);
          }
        break;
        case 4:
          printf("TEST4");
          FILE* fichier4 = NULL;
          int caractereActuel4 = 0;
          fichier4 = fopen("EXIASAVER1_PBM/4.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel4 = fgetc(fichier4);
              printf("%c", caractereActuel4);
            } while (caractereActuel4 != EOF);
            fclose(fichier4);
          }
        break;
      }
    }
    else if (choix == 2)
    {
      printf("Lancement du type dynamique ! \n");
    }
    else
    {
      printf("Lancement du type intéractif ! \n");
    }
sauvegarde(ch_image,choix);
return 0;
}

void sauvegarde(int typefichier, int image_ch)
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

    if (typefichier == 1)
    {
      switch(image_ch)
      {
        case 1:
          fseek(historique, 25, SEEK_SET);
          fprintf(historique,"EXIASAVER1_PBM/1.pbm\n");
        break;
        case 2:
          fseek(historique, 25, SEEK_SET);
          fprintf(historique,"EXIASAVER1_PBM/2.pbm\n");
        break;
        case 3:
          fseek(historique, 25, SEEK_SET);
          fprintf(historique,"EXIASAVER1_PBM/3.pbm\n");
        break;
        case 4:
          fseek(historique, 25, SEEK_SET);
          fprintf(historique,"EXIASAVER1_PBM/4.pbm\n");
        break;
      }
    }
    fseek(historique, 0, SEEK_END);
    fprintf(historique,"%s;%d\n",s_Date,typefichier);
  }
  return;
}