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
