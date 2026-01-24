class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevLast = &dummy;
        while (true) {
            ListNode* kthNode = prevLast;
            for (int i = 0; i < k && kthNode; i++) {
                kthNode = kthNode->next;
            }
            if (!kthNode) break;
            ListNode* nextNode = kthNode->next;
            ListNode* curr = prevLast->next;
            ListNode* prev = nextNode;
            while (curr != nextNode) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = prevLast->next;
            prevLast->next = kthNode;
            prevLast = temp;
        }
        return dummy.next;
    }
};
