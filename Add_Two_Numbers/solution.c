#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//Elementary Math 
	//Time: O(max(m,n)) Space: O(1)
    struct ListNode dummy_head = {0};
    struct ListNode* cur = &dummy_head;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = sum % 10;
        cur->next = NULL;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    return dummy_head.next;
}


// Function to print the linked list
void printLinkedList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeLinkedList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to compare two linked lists
int compareLinkedList(struct ListNode* list1, struct ListNode* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->val != list2->val) {
            return 0; // Lists are not equal
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == NULL && list2 == NULL); // Lists are equal if both are NULL
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main() {
    // Test Case 1
    struct ListNode* l1_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_1->val = 2;
    l1_1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_1->next->val = 4;
    l1_1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_1->next->next->val = 3;
    l1_1->next->next->next = NULL;

    struct ListNode* l2_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_1->val = 5;
    l2_1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_1->next->val = 6;
    l2_1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_1->next->next->val = 4;
    l2_1->next->next->next = NULL;

    struct ListNode* expected_result1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result1->val = 7;
    expected_result1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result1->next->val = 0;
    expected_result1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result1->next->next->val = 8;
    expected_result1->next->next->next = NULL;

    struct ListNode* result1 = addTwoNumbers(l1_1, l2_1);
    printf("Test Case 1 Result: ");
    printLinkedList(result1);
    printf("Expected Result: ");
    printLinkedList(expected_result1);
    printf("Match: %s\n", compareLinkedList(result1, expected_result1) ? "true" : "false");

    freeLinkedList(l1_1);
    freeLinkedList(l2_1);
    freeLinkedList(expected_result1);
    freeLinkedList(result1);

    // Test Case 2
    struct ListNode* l1_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_2->val = 0;
    l1_2->next = NULL;

    struct ListNode* l2_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_2->val = 0;
    l2_2->next = NULL;

    struct ListNode* expected_result2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result2->val = 0;
    expected_result2->next = NULL;

    struct ListNode* result2 = addTwoNumbers(l1_2, l2_2);
    printf("Test Case 2 Result: ");
    printLinkedList(result2);
    printf("Expected Result: ");
    printLinkedList(expected_result2);
    printf("Match: %s\n", compareLinkedList(result2, expected_result2) ? "true" : "false");

    freeLinkedList(l1_2);
    freeLinkedList(l2_2);
    freeLinkedList(expected_result2);
    freeLinkedList(result2);

    // Test Case 3
    struct ListNode* l1_3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->val = 9;
    l1_3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->next->val = 9;
    l1_3->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->next->next->val = 9;
    l1_3->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->next->next->next->val = 9;
    l1_3->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->next->next->next->next->val = 9;
    l1_3->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->next->next->next->next->next->val = 9;
    l1_3->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3->next->next->next->next->next->next->val = 9;
    l1_3->next->next->next->next->next->next->next = NULL;

    struct ListNode* l2_3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_3->val = 9;
    l2_3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_3->next->val = 9;
    l2_3->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_3->next->next->val = 9;
    l2_3->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_3->next->next->next->val = 9;
    l2_3->next->next->next->next = NULL;

    struct ListNode* expected_result3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->val = 8;
    expected_result3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->val = 9;
    expected_result3->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->next->val = 9;
    expected_result3->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->next->next->val = 9;
    expected_result3->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->next->next->next->val = 0;
    expected_result3->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->next->next->next->next->val = 0;
    expected_result3->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->next->next->next->next->next->val = 0;
    expected_result3->next->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    expected_result3->next->next->next->next->next->next->next->val = 1;
    expected_result3->next->next->next->next->next->next->next->next = NULL;

    struct ListNode* result3 = addTwoNumbers(l1_3, l2_3);
    printf("Test Case 3 Result: ");
    printLinkedList(result3);
    printf("Expected Result: ");
    printLinkedList(expected_result3);
    printf("Match: %s\n", compareLinkedList(result3, expected_result3) ? "true" : "false");

    freeLinkedList(l1_3);
    freeLinkedList(l2_3);
    freeLinkedList(expected_result3);
    freeLinkedList(result3);

    return 0;
}
