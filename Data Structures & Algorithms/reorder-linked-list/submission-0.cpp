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
    ListNode* getMid(ListNode* &head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow != NULL && fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        } 

        return prev;
    }

    ListNode* insert(ListNode* &head1, ListNode* &head2){
        ListNode* curr1 = head1;
        ListNode* next1 = head1 -> next;
        ListNode* curr2 = head2;
        
        while(curr1 != NULL && curr2 != NULL){
            ListNode* next2 = curr2 -> next;
            curr1 -> next = curr2;
            curr2 -> next = next1;
            curr2 = next2;
            curr1 = next1;
            if(curr1 != NULL){
                next1 = curr1 -> next;
            }
        }
        return head1;
    }
public:
    void reorderList(ListNode* head) {
        if(head -> next == NULL){
            return;
        }
        // step 1 -> find middle
        ListNode* middle = getMid(head);

        // step 2 -> reverse the list after mid pt.
        ListNode* midHead = middle -> next;
        middle -> next = NULL;
        ListNode* temp = reverse(midHead);
        

        // step 3 -> insert in between the fist part of list
        ListNode* ans = insert(head, temp);
        head = ans;
        
    }
};
