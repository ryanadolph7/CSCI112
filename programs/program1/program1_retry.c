#include <stdio.h>
#include <string.h>



void write_data(char data[][150], int size) {
    
    FILE *out_fp; 
    out_fp = fopen("winners.txt", "w");

    char *first_name[47][150], *sir_name[47][150], *born_country[47][150], *year[47][150], *category[47][150], *university[47][150], *city_of_uni[47][150], *age_got_prize[47][150];   


    for(int k = 0; k < size; k++) {
        // tokens for differnt data in the lines        
    
        *first_name[k] = strtok(data[k], ",");
        *sir_name[k] = strtok(NULL, ",");
        *born_country[k] = strtok(NULL, ",");
        *year[k] = strtok(NULL, ",");
        *category[k] = strtok(NULL, ",");
        *university[k] = strtok(NULL, ",");
        *city_of_uni[k] = strtok(NULL, ",");
        *age_got_prize[k] = strtok(NULL, ",");
    }

    for(int i = 1; i < size; i++) {
        fprintf(out_fp, "%d: %s %s from %s won when they were %s.",i, *first_name[i], *sir_name[i], *university[i], *age_got_prize[i]); 
    }

    fclose(out_fp);
    
}

void sort_list(char data[][150], char data_copy[][150], int max_size) {

    // tokens for differnet data in the lines

    char *first_name[47][150];

    // tokenizing
    for(int k = 0; k < max_size; k++) {
    
        *first_name[k] = strtok(data[k], ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
    }
   
   

   // selection sort algo
   int i, j, min_pos;
   for(i = 1; i < max_size - 1; i++){
        min_pos = i; 
        for(j = i + 1; j < max_size; j++) {
            // compare the first names of each person
            if( strcmp(*first_name[j], *first_name[min_pos]) < 0) {
                min_pos = j;
            }
        }
        // if the first name is less than the the other, than switch the first name indexs' 
        // and switch the data_copy indexs to match
        // this was just the way I figured out and committed to, there are probably a ton
        // of easier ways to do this.
        if(min_pos != i) {

            // switching first_name data
            char name_temp[150];
            strcpy(name_temp, *first_name[min_pos]);
            strcpy(*first_name[min_pos], *first_name[i]);
            strcpy(*first_name[i], name_temp);

            // switching data_array
            char data_temp[150];
            strcpy(data_temp, data_copy[min_pos]);
            strcpy(data_copy[min_pos], data_copy[i]);
            strcpy(data_copy[i], data_temp);
        } 

   }
   write_data(data_copy, max_size); 
}




int main(void) {
    int ROW = 47;
    int COL = 150;
    
    
    char data[ROW][COL];
    char data_copy[ROW][COL];

    FILE *fp;
    fp = fopen("/public/programs/program1/nobel.csv", "r");
    
    if(fp == NULL) {
        printf("Error entering the file.\n");
        return(1);
    }

    for(int i = 0; i < ROW; i++) {
        while( fgets(data[i], COL, fp) != NULL) {
            strcpy(data_copy[i], data[i]);
            i++;
        }
        
    }
    
    fclose(fp);
    
    sort_list(data, data_copy, ROW);

    return(0);    
}
