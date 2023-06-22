//Maximum meetings

#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>> ans;
    for(int i=0;i<start.size();i++)
    {
        ans.push_back({end[i],{i+1,start[i]}});
    }
    sort(ans.begin(),ans.end());
    int n=ans.size();
    int e=-1;
    vector<int>res;
    for(auto val:ans)
    {
        if(val.second.second>e)
        {
            res.push_back(val.second.first);
            e=val.first;
        }
    } 
    return res;

}

//Minimum Number of Platforms

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int i = 0 , j = 0;
    int maxi = 0;
    int platforms = 0;
    while(i < n && j < n){
        if(at[i] <= dt[j]) i++ , platforms++;
        else j++ , platforms--;
        maxi = max(platforms,maxi);
    }
    return maxi;
}

//Job Sequencing Problem

#include <bits/stdc++.h> 
#include<algorithm>
bool comp(vector <int> a,vector<int> b)
{
    return a[1]>b[1];
    }
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comp);
    int n=jobs.size();
    int maxdead=INT_MIN;
    for (int i=0;i<n;i++)
    maxdead=max(jobs[i][0],maxdead);
    int profit=0;
     vector<int> ans(maxdead+1,-1);     //why maxdead +1 soze is needed  ans 1 indexing is used
    for (int i=0;i<n;i++)
    {
        int currdead=jobs[i][0];
        int currprofit=jobs[i][1];
        for (int k=currdead;k>0;k--)
        {
            if(ans[k]==-1)
            {
                profit+=currprofit;
                ans[k]=1;
                break;
            }
        }
    }
    return profit;
}


//Fractional Knapsack

#include <bits/stdc++.h> 
bool comp(pair<int,int>a,pair<int,int>b)
{
    double r1=(double)a.second/a.first;
    double r2=(double)b.second/b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comp);
    double res=0;
    for (int i=0;i<n;i++)
    {
        if(items[i].first<=w)
        {
            res=res+items[i].second;
            w=w-items[i].first;
        }
        else
        {
            res=res+(items[i].second *((double)w/items[i].first));
            break;
        }
    }
    
    return res;
}


//Find Minimum Number Of Coins

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[9]={1,2,5,10,20,50,100,500,1000};
    int coin=0;
    for(int i=8;i>=0;i--)
    {
        if(amount/arr[i]==0)
        {

        }
        else
        {
            int r=amount/arr[i];
            amount=amount-arr[i]*r;
            coin=coin+r;
        }
        if(amount==0)
            break;

    }
    return coin;
}


//Maximum activities

#include <bits/stdc++.h> 

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>vp;
    int n=start.size();
    
    for(int i=0;i<n;i++)
        vp.push_back({finish[i],start[i]});
        
    sort(vp.begin(),vp.end());
    
    int count=1;
    int endLimit=vp[0].first;

    for(int i=1;i<n;i++)
    {
        int s=vp[i].second,e=vp[i].first;

        if(s>=endLimit)
        {
            count++;
            endLimit=e;
        }
    }
    return count;
}



