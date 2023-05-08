#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"


Exhibit *create_new_exhibit(char name[], int capacity) {
    
    Exhibit* result = malloc(sizeof(Exhibit));
    strcpy(result->name, name);
    result->capacity = capacity;
    result->next = NULL;

    return result;
}

void insert_exhibit_at_front(Exhibit** head, Exhibit* new) {
    new->next = *head;
    *head = new;
}

void print_exhibits(Exhibit* head) {
    Exhibit* temp = head;

    while(temp != NULL) {
        printf("%s->", temp->name);
        temp = temp->next;
    }
    printf("\n");
}


void delete_exhibit(Exhibit** head, char name[]) {
    Exhibit* temp = *head;
    Exhibit* to_free;
    if(temp == NULL) {
        return;
    } else if(strcmp(temp->name, name) == 0) {
        // the first one is the one we need to delete
        *head = temp->next;
        free(temp);
    } else {
        while(temp->next != NULL) {
            if(strcmp(temp->next->name, name) == 0) {
                // next one is the one to delete
                to_free = temp->next;
                temp->next = temp->next->next;
                free(to_free);
                return;
            }
            temp = temp->next; // move to next node
        }

    }

}


void delete_all(Exhibit** head) {
    Exhibit* temp;

    while(*head != NULL) {
        temp = *head;
        // move forward one
        *head = (*head)->next;
        // free the original head
        free(temp);
    }
}


void insert_animal_at_front(Exhibit** head, char name[], Animal* new) {

   Exhibit* temp = *head;
   if(temp == NULL) {
        return;
   } else {
        if(strcmp(temp->name, name) == 0) {
            temp->animal_head->next = new;
        }
   }
   
}


Animal* create_new_animal(char name[], int age, char species[]) {
    Animal* result = malloc(sizeof(Animal));
    strcpy(result->name, name);
    strcpy(result->species, species);
    result->age = age;
    result->next = NULL;
    return result;
}

void delete_animal(Exhibit* head, char name[], char animal_name[]) {
    Exhibit* temp = head;
    Animal* a_temp = temp->animal_head;
    Animal* to_free;
    if(temp == NULL) {
        return;
    } else if(strcmp(temp->name, name) == 0) {
        // the animal is in the first exhibit
        if(strcmp(temp->animal_head->name, animal_name) == 0) {
            to_free = temp->animal_head;
            temp->animal_head = temp->animal_head->next;
            free(to_free);
            return;
        }
        
    } else {
        while(temp != NULL) {
            if(strcmp(temp->animal_head->next->name, animal_name) == 0) {
                // next one is to free
                to_free = temp->animal_head->next;
                temp->animal_head->next = temp->animal_head->next->next;
                free(to_free);
                return;
            }

        }
    }
    
}


void print_animals(Animal* head) {
    Animal* temp = head;
    while(temp != NULL) {
        printf("%s->", temp->name);
        temp = temp->next; 
    }
    printf("\n");
}




