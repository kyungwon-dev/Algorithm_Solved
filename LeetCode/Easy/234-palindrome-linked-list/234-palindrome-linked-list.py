from collections import deque
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        listnode_to_list = []
        listnode_to_list.append(head.val)
        while head.next != None:
            head = head.next
            listnode_to_list.append(head.val)
        return True if listnode_to_list == listnode_to_list[::-1] else False
        