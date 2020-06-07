// Written by Jake Pratt
// 2020 April 12
// CS133U
// Professor Goble

// Sources:
// KN King's C Programming, A Modern Approach 2nd Edition.
// https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
// https://stackoverflow.com/questions/1190870/i-need-to-generate-random-numbers-in-c

/*
For this assignment, you should exercise dynamic memory allocation using malloc and then free the
memory after it has been utilized. The assignment is to create a mathematics addition quiz which is
expandable to as many questions as the user inputs.
Write a program that:
1. Prompts the user to enter number of questions required in the quiz.
2. Generates a quiz which has as many questions as the user entered in (1) above.
3. Allocates exactly the right amount of memory dynamically (i.e. using malloc) as follows:
1. Two arrays – one for the first operand and one for the second.
2. You should use the rand() function to generate random numbers in the range 1 – 99 for
each of the operands. Here is a video tutorial to generate random dice numbers (1-6). You
should be able to adapt this to generate random number in the range 1-99.
3. Fill both operands array with random 2 digit numbers. Here is a video tutorial to fill an array
with random numbers.
4. Create an additional array using malloc to store the answer the user enters for each question
presented.
5. Create another dynamic array to store the correct calculated answer. This is used to check the
user's answer.
6. In total, you will have 4 dynamically created arrays of the size the user entered in response to
(1) above.
7. When the user has answered all the questions in the quiz, your program should present the
result.
8. Don't forget to free all dynamically allocated memory
Submit a single file named quiz.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

    // Prompt user the number of questions
    int n;
    int wrong = 0;
    printf("Addition Quiz \n\n");
    printf("Enter number of problems you want to attempt: ");
    scanf("%d", &n);

    // Declare arrays and allocate memory.
    int *op1, *op2, *sums, *answers;

    op1 = calloc(n, sizeof(int));
    op2 = calloc(n, sizeof(int));
    sums = calloc(n, sizeof(int));
    answers = calloc(n, sizeof(int));

    // Fill the first 2 with random numbers ranging 1-99
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        op1[i] = (rand() % 89) + 10;
        //printf("%d \n", op1[i]);
    }

    for(int i = 0; i < n; i++){
        op2[i] = (rand() % 89 ) + 10;
    }

    // Fill the third with the sums of the indicies of the first two.
    for(int i = 0; i < n; i++){
        sums[i] = op1[i] + op2[i];
    }
    // Prompt the user for the sums and store the answers in the fourth.
    for(int i = 0; i < n; i++){
        printf("\n%d + %d = ", op1[i], op2[i]);
        scanf(" %d", &answers[i]);
        //printf(" \n");
    }

    // Compare the third an fourth arrays to determine the score.
    printf("\nQuiz Results \n\n");
    printf("Question \tYour Answer \t Correct\n");
    for(int i = 0; i < n; i++){
            printf("%d + %d \t %d", op1[i], op2[i], answers[i]);
            if(answers[i] == sums[i]){
                printf("\t\t Yes\n");
            }
            else{
                printf("\t\t No\n");
                wrong++;
            }

    }
    // Print the results.
    float score = ((n-wrong)/n)*100;
    printf("Score = %f", score);
    printf("================================================== \n");
    printf("Your scorecard is %d / %d -> %0.2f % \n", n - wrong, n, score);
    printf("================================================== \n");


    // Free the memory.
    free(op1);
    free(op2);
    free(sums);
    free(answers);

    return 0;
}
