//74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(!matrix.size()){
            return false;
        }
        int n=matrix.size();
        int m=matrix[0].size();

        int lo=0;
        int h=(n*m)-1;

        while(lo<=h)
        {
            int mid=(lo+h)/2;
            if(matrix[mid/m][mid%m]==target)
            return true;

            else if(matrix[mid/m][mid%m]<target)
            lo=mid+1;
            else
            h=mid-1;
        }
        return false;

    }
};

//50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0)
            nn=-1*nn;
        while(nn)
        {
            if(nn%2)
            {
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0)ans=(double)(1.0)/(double)(ans);
        return ans;
        
    }
};

//169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int count=0,element=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0){
                    element=nums[i];
            }
            if(element==nums[i])
            {
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};
