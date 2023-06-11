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


//229. Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0;
        int e1=INT_MIN;
        int e2=INT_MIN;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=e2){
                c1=1;
                e1=nums[i];
            }
            else if(c2==0 && nums[i]!=e1){
                c2=1;
                e2=nums[i];
            }
            else if(e1==nums[i])c1++;
            else if(e2==nums[i])c2++;
            else{
                c1--;
                c2--;
            }
        }
        int coun1=0;
        int coun2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1){
                coun1++;
                if(coun1==(n/3)+1)
                    ans.push_back(e1);
            }
            else if(nums[i]==e2)
            {
                coun2++;
                if(coun2==(n/3)+1)
                    ans.push_back(e2);
            }
            if(ans.size()==2)
                break;
        }


        return ans;

    }
};

//Unique Paths

    int f(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
            return 1;
        else if(i<0||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        int x=f(i-1,j,dp);
        int y=f(i,j-1,dp);

        return dp[i][j]=x+y;
    }

int uniquePaths(int m, int n) {

	vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=f(m-1,n-1,dp);
        return ans;
}