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
public:

    ListNode* reverseList(ListNode* node){
        ListNode* temp=node;
        ListNode* curr=node;
        ListNode* pre=NULL;
        if(node->next==NULL)return node;
        while(curr!=nullptr){
            temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }

    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int n=0;
        ListNode* pre=NULL;
        while(fast!=NULL){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
            n++;
        }
        // cout<<n<<endl;
        // cout<<pre->val<<endl;
        ListNode* temp=pre->next;
        ListNode* voidValue=NULL;
        // cout<<temp->val<<endl;
        pre->next=voidValue;
        ListNode* p=reverseList(temp);
        ListNode* p_holder=p;
        // cout<<"p_holder-end-here"<<endl;
        int sum=INT_MIN;
        fast=head;
        while(p!=NULL && fast!=NULL){
            sum=max(sum,(p->val+fast->val));
            // cout<<"value of p is :"<<p->val<<"\n";
            // cout<<"value of fast is :"<<fast->val<<"\n";
            p=p->next;
            fast=fast->next;
        }        
        return sum;
    }
};