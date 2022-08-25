# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        rev = None
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next
        
        while rev and rev.val == slow.val:
            slow, rev = slow.next , rev.next
        
        return not rev
        
        
        
#         listnode_to_list = []
#         listnode_to_list.append(head.val)
#         while head.next != None:
#             head = head.next
#             listnode_to_list.append(head.val)
#         return True if listnode_to_list == listnode_to_list[::-1] else False
        
        