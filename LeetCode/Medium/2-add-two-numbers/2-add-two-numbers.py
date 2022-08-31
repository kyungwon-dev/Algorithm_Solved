# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        answer = ListNode()
        head = answer
        prev = 0
        while l1 and l2:
            answer.val = l1.val + l2.val + prev
            answer.val, prev = answer.val % 10 , answer.val // 10
            l1 , l2 = l1.next, l2.next
            if not l1 and not l2:
                break
            answer.next = ListNode()
            answer = answer.next
        
        while l1:
            answer.val = l1.val + prev
            answer.val, prev = answer.val % 10 , answer.val // 10
            l1 = l1.next
            if not l1:
                break
            answer.next = ListNode()
            answer = answer.next
        
        while l2:
            answer.val = l2.val + prev
            answer.val, prev = answer.val % 10 , answer.val // 10
            l2 = l2.next
            if not l2:
                break
            answer.next = ListNode()
            answer = answer.next
        
        if prev!=0:
            answer.next = ListNode(prev)
            answer = answer.next
        
        return head


        
