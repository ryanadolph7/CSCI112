#include <stdio.h>
#include <stdbool.h>


int within_x_percent(double ref, double data, double percent);

int main(void) {
    double data;
    double percent = 5.0;
    char ans;
    double new_percent;

    // assinging each substance its own reference variable 

    double ref_water = 100.0;
    double ref_mercury = 357.0;
    double ref_copper = 1187.0;
    double ref_silver = 2193.0;
    double ref_gold = 2660.0;



    printf("Observed boiling point (in deg. C)? ");
    scanf(" %lf", &data); // setting data to the users observerd boiling point 
    printf("You entered %.2lf\n", data);
    printf("Custom error percent? n for no (5%% default), y for yes: "); // asking for custom error percent
    scanf(" %c", &ans);

    // switch statement to check if the user wants to input a custom error percent 
    // if yes, then it asks them for the percnet 
    // if no, then it breaks and goes to the next if statement to
    // check the substance
    // if user inputs anything other than 'n', 'N', 'y', 'Y' then the switch statement returns
    // false, terminating the program and telling the user bad input

    switch(ans) {
        case 'y':
            printf("Enter error percent: ");
            scanf("%lf", &new_percent);
            percent = new_percent;
            printf("You entered %.2lf percent\n", percent);
            break;
        case 'Y':
            printf("Enter error percent: ");
            scanf("%lf", &new_percent);
            percent = new_percent;
            printf("You entered %.2lf percent\n", percent);
            break;
        case 'n':
            break;
        case 'N':
            break;
        default:
            printf("Error; bad input\n");
            return(1);
    }

    

    // using a loop to check if the funciton returns true
    // if true, then we know what the substance is
    // then the substance is printed in the terminal
    
    if(within_x_percent(ref_water, data, percent) == true) { 
        printf("Substance is water\n"); 
    } else if(within_x_percent(ref_mercury, data, percent) == true) {
        printf("Substance is mercury\n");
    } else if(within_x_percent(ref_copper, data, percent) == true) {
        printf("Substance is copper\n");
    } else if(within_x_percent(ref_silver, data, percent) == true) {
        printf("Substance is silver\n");
    } else if(within_x_percent(ref_gold, data, percent) == true) {
        printf("Substance is gold\n");
    } else {
        printf("Substance unkown\n");
    }

    

    return(0);
}


// function to check if the observed boiling point is within x percent 

int within_x_percent(double ref, double data, double percent) {
    if((data <= ref + (ref * (percent / 100))) && (data >= ref - (ref * (percent / 100)))) {
        return(1);
    }  
    return(0);
}
