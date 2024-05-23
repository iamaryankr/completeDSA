class Solution {
public:
    int length(ListNode *p){
        int len = 0;
        while(p){
            len++;
            p = p->next; 
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        int diff = abs(lenA-lenB);

        if(lenA>lenB){
            while(diff--) headA = headA->next;
        }
        else{
            while(diff--) headB = headB->next;
        }

        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};