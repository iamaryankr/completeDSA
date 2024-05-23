class Solution {
public:
    Node* copyRandomList(Node* head) {
        //adding copy node after the real node
        Node *temp = head;
        while(temp!= nullptr){
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        //building the random for the copy nodes
        Node *itr = head;
        while(itr){
            if(itr->random){
                itr->next->random = (itr->random)->next;
            }
            itr = itr->next->next;
        }
        //retrieving the lists separately
        Node *dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node *fast;
        while(itr){
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
       return dummy->next;
    }
};