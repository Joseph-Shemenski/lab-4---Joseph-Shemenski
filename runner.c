#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char file_name [100];  // character array to hold file name
FILE *file_ptr;        // pointer used to access file
int sum_total;         // int used to hold the total result

int array_size[1];     // integer used to hold the size of the txt file
extern int sum_up(int*, int);   //function that is defined in assembly

int main(){
    printf("Enter a file name: \n");
    fgets(file_name, 100, stdin);
    file_ptr = fopen(file_name, "r");
    if(file_ptr == NULL){       // checks that to see if the file exist and is valid
        printf("The file is invalid \n");
    }
    else{
        fscanf(file_ptr, "%d", array_size);
        int size = array_size[0];  // integer to hold the size 
        int number_array[array_size[0]];  // array to hold each integer as it is scanned from txt file
        int numbers[size];                // array that actually holds integers and will be accessed in assembly
        int counter = 0;                  // counter to access the number array
        while(fscanf(file_ptr, "%d", number_array) == 1){
            numbers[counter] = *number_array;
            counter += 1;
            
        }
        fclose(file_ptr);
        
        sum_total = sum_up(numbers, size);
        printf("The sum is: ");
        printf("%d\n", sum_total);
    }
    return 0;
}