from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """ Elementary Math Time: O(max(m,n)) Space: O(1)"""
        dummy_head = ListNode(0)
        cur = dummy_head
        carry = 0

        while l1 != None or l2 != None or carry != 0:
            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0
            column_sum = l1_val + l2_val + carry
            carry = column_sum // 10
            new_node = ListNode(column_sum % 10)
            cur.next = new_node
            cur = new_node
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy_head.next

        

    
# Function to convert a list to a ListNode
def list_to_linked_list(lst):
    dummy_head = ListNode(0)
    current = dummy_head
    for val in lst:
        current.next = ListNode(val)
        current = current.next
    return dummy_head.next

# Function to convert a ListNode to a list
def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

# Test cases
def run_test(input1, input2, expected_output):
    l1 = list_to_linked_list(input1)
    l2 = list_to_linked_list(input2)
    expected_result = list_to_linked_list(expected_output)

    s = Solution()
    result = s.addTwoNumbers(l1, l2)

    assert linked_list_to_list(result) == expected_output, f"Expected: {expected_output}, Got: {linked_list_to_list(result)}"

# Example tests
run_test([2,4,3], [5,6,4], [7,0,8])
run_test([0], [0], [0])
run_test([9,9,9,9,9,9,9], [9,9,9,9], [8,9,9,9,0,0,0,1])

print("All tests passed!")

