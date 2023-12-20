#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//Elementary Math 
		//Time: O(max(m,n)) Space: O(1)
		ListNode dummy_head(0);
		auto cur = &dummy_head;
		auto carry = 0;

		while (l1 != nullptr || l2 != nullptr || carry != 0){
			auto l1_val = (l1 != nullptr) ? l1->val : 0;
			auto l2_val = (l2 != nullptr) ? l2->val : 0;
			auto sum = l1_val + l2_val + carry;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}

        return dummy_head.next;
    }
};


// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to compare two linked lists
bool compareLinkedLists(ListNode* list1, ListNode* list2) {
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val != list2->val) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == nullptr && list2 == nullptr;
}

int main() {
    Solution solution;

    // Test Case 1
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* expected1 = new ListNode(7, new ListNode(0, new ListNode(8)));
    ListNode* result1 = solution.addTwoNumbers(l1, l2);

    cout << "Test Case 1: ";
    printLinkedList(result1);
    cout << "Expected Result: ";
    printLinkedList(expected1);
    cout << "Match: " << (compareLinkedLists(result1, expected1) ? "true" : "false") << endl;

    // Test Case 2
    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(0);
    ListNode* expected2 = new ListNode(0);
    ListNode* result2 = solution.addTwoNumbers(l3, l4);

    cout << "Test Case 2: ";
    printLinkedList(result2);
    cout << "Expected Result: ";
    printLinkedList(expected2);
    cout << "Match: " << (compareLinkedLists(result2, expected2) ? "true" : "false") << endl;

    // Test Case 3
    ListNode* l5 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l6 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode* expected3 = new ListNode(8, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1))))))));
    ListNode* result3 = solution.addTwoNumbers(l5, l6);

    cout << "Test Case 3: ";
    printLinkedList(result3);
    cout << "Expected Result: ";
    printLinkedList(expected3);
    cout << "Match: " << (compareLinkedLists(result3, expected3) ? "true" : "false") << endl;

    return 0;
}