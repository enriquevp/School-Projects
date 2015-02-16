
/*Included libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Constants */
#define MAX_NAME 16
#define MAX_TEL 10
#define MAX 50

/*Structs*/
struct contact
{
	char name[MAX_NAME];
	char tel[MAX_TEL];
};

/*Global variables*/
int elements;

/*Functions*/
void insert_contact(struct contact *a)
{
        int i = 0,j;
        struct contact con;

        if (elements < MAX){
                printf("\nInput name: ");
                scanf("%[^\n]", (char*)&con.name);

                printf("\nInput telephone: ");
                scanf("%s", (char*)&con.tel);
                while (i < elements && strcmp(con.name, (a + i)->name) > 0)
                        i++;

                for (j=elements;j>i;j--)
                        a[j] = a[j - 1];
                a[i] = con;
                elements++;
        }else {
                printf("Agenda is full, no more rows allowed.\n");
        }
}

void list_contacts(struct contact *a)
{
        int i = 0;
        if (elements == 0){
                printf("Agenda is empty.\n");
        }else {
                printf("\nName\t\tTelephone\n");
                printf("=======================\n");
                for (i = 0;i < elements;i++)
                        printf("%s\t%-9s\n",(a + i)->name,(a + i)->tel);
        }

}

void search_contact(struct contact *a)
{
        int i = 0;
        char name[MAX_NAME];

        printf("\nInput contact to search: ");
        scanf("%[^\n]%*c", (char*)&name);

       while (i < elements-1 && strcmp(name,(a + i)->name) != 0)
                i++;
        if (strcmp (name, (a + i)->name) == 0)
                printf("\n %-15s%9s\n",(a + i)->name,(a + i)->tel);
        else
                printf("\nContact not found.");
}

void delete_contact(struct contact *a)
{
        int i = 0, j = 0;
        char delete;
        char name[MAX_NAME];

        printf("\nInput contact name to delete: ");
        scanf("%[^\n]%*c",(char*)&name);

        while (i < elements-1 && strcmp(name,(a + i)->name) != 0)
                i++;
        if (strcmp(name, (a + i)->name) == 0){
                printf("\n %-15s%9s\n",(a + i)->name,(a + i)->tel);
                printf("Wanna delete this contact? [y/n]");
                scanf("%c",&delete);

                if (delete  == 'Y' || delete == 'y'){
                for (j = i + 1;j < elements;j++)
                        a[j - 1] = a[j];

                elements--;
                printf("\nContact deleted.");
                scanf("%*c");
                }
        }else
                printf("\nContact not found.");
}

int main()
{
        char option,delete;
        int i = 0, j = 0;
        struct contact *agenda = malloc(MAX * sizeof(*agenda));

        elements = 0;
        do {
		system("clear");
		printf("\tAGENDA\n");
		printf("a) Enter Contact \n");
		printf("b) List Contacts \n");
		printf("c) Search Contact \n");
		printf("d) Delete Contact\n");
		printf("e) Exit \n");
		printf("Choose an option: ");
	  	scanf("%c%*c",&option);

		switch (option){
		case 'a':
		case 'A':
                        insert_contact(agenda);
                        break;

                case 'b':
                case 'B':
                        list_contacts(agenda);
		        break;

		case 'c':
		case 'C':
		        search_contact(agenda);
			break;

		case 'd':
                case 'D':
		        delete_contact(agenda);
			break;

		case 'e':
		case 'E':
			printf("\nGoodbye!");
			break;

		    default:
                    printf("\nOption not allowed.");
		}

		scanf("%*c");
        }while (option != 'e' && option != 'E');

        free(agenda);
}
