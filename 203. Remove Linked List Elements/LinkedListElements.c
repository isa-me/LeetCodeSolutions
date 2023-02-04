#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val);
struct ListNode* array_2_list(int arr[], int N);
void print(struct ListNode* head);
int main()
{
    int testCase1[7] = {1,2,6,3,4,5,6};
    int testCase2[7] = {};
    int testCase3[4] = {7,7,7,7};
    struct ListNode* list1 = array_2_list(testCase1,7);
    struct ListNode* list2 = array_2_list(testCase2,7);
    struct ListNode* list3 = array_2_list(testCase3,4);
    printf("Before removing 6: ");
    print(list1);
    printf("\n\nBefore removing 1: ");
    print(list2);
    printf("\n\nBefore removing 7: ");
    print(list3);
    printf("\n\n");
    list1 = removeElements(list1, 6);
    list2 = removeElements(list2, 1);
    list3 = removeElements(list3, 7);
    printf("After removing 6: ");
    print(list1);
    printf("\n\nAfter removing 1: ");
    print(list2);
    printf("\n\nAfter removing 7: ");
    print(list3);
    printf("\n\n");
    return 0;
}
void print(struct ListNode* head)
{
    struct ListNode* current_node = head;
   	while ( current_node != NULL)
    {
        printf("%d ", current_node->val);
        current_node = current_node->next;
    }
}
struct ListNode* array_2_list(int arr[], int N)
{
    int j;
    struct ListNode* lastP = NULL;
    struct ListNode* newP = NULL;
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->val = arr[0];
    L->next = NULL;
    lastP = L;
    for (j = 1; j<N; j++)
    {
        newP = (struct ListNode*)malloc(sizeof(struct ListNode));
        newP->val = arr[j];
        newP->next = NULL;
        lastP->next = newP;
        lastP = newP;
    }
    return L;
}
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        if(prev==NULL && curr->val == val)
        {
            head = next;
            curr->next = NULL;
            curr = head;
        }
        else
        {
            if(curr->val == val)
            {
                curr->next = NULL;
                prev->next = next;
                curr = next;
            }
            else
            {
                prev = curr;
                curr = next;
            }
        }
    }
    return head;
}