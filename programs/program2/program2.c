#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main(void) {

    int choice = 0;

    while(choice != 6) {
        Exhibit* start = NULL;
        Animal* a_start = NULL;

        printf("Menu\n");
        printf("1 - Create new zoo\n");
        printf("2 - Add exhibit\n");
        printf("3 - Add animal\n");
        printf("4 - Remove animal\n");
        printf("5 - Remove exhibit\n");
        printf("6 - Exit\n");
        printf("Enter choice: ");
        scanf(" %d", &choice);

        
        
        switch(choice) {
            case 1: // create a new zoo 
                int exhibit_num = 0;
                printf("How many exhibits would you like to start with? > ");
                scanf("%d", &exhibit_num);
                for(int i = 0; i < exhibit_num; i++) {
                   char name[20];
                   int capacity = 0;
                   printf("Enter exhibit name > ");
                   scanf(" %s", name);
                   printf("Enter exhibit capacity > ");
                   scanf(" %d", &capacity);
                   insert_exhibit_at_front(&start, create_new_exhibit(name, capacity)); 
                }
                break;
            case 2: // add new exhibit
                char name[20];
                int capacity = 0;
                printf("Enter exhibit name > ");
                scanf(" %s", name);
                printf("Enter exhibit capacity > ");
                scanf(" %s", &capacity);
                insert_exhibit_at_front(&start, create_new_exhibit(name, capacity));
                print_animals(&a_start);
                break;
            case 3: // add a new animal 
                char animal_name[20];
                char species[15];
                char exhibit[25];
                int age;
                printf("Enter animal name > ");
                scanf("%s", animal_name);
                printf("Enter animal age > ");
                scanf("%d", &age);
                printf("Enter animal species > ");
                scanf("%s", species);
                printf("Enter animal's exhibit > ");
                scanf("%s", exhibit);
                insert_animal_at_front(&start, exhibit, create_new_animal(animal_name, age, species));  
                break;
            case 4: // delete an animal
                char a_name[20];
                char exhibit_name[20];
                printf("Enter animal name > ");
                scanf(" %s", name);
                printf("Enter exhibit name > ");
                scanf(" %s", exhibit_name);
                delete_animal(&start, exhibit_name, a_name);
                break;
            case 5: // remove an exhibit  
                char e_name[20];
               printf("Enter exhibit name > "); 
               scanf(" %s", e_name);
               delete_exhibit(&start, e_name);
               break;
            case 6: // exit
                return -1;
                break;
            default:
                
                printf("Menu\n");
                printf("1 - Create new zoo\n");
                printf("2 - Add exhibit\n");
                printf("3 - Add animal\n");
                printf("4 - Remove animal\n");
                printf("5 - Remove exhibit\n");
                printf("6 - Exit\n");
                printf("Enter choice: ");
                scanf(" %d", &choice);
                
        }


    }
    


    return(0);
}   
