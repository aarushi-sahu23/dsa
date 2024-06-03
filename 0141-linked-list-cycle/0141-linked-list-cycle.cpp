/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       /* ListNode * temp= head;
        map<ListNode*, int> mp;
        while(temp!=nullptr){
            
            if(mp[temp]==1){
                return true;
            }
            mp[temp]=1;
            temp= temp->next;
        }
     return false;*/

     // tortoise and hare
     ListNode* slow= head;
     ListNode* fast= head;
     while(fast!= nullptr && fast->next!= nullptr){
        slow= slow->next;
        fast= fast->next->next;
        if(slow== fast){
            return true;
        }

     }
    return false;

    }
};