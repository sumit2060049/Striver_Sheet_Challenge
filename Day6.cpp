

//160. Intersection of Two Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b)
        {
            if(a==NULL)a=headB;
            else a=a->next;

            if(b==NULL)b=headA;
            else b=b->next;
        }
        return a;
    }
};


//141. Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)return true;
        }
        return false;

    }
};


//25. Reverse Nodes in k-Group

class Solution {
public:
   void reverse(ListNode *s,ListNode *e)
    {
        ListNode *p=NULL,*c=s,*n=s->next;
        while(p!=e)
        {
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)
            n=n->next;

        }

    }

    ListNode* reverseKGroup(ListNode* head, int k) {


if(head==NULL||head->next==NULL||k==1)
return head;
ListNode* dummy=new ListNode(-1);
dummy->next=head;
ListNode *beforeStart=dummy,*e=head;
int i=0;
while(e!=NULL)
{
    i++;
    if(i%k==0)
    {
        ListNode *s=beforeStart->next,*temp=e->next;
        reverse(s,e);
        beforeStart->next=e;
        s->next=temp;
        beforeStart=s;
        e=temp;
    }
    else
    {
        e=e->next;
    }

}
return dummy->next;

        
    }
};


//234. Palindrome Linked List

class Solution {
public:
    ListNode* reverse(ListNode *head)
    {   if(head==NULL)
        return NULL;
        ListNode *p=NULL,*c=head,*n=head->next;
        while(c!=NULL)
        {
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)
            n=n->next;

        }
        return p;

    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        slow->next=reverse(slow->next);
        ListNode *start=head,*mid=slow->next;
        while(mid!=NULL)
        {
            if(mid->val!=start->val)
            return false;
            start=start->next;
            mid=mid->next;
        }
        //print(head);
        slow->next=reverse(slow->next);
       // print(head);
        return true;


    }
};

//142. Linked List Cycle II


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)break;
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        ListNode *ptr1=head,*ptr2=slow;
        while(ptr1!=ptr2)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1;
    }
};

//Flatten A Linked List


Node* mergeTwoLists(Node* a, Node* b) {

    

    Node *temp = new Node(0);

    Node *res = temp; 

    

    while(a != NULL && b != NULL) {

        if(a->data < b->data) {

            temp->child = a; 

            temp = temp->child; 

            a = a->child; 

        }

        else {

            temp->child = b;

            temp = temp->child; 

            b = b->child; 

        }

    }

    

    if(a) temp->child = a; 

    else temp->child = b; 

    

    return res -> child; 

    

}

Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL) return head;

    Node* L2 = flattenLinkedList(head->next);

    head->next = NULL;

    Node* nhead = mergeTwoLists(head, L2);

    return nhead;

}