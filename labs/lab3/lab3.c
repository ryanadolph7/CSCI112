#include <stdio.h>

double get_grade(char *test_answers, char *student_answers);


int main(void) {


    int questions;
    while (scanf("%d", &questions) == 1) { // scans amount of questions
        
    }
    printf("Questions:     ");
    for(int i = 1; i <= questions; i++) {
        printf("  %d", i);
    }
    printf("\n\n"); // add new line to 

    char test_answers[8]; // scan in test answers
    for(int i = 0; i < questions; i++) {
        while (scanf("%c", &test_answers[i]) == ' ') {
        }
    }

    printf("Answers:       "); // print test answers
    for(int i = 0; i < questions; i++) {
        printf("  %c", test_answers[i]);
    }
    printf("\n\n");

    int student1; // scan student1 ID
    while (scanf("%d", &student1) == 1) {
    }

    char student1_answers[8]; // put student1 test answers into array
    for(int i = 0; i < questions; i++) {
        while(scanf("%c", &student1_answers[i]) == ' ') {
        }
    }
    
    int student2; // scan student2 ID
    while (scanf("%d", &student2) == 1) {
    }

    char student2_answers[8]; // scan student2 answers
    for(int i = 0; i < questions; i++) {
        while(scanf("%c", &student2_answers[i]) == ' ') {
        }
    }


    int student3; // scan student3 ID
    while(scanf("%d", &student3) == 1) {
    }
    
    char student3_answers[8]; // scan student3 answers
    for(int i = 0; i < questions; i++) {
        while(scanf("%c", &student3_answers[i]) == ' ') {
        }
    }

    int student4; // scan student4 ID
    while(scanf("%d", &student4) == 1) {
    }

    char student4_answers[8]; // scan student4 answers
    for(int i = 0; i < questions; i++) {
        while(scanf("%c", &student4_answers[i]) == ' ') {
        }
    }

    int student5; // scan student5 ID
    while(scanf("%d", &student5) == 1) {
    }

    char student5_answers[8]; // scan student5 answers
    for(int i = 0; i < questions; i++) {
        while(scanf("%c", &student5_answers[i]) == ' ') {
        }
    }

    double grade1 = get_grade(test_answers, student1_answers); // get_grade function for each student
    double grade2 = get_grade(test_answers, student2_answers);
    double grade3 = get_grade(test_answers, student3_answers);
    double grade4 = get_grade(test_answers, student4_answers);
    double grade5 = get_grade(test_answers, student5_answers);


    printf("ID\tGrade(%%)\n");

    

    printf("%d\t%.2lf\n", student1, grade1);

    printf("%d\t%.2lf\n", student2, grade2);

    printf("%d\t%.2lf\n", student3, grade3);

    printf("%d\t%.2lf\n", student4, grade4);

    printf("%d\t%.2lf\n\n", student5, grade5);
    
    printf("Questions:     ");
    for(int i = 1; i <= questions; i++) {
        printf("  %d", i);
    }
    printf("\n"); 
    printf("Missed by:     ");
   
    int missed[8];

    for(int i = 0; i < 8; i++) {
        if(test_answers[i] == student1_answers[i]) {
        } else if(test_answers[i] == student2_answers[i]) {
        } else if(test_answers[i] == student3_answers[i]) {
        } else if(test_answers[i] == student4_answers[i]) {
        } else if(test_answers[i] == student5_answers[i]) {
        } else {
            missed[i] += 1;
        }
    }

    for(int i = 0; i < 8; i++) {
        printf("  %d", missed[i]);
    }
    printf("\n");


    return(0);
}


double get_grade(char *test_answers, char *student_answers) {
    double grade = 0.0;

    for(int i = 0; i < 8; i++) {
        if(student_answers[i] == test_answers[i]) {
            grade += 1;
        } 
    }
    grade = (grade/8.0) * 100.0;

    return(grade);
}







