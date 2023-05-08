// structs
typedef struct Animal {
    char name[40];
    int age;
    char species[20];
    struct Animal *next;
} Animal;

typedef struct Exhibit {
    char name[40];
    int capacity;
    struct Exhibit *next;
    struct Animal *animal_head;
} Exhibit;

// exhibit funcs

void print_exhibits(Exhibit* head);

Exhibit* create_new_exhibit(char name[], int capacity);

void insert_exhibit_at_front(Exhibit** head, Exhibit* e);

void delete_exhibit(Exhibit** head, char name[]);

void delete_all(Exhibit** head);

// animal funcs

void insert_animal_at_front(Exhibit** head, char name[], Animal* new);

Animal* create_new_animal(char name[], int age, char species[]);

void print_animals(Animal* head);

void delete_animal(Exhibit* head, char name[], char animal_name[]);
