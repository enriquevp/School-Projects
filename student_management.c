/* GestioAlumnes.c  * 
 * Programa que realitza la gestió d'una taula d'alumnes */

/*Mòduls importats*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Constants*/
#define MAX_NOM 10
#define MAX_LLISTA 10

/*Tipus definit*/
typedef struct {
	char nom [MAX_NOM];
	int curs;
	char grup;
	float mitjana;
}alumne;

/*Variables globals*/
int elements;

char menu(char op)
{
        system("clear");
	printf("\tMenú Alumnes\n");
	printf("===================\n");
	printf("a) Introduir Alumne\n");
	printf("b) Llistar Alumnes\n");
	printf("c) Buscar Alumne\n");
	printf("d) Esborrar Alumne\n");
	printf("e) Sortir\n");
	printf("===================\n");
	printf("Tria una opció: ");

	scanf("%c%*c",&op);
        return op;
}

void introduir_alumne(alumne llista[MAX_LLISTA])
{ 
        if (elements < MAX_LLISTA){
                printf("\nEscriu el nom: ");
                scanf("%9[^\n]",(char*)&llista[elements].nom);
                printf("Escriu el curs: ");
                scanf("%d%*c",&llista[elements].curs);
                printf("Escriu el grup: ");
                scanf("%c",&llista[elements].grup);
                printf("Escriu la mitjana: ");
                scanf("%f",&llista[elements].mitjana);
                elements++;
	}else {
                printf("\n  Llista plena\n");	
	}
        scanf("%*c");
}

void llistar_alumnes(alumne llista[MAX_LLISTA])
{
        int i;
        if (elements > 0){
	        printf("\n  Nom	   Curs Grup  Mitjana\n");
		printf("=============================\n");
                for (i=0; i<elements; i++){
		        printf("  %-9s %2d ",llista[i].nom,llista[i].curs);
                        printf("   %c     %.2f\n",llista[i].grup,llista[i].mitjana);
		}
	}else {
	     	printf("\n  Llista buida\n");
        }
	scanf("%*c");
}

void cercar_alumnes(alumne llista[MAX_LLISTA])
{
        int i;
        char nom[MAX_NOM];

        printf("\nEscriu el nom a cercar: ");
	scanf("%9[^\n]%*c",(char*)&nom);
	i=0;
	while (i<elements-1 & strcmp(nom,llista[i].nom)!=0)
                i++;
	if (strcmp(nom,llista[i].nom)==0){
        	printf("\n  Nom  Curs Grup  Mitjana\n");
		printf("=============================\n");
                printf("  %-9s %2d ",llista[i].nom,llista[i].curs);
		printf("   %c     %.2f\n",llista[i].grup,llista[i].mitjana);
        }else {
        	printf("\nAlumne no trobat\n");
        }
	scanf("%*c");
}

void esborra_alumne(alumne llista[MAX_LLISTA])
{
        int i,j;
        char esborra, nom[MAX_NOM];

        printf("\nEscriu el nom a esborrar: ");
	scanf("%9[^\n]%*c",(char*)&nom);
	i=0;
	while (i<elements-1 & strcmp(nom,llista[i].nom)!=0)
	        i++;
	if (strcmp(nom,llista[i].nom)==0){
        	printf("\n  %-9s %2d ",llista[i].nom,llista[i].curs);
		printf("   %c     %.2f\n",llista[i].grup,llista[i].mitjana);
		printf("El voleu esborrar [s/n]: ");
		scanf("%c%*c",&esborra);
		if (esborra =='S' || esborra=='s'){
		        for(j=i+1;j<elements;j++)
			        llista[j-1]=llista[j];
			elements--;
        		printf("\nAlumne esborrat\n");
		}
	}else {
	        printf("\nAlumne no trobat\n");
	}
	scanf("%*c");
		
		
}
void main()
{
        alumne llista [MAX_LLISTA];
        char opcio;
        int i,j;
	char esborra;
	char nom[MAX_NOM];

	elements=0;

	do{
                // Escriptura del menú. La opció es llegeix a aquella funció.
	        opcio=menu(opcio);
		switch (opcio) {
		case 'A':
		case 'a':
                        introduir_alumne(llista);
                        break;
		case 'B':
		case 'b': 
                        llistar_alumnes(llista);
			break;
			
                case 'C':
		case 'c': 
                        cercar_alumnes(llista);
			break;
		case 'D':
		case 'd':
                        esborra_alumne(llista);
			break;

		case 'E':
		case 'e':  // Sortir
			printf("Gràcies per utilitzar el nostre programari!\n");
			scanf("%*c");
			system("clear");		
			break;

		default : printf("\n  Opció incorrecta "); 
		}
	}while (opcio!='e' && opcio!='E');
}
