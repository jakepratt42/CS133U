// Written by: Jake Pratt
// 2020 June 6
// Professor Colin Goble
// CS133U
// Lab 10

/*
Write a C program that reads a series of phone numbers from a file and displays them in a standard
format.
The first thing your program should do is prompt the user to enter the full pathname of the data file on
disk. Alternatively, you can pass this as a command line argument if you prefer.
Each line of the file will contain a single phone number, but the numbers may be in a variety of
formats. However, you may assume that each line contains 10 digits, possibly mixed with other
characters (which should be ignored).
*/

// Sources:
// KN King's C Programming, A Modern Approach 2nd Edition.
// https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

#include<stdio.h>
#include<stdlib.h>
#define N 15

int main(void)
{

    FILE *in_file;
    char line [N];
    char phoneNum[10];
    //char file[500];
    char file[500] = "C:\\Users\\Jake\\Documents\\CS133U\\CFiles\\Lab10\\numbers.txt";
    /*
    printf("Please Enter File Path & Name: \n");
    scanf("%s", file);
    */
    in_file = fopen(file, "r");
    if (in_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }

    while(fgets(line, N - 1, in_file) != NULL)  // I think i just need to have one loop read until EoL, and the outer read till EoF.
    {
        //fscanf(in_file, "%s", &line);
        //printf("%s \n", line);
        for(int i = 0, j = 0; i <= 14; i++)
        {
            //printf("Loop #: %d \n", i);
            if(line[i]>= '0' && line[i] <= '9')
            {
                phoneNum[j] = line[i];
                j++;
            }
        }
        printf("(%c%c%c) %c%c%c-%c%c%c%c \n", phoneNum[0], phoneNum[1], phoneNum[2], phoneNum[3], phoneNum[4], phoneNum[5], phoneNum[6], phoneNum[7], phoneNum[8], phoneNum[9]);
    }
    //fscanf(in_file, "%1d", &number2);
    //sum = number1 + number2;
    //printf("Sum of numbers %d and %d is %d \n", number1, number2, sum);

    //fgets(line, 15, in_file);
    //printf("%s \n", line);

    fclose(in_file);

    return 0;
}
