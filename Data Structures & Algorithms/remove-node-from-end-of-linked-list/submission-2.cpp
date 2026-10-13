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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        // step1 -> Reverse the list
        ListNode* tempHead = reverse(head);
        if(n == 1){
            ListNode* temp = tempHead;
            tempHead = temp -> next;
            temp -> next = NULL;
            delete(temp);
            
        }
        else{
            ListNode* curr = tempHead;
            for(int i=1; i < n-1; i++){
                curr = curr -> next;
            }
        // step2 -> delete at position
            ListNode* nodeToDelete = curr -> next;
            curr -> next = nodeToDelete -> next;
            nodeToDelete -> next = NULL;
            delete(nodeToDelete);
        }
        // step3 -> Again reverse the list
        return reverse(tempHead);
    }
};
