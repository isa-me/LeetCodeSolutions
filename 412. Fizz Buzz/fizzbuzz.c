#include <stdio.h>
#include <stdlib.h>
void printStringArray(int n, char** array);
void clearAllocated2DArray(int n, char** array);
int howManyDigits(int num);
char ** fizzBuzz(int n, int* returnSize);
int main()
{
    int input = 15;
    int returnSize;
    char** fbsolution = fizzBuzz(input, &returnSize);
    printf("Input: %d\nArray:\n",input);
    printStringArray(returnSize, fbsolution);
    clearAllocated2DArray(returnSize, fbsolution);
    //free(fbsolution);
    return 0;
}
void printStringArray(int n, char** array){
    for(int i=0; i<n; i++){
        printf("%s,\n",array[i]);
    }
}
void clearAllocated2DArray(int n, char** array){
    for(int i=0; i<n; i++){
        if(((i+1)%3 != 0) && ((i+1)%5 != 0)) free(array[i]);
    }
    free(array);
}
int howManyDigits(int num){
    int digits;
    digits = 1;
    while(num != 0){
        num = num/10;
        digits ++;
    }
    return digits;
}
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    int digit_size = howManyDigits(n);
    char** answer = calloc(n, sizeof(char*));
    for(int i=0; i<n; i++){
        if(((i+1)%3 == 0) && ((i+1)%5 == 0)){
            answer[i] = "FizzBuzz";
        }
        else if((i+1)%3 == 0){
            answer[i] = "Fizz";
        }
        else if((i+1)%5 == 0){
            answer[i] = "Buzz";
        }
        else{
            answer[i] = calloc(digit_size+1, sizeof(char));
            sprintf(answer[i],"%d",i+1);
        }
    }
    return answer;
}  