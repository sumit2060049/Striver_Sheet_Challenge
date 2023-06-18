
//206. Reverse Linked List

class Solution {
public:
    ListNode* reverse(ListNode *head)
    {   if(head->next==NULL)
        {
        return head;
        }
        ListNode* reverseHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return reverseHead;
    }
    ListNode* reverseList(ListNode* head) {
    
        if(head==NULL)
        return NULL;
        return reverse(head);
    }
};

//876. Middle of the Linked List

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode* temp1=head;
        struct ListNode* temp2=head;
        while(temp2&&temp2->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        return temp1;
    }
};

//21. Merge Two Sorted Lists

class Solution {
public:
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val<l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2);
    }
};

//19. Remove Nth Node From End of List

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;

        for(int i=1;i<=n;i++)
        {
            fast=fast->next;
        }
        while(fast->next != NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        return start->next;
    }
};

//2. Add Two Numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry)  {

            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;

    }
};


//237. Delete Node in a Linked List


class Solution {
public:
    void deleteNode(ListNode* node) {
        
            struct ListNode* temp;
            temp=node->next;
        
        swap(node->val,node->next->val);
        
        node->next=node->next->next;
            delete temp; 
        //}
    }
};