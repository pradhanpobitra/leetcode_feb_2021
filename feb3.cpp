class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode  *slow,*fast;
        slow = fast = head;
        do{
            if(!fast->next || !fast->next->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);
        return true;
    }
};