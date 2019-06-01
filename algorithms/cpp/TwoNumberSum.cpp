//from https://leetcode-cn.com/problems/add-two-numbers/submissions/

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
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        auto start1 = l1;
        auto start2 = l2;
        int carry = 0;
        ListNode* sumNode = new ListNode(0);
        ListNode* result = sumNode;
        
        while(true)
        {
            int sum = 0;
            
            int s1 = 0;
            if(start1 != NULL)
            {
                s1 = start1->val;
            }
            
            int s2 = 0;
            if(start2 != NULL)
            {
                s2 = start2->val;
            }
            
            sum = s1 + s2 + carry;
            carry = sum/10;
            sum = sum%10;
            
            sumNode->val = sum;
                         
            start1 = (start1==NULL?NULL:start1->next);
            start2 = (start2==NULL?NULL:start2->next);
            
            if(start1 == NULL && start2 == NULL && carry == 0)
            {
                break;
            }
            
            ListNode* nextSum = new ListNode(0);
            sumNode->next = nextSum;
            sumNode = sumNode->next;

        }
        
        return result;
    }
};
