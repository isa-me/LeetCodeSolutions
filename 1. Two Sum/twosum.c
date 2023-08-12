#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
void printArray(int* array, int n);
int main(){
    int numsSize = 4;
    int target = 9;
    int returnSize;
    int* nums = calloc(numsSize, sizeof(int));
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;
    int* solution = twoSum(nums, numsSize, target, &returnSize);
    printf("Input: nums = ");
    printArray(nums, 4);
    printf("\nTarget = %d\nSolution: ", target);
    printArray(solution, returnSize);
    printf("\n");
    free(solution);
    free(nums);

    return 0;
}

void printArray(int* array, int n){
    printf("[");
    for(int i = 0; i<n; i++){
        if(i == n-1) printf("%d",array[i]);
        else
            printf("%d,",array[i]);
    }
    printf("]");
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int tmp;
    *returnSize = 2;
    int* solution = calloc(2,sizeof(int));
    for(int i = 0; i<numsSize; i++){
        //if(nums[i]<=target){
            tmp = target - nums[i];
            for(int j = 0; j<numsSize; j++){
                if((tmp == nums[j]) && (i!=j)){
                    solution[0] = i;
                    solution[1] = j;
                }
            }
        //}
    }
    return solution;
}




















