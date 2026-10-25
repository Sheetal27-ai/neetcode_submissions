/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    void insertAtTail(ListNode* &head, int data){
        ListNode* temp = new ListNode(data);
        if(head == NULL){
            head = temp;
            return;
        }
        
        ListNode* tempHead = head;
        while(tempHead -> next != NULL){
            tempHead = tempHead -> next;
        }

        tempHead -> next = temp;
        temp -> next = NULL;
        return;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = NULL;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int l1_digit = 0;
            int l2_digit = 0;
            if(l1 != NULL)
                l1_digit = l1 -> val;
            if(l2 != NULL)
                l2_digit = l2 -> val;
            
            int sum = l1_digit + l2_digit + carry;;
            int digit = sum % 10;
            carry = sum/10;

            insertAtTail(ans, digit);
            if(l1 != NULL)
                l1 = l1 -> next;
            if(l2 != NULL)
                l2 = l2 -> next;
        }
        return ans;
    }
};
