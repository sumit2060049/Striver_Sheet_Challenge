
//61. Rotate List


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

    if(!head || !head->next||k==0)
        return head;

    ListNode *cur=head;
    int len = 1;
    while(cur->next && ++len)
        cur=cur->next;

    cur->next=head;
    k=k%len;
    k=len-k;
    while(k--)cur=cur->next;

    head=cur->next;
    cur->next= NULL;

    return head;

    }
};

//138. Copy List with Random Pointer


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;
        while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
            iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

    
        iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

        while (iter != NULL) {
            front = iter->next->next;

            
            copy->next = iter->next;

            
            iter->next = front;
        
            copy = copy -> next; 
            iter = front;
        }

        return pseudoHead->next;
    }
};

//15. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());//nlogn to sort
        vector<vector<int>>res;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0||(i>0 && nums[i]!=nums[i-1]))
            {
                int lo=i+1,hi=nums.size()-1,sum=0-nums[i];
                while(lo<hi)
                {
                    if(nums[lo]+nums[hi]==sum)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        
                        while(lo<hi && nums[lo]==nums[lo+1])lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])hi--;
                        
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum)lo++;
                    else hi--;
                }
            }
        }
        return res;
            }
};

//42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;int right=n-1;
        int res=0;
        int maxleft=0,maxright=0;

        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=maxleft)
                maxleft=height[left];
                else
                res+=maxleft-height[left];
                left++;
            }
            else
            {
                if(height[right]>=maxright)
                maxright=height[right];
                else
                res+=maxright-height[right];

                right--;
            }
        }
        return res;

    }
};

//26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j]){
                i++;
            nums[i]=nums[j];
            }
                
        }
        return i+1;
    }
};

//485. Max Consecutive Ones


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count++;
                if(count>max)
                {
                    max=count;
                }
            }
            else
            {
                
                count=0;
            }
        }
        return max;
    }
};

