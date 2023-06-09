//48. Rotate Image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
            swap(matrix[i][j],matrix[j][i]); 
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
//56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
                res.push_back(intervals[i]);
            else if(intervals[i][1]>=intervals[i+1][0])
            {
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

//88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(j>=0 && i>=0)
        {
                if(nums1[i]>nums2[j])
                {
                    nums1[k]=nums1[i];
                    i--;
                    k--;
                }
                else if(nums1[i]==nums2[j])
                {
                    nums1[k]=nums1[i];
                        i--;
                        k--;
                    nums1[k]=nums2[j];
                        j--;
                        k--;
                }  
                else
                {
                    nums1[k]=nums2[j];
                    j--;
                    k--;
                }
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            k--;
            j--;
        }
        while(i>=0)
        {
            nums1[k]=nums1[i];
            k--;
            i--;
        }
    }
};

//287. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};

//Missing and repeating numbers(code studio)

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long cursum = 0, actsum = (long long)(n * (n + 1)) / 2;
        for (auto x : arr)
            cursum += (long long)x;
        long long sqcursum = 0, sqactsum = ((long long)n * (long long)(n + 1) * (long long)(2 * n + 1)) / 6;
        for (auto x : arr)
            sqcursum += (long long)x * (long long)x;
        long long diff = cursum - actsum, sqdiff = sqcursum - sqactsum;
        long long sum = sqdiff / diff;

        long long repeating = (sum + diff) / 2;
        long long missing = sum - repeating;
        return {(int)missing, (int)repeating};

	
}

//Count Inversion(code studio)

#include <bits/stdc++.h>

long long merge(long long *arr,int low,int mid,int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;

    long long cnt=0;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {   
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return cnt;

}




long long mergeSort(long long *arr,int low,int high)
{
    long long  cnt=0;
    if(low>=high)return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr, low, mid,high);
    return cnt;

}

long long getInversions(long long *arr, int n){
        return mergeSort(arr, 0, n-1);
}


