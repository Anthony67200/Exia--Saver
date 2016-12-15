#include <stdlib.h>		//Bibliothèque fondamentales
#include <stdio.h>		//Contenant printf, scanf, ...
#include <ncurses.h>		//Bibliothèque pour quitter le processus sur commande de touches
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define LARGEUR_CONSOLE 80

int InitTime()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant=*localtime(&secondes);
	int TimeS1 = (instant.tm_sec)/10;
	int TimeS2 = (instant.tm_sec)-(TimeS1*10);
	int TimeM1 = (instant.tm_min)/10;
	int TimeM2 = (instant.tm_min)-(TimeM1*10);
	int TimeH1 = (instant.tm_hour)/10;
	int TimeH2 = (instant.tm_hour)-(TimeH1*10);
	//printf("Horloge --> %u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);

	int Tab[8];
	Tab[0]=TimeH1;
	Tab[1]=TimeH2;
	Tab[2]=20;
	Tab[3]=TimeM1;
	Tab[4]=TimeM2;
	Tab[5]=20;
	Tab[6]=TimeS1;
	Tab[7]=TimeS2;

	int z = 0;
	int TailleFich = 1;

	int y=12, x=9;
	FILE* fichier1 = NULL;     		//Pointeur initialisé à NULL
	char chaine[1000];         //taille max du fichier
	int chaine2[2];
        int i=0, j=0;				//Déclaration des deux variables pour les boucles
        int r,e;

	fichier1 = (FILE*)malloc(sizeof(int));	//Permet d'allouer de la mémoire au pointeur fichier1

	for (z=0;z<8;z++)
	{
		switch (Tab[z])
				
		{
			case 0:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/0.pbm", "r");
				break;
			case 1:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/1.pbm", "r");
				break;
			case 2:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/2.pbm", "r");
				break;
			case 3:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/3.pbm", "r");
				break;
			case 4:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/4.pbm", "r");
				break;
			case 5:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/5.pbm", "r");
				break;
			case 6:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/6.pbm", "r");
				break;
			case 7:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/7.pbm", "r");
				break;
			case 8:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/8.pbm", "r");
				break;
			case 9:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/9.pbm", "r");
				break;
			case 20:
				fichier1 = fopen("/home/elendril/Bureau/EXIASAVER_HOME/EXIASAVER2_PBM/3x5/point.pbm", "r");
				break;
		}

//..........................................................................................................AFFICHAGE DE L'IMAGE.....................................................................................................

		 if (fichier1 != NULL) 							//On peut lire le fichier
        	    {
        	        fseek(fichier1, 3, SEEK_SET);
        	        fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]);
        	        r = chaine2[0];
        	        e = chaine2[1];
        	        r = (r*2)-1;

			fseek(fichier1, 1, SEEK_CUR);
        	      	for(i=0; i<e; i++)                   			//Boucle qui va parcourir les lignes
        	            {
				gotoxy(x,y);
				fgets(chaine, 1000, fichier1);		//récupération de la ligne
        	                for(j=0; j<r; j++)               		//boucle qui parcours la ligne
        	                    {
					gotoxy(x,y);
					if (chaine[j] == '0')
        	                            chaine[j] = ' ';        		//Affiche les caractères correspondants en ' '
        	       			else if (chaine[j] == '1')
        	                            	chaine[j] = 'X';
        	                    }
				x=x+1;
				printf("%s", chaine);				//Afficher l'image ligne par ligne
        	            }
				fclose(fichier1);   				//On ferme le fichier ouvert
				fichier1 = NULL;
				free(fichier1);					//Permet de libérer la mémoire allouer
        	    }
		x=x-5;
		y=y+7;
	}

}

int dotLoading(int refresh)
{
	system("clear");
	int i = 0;
	int coordy = 40; //Il s'agit des coordonnées où devront s'afficher le premier point
	int coordx = 23;
	gotoxy(20,30);
	InitTime();
	gotoxy(23,0);
	printf("L'heure va s'actualiser automatiquement");
	for (size_t i = 0; i < refresh; i++) { //boucle for qui permet d'afficher un point par seconde après la phrase
		gotoxy(coordx,coordy); //et ce jusqu'à que l'heure s'actualise
		printf(".\n");
		sleep(1);
		coordy++;
	}
coordy = 40;
dotLoading(refresh); //une fois que la période d'actualisation est atteinte la fonction d'affichage se relance pour actualiser
return 0;
}

int main()
{

	int refresh;				//Temps en seconde avant actualisation
	system("clear");				//Nettoiement de la console
	printf("Quel est le temps de refresh pour l'heure ? (en secondes)\n"); //Question à l'user
	scanf("%d", &refresh);
	system("clear");
	dotLoading(refresh);
	return 0;
}
