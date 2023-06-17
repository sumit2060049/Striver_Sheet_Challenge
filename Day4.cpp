//1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> p;
        map<int,int> mm;
        for(int i=0;i<nums.size();i++)
        {
            if(mm.find(target-nums[i])!=mm.end())
            {
                p.push_back(mm[target-nums[i]]);
                p.push_back(i);
                
            }
            mm[nums[i]]=i;
            if(p.size()==2)
            break;
        }
        return p;
    }
};

//18. 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int> > res;
        
        if (nums.empty())
            return res;
        int n = nums.size(); 
        sort(nums.begin(),nums.end());
    
        for (int i = 0; i < n; i++) {
        
           long long int target_3 = target - nums[i];
        
            for (int j = i + 1; j < n; j++) {
            
               long long int target_2 = target_3 - nums[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = nums[front] + nums[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && nums[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && nums[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        
        }
    
        return res; 
    }
};

//128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n= nums.size();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int cnt=1;
                int x=it;
                while(st.find(x+1)!= st.end ()){
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(longest,cnt);
            }
        }
    return longest;




    }
};

// Longest Subarray Zero Sum

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    map<long long ,int> preSumMap;
    long long sum=0;
    int maxLen=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            maxLen=max(maxLen,i+1);
        long long rem=sum;
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)== preSumMap.end())
            preSumMap[sum]=i;
    }
    return maxLen;
  

}

//Count Subarrays with Given XOR

#include <bits/stdc++.h>



int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++;
    int cnt=0;
    for(int i=0;i<arr.size();i++)
    {
        xr=xr^arr[i];

        int y=xr^x;
        cnt+=mpp[y];
        mpp[xr]++;


    }
    return cnt;
}

//Longest Substring Without Repeating Characters

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
     vector<int>mpp(256,-1);

        int left=0,right=0;
        int n=input.size();
        int len=0;
        while(right<n)
        {
            if(mpp[input[right]] !=-1)
            left=max(mpp[input[right]]+1,left);

            mpp[input[right]]=right;

            len=max(len,right-left+1);
            right++;
        }
        return len;
}