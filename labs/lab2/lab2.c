#include <stdio.h>
#include <string.h>

int main(void) {

    char high_days[50];
    char pleasant_days[50];
    char cold_days[50];
    char symbol = '*';

    int input;
    double average;


    printf("Enter a high temp reading (-99 to quit)> \n");
    scanf(" %d", &input);
    while(input != -99) {
    average += input;
         if(input >= 85){
             strncat(high_days, &symbol, 1);
         } else if(input < 85 && input >= 60) {
             strncat(pleasant_days, &symbol, 1);
         } else if(input < 60) {
             strncat(cold_days, &symbol, 1);
         } else if(input == -99) {
             return(1);
         }
    printf("Enter a high temp reading (-99 to quit)> \n");
    scanf(" %d", &input);
   }
  
    // I got a C certificate through codecademy over the winter 
    // thats how I know of the strlen function and strncat function 
    average = average / (strlen(high_days) + strlen(pleasant_days) + strlen(cold_days));

    printf("\n"); // newline characters are just for formatting the output 
                  // to have space between the users high temp input and the output

    printf("Hot days:\t %s\n", high_days);
    printf("Pleasant days:\t %s\n", pleasant_days);
    printf("Cold days:\t %s\n", cold_days);
    printf("Avreage temperature: %.1lf\n", average);
    

    return(0);
}
