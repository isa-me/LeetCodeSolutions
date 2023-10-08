#include <stdio.h>
#include <stdlib.h>
typedef struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
} Node;
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
void appendList(Node* head, Node* node){
    Node* curr = head;
    Node* prev = NULL; 
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = node;
}
int hashFunction(int key, int tablesize){
    return key%tablesize;
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
int main(){
    //_____________________________________________________________________________
    //-----------------------Testing the print list function-----------------------
    /*Node node1, node2, node3, node4;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    node1.key = 1;
    node2.key = 2;
    node3.key = 3;
    node4.key = 4;
    node1.value = 0;
    node2.value = 1;
    node3.value = 2;
    node4.value = 3;
    printList(&node1);
    printf("\n");*/
    //_____________________________________________________________________________
    //_____________________________________________________________________________
    //-----------------------Testing the print table function----------------------
    /*Node node1, node2, node3, node4;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    node1.key = 1;
    node2.key = 2;
    node3.key = 3;
    node4.key = 4;
    node1.value = 0;
    node2.value = 1;
    node3.value = 2;
    node4.value = 3;

    int numsSize = 4;
    Node** hashtable = calloc(numsSize, sizeof(Node*));
    hashtable[1] = &node1;
    hashtable[3] = &node3;
    printTable(hashtable,numsSize);
    printf("\n");
    free(hashtable);
    */
    //_____________________________________________________________________________
    //_____________________________________________________________________________
    //-----------------------Testing the append list function----------------------
    /*Node node1, node2, node3, node4, node5;
    node1.next = NULL;
    node2.next = NULL;
    node3.next = NULL;
    node4.next = NULL;
    node1.key = 1;
    node2.key = 2;
    node3.key = 3;
    node4.key = 4;
    node1.value = 0;
    node2.value = 1;
    node3.value = 2;
    node4.value = 3;

    //node5.next = NULL;
    //node5.key = 5;
    //node5.value = 4;

    appendList(&node1, &node2);
    appendList(&node2, &node3);
    appendList(&node3, &node4);
    printList(&node1);
    printf("\n");*/
    //_____________________________________________________________________________
    //_____________________________________________________________________________
    //-----------------------Testing the print table function----------------------
    int target = 9;
    int numsSize = 4;
    int* nums = calloc(numsSize, sizeof(int));
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;

    Node** hashtable = calloc(numsSize, sizeof(Node*));
    for(int i=0; i<numsSize; i++){
        Node* n = createHashNode(nums[i],i,NULL);
        n->key = nums[i];
        n->value = i;
        n->next = NULL;
        hashAdd(n,hashtable,numsSize);
    }
    printTable(hashtable,numsSize);
    printf("\n");
    free(nums);
    freeHashTable(hashtable,numsSize);
    //_____________________________________________________________________________
    return 0;
}