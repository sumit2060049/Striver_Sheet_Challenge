#include <bits/stdc++.h>
//73.Set Matrix Zeros
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //row -> matrix[..][0]
        //col -> matrix[0][..]
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;

                    if(j!=0)
                        matrix[0][j]=0;
                    else
                        col0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=0){
                    if(matrix[0][j]==0 || matrix[i][0]==0)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++)
                matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }



    }
};

//118.Pascal Triangle


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>r(numRows);
        for(int i=0;i<numRows;i++)
        {
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;
            
            for(int j=1;j<i;j++)
                r[i][j]=r[i-1][j-1]+r[i-1][j];
        }
        return r;
    }
};

//31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k,l;
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }else{
            for(l=n-1;l>k;l--)
        {
            if(nums[l]>nums[k])
            {
                break;
            }
        }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};
