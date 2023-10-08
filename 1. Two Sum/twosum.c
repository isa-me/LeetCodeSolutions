#include <stdio.h>
#include <stdlib.h>
typedef struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
} Node;

void printArray(int* array, int n){
    printf("[");
    for(int i = 0; i<n; i++){
        if(i == n-1) printf("%d",array[i]);
        else
            printf("%d,",array[i]);
    }
    printf("]");
}
void printList(Node* head){
    Node* curr = head;
    Node* prev = NULL; 
    if(head == NULL) printf("(NULL)");
    else{
        while(curr != NULL){
            if(curr->next == NULL) printf("(%d)->(NULL)",curr->value);
            else printf("(%d)->",curr->value);
            prev = curr;
            curr = curr->next;
        }
    }
}
void printTable(Node** table, int size){
    for(int i=0; i<size; i++){
        printf("[%d]: ",i);
        printList(table[i]);
        printf("\n");
    }
}

int hashFunction(int key, int tablesize){
    return key%tablesize;
}
void appendList(Node* head, Node* node){
    Node* curr = head;
    Node* prev = NULL; 
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = node;
}
void hashAdd(Node* n, Node** table, int tablesize){
    int hashindex = hashFunction((n->key),tablesize);
    if(table[hashindex] == NULL) table[hashindex] = n;
    else appendList(table[hashindex],n);
}
Node* createHashNode(int key, int value, Node* next){
    Node* hn = calloc(1, sizeof(Node));
    hn->key = key;
    hn->value = value;
    hn->next = next;
    return hn;
}
void freeList(Node* head){
    Node* curr = head;
    Node* next = NULL; 
    while(curr != NULL){
        next = curr->next;
        free(curr); 
        curr = next;
    }
}
void freeHashTable(Node** table, int tablesize){
    for(int i=0; i<tablesize; i++){
        if(table[i]!=NULL){
            freeList(table[i]);
        }
    }
    free(table);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    /*int tmp;
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
    }*/
    *returnSize = 2;
    int* solution = calloc(2,sizeof(int));
    Node** hashtable = calloc(numsSize, sizeof(Node*));
    for(int i=0; i<numsSize; i++){
        Node* n = createHashNode(nums[i],i,NULL);
        hashAdd(n,hashtable,numsSize);
    }
    //printTable(hashtable,numsSize);
    //----------------------------------------------------------------------------
    freeHashTable(hashtable,numsSize);
    //----------------------------------------------------------------------------
    solution[0] = 0;
    solution[1] = 1;
    return solution;
}


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
    free(solution);
    free(nums);
    return 0;
}




















