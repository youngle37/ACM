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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur_1 = l1;
        ListNode* cur_2 = l2;
        ListNode* last_1 = NULL;
        ListNode* last_2 = NULL;
        
        bool carry = false;
        
        while(cur_1 != NULL && cur_2 != NULL){
            if(carry){
                cur_1->val++;
                carry = false;
            }
            
            cur_1->val += cur_2->val;
            
            if(cur_1->val >= 10){
                cur_1->val -= 10;
                carry = true;
            }
            
            last_1 = cur_1;
            last_2 = cur_2;
            
            cur_1 = cur_1->next;
            cur_2 = cur_2->next;
        }
        
        if(cur_1 != NULL && carry){
            while(cur_1 != NULL && carry){
                cur_1->val++;
                carry = false;

                if(cur_1->val >= 10){
                    cur_1->val -= 10;
                    carry = true;
                }

                last_1 = cur_1;
                cur_1 = cur_1->next;
            }

            if(carry){
                ListNode* newDigit = new ListNode(1);
                last_1->next = newDigit;
            }
        } else if(cur_2 != NULL){
            if(carry){
                ListNode* now_2 = cur_2;
                while(now_2 != NULL && carry){
                    now_2->val++;
                    carry = false;

                    if(now_2->val >= 10){
                        now_2->val -= 10;
                        carry = true;
                    }

                    last_2 = now_2;
                    now_2 = now_2->next;
                }

                if(carry){
                    ListNode* newDigit = new ListNode(1);
                    last_2->next = newDigit;
                }
            }

            last_1->next = cur_2;
        } else if(carry) {
            ListNode* newDigit = new ListNode(1);
            
            last_1->next = newDigit;
        }

        return l1;
    }
};
