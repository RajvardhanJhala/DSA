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
      ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
      }    
public:
    bool isPalindrome(ListNode* head) {
      if(head==nullptr || head->next == nullptr) return true;
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* secondHalf = reverseList(slow);
      ListNode* firstHalf = head;
      while(secondHalf!=nullptr){
        if(secondHalf->val != firstHalf->val){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
      }
      return true;
      }

    };