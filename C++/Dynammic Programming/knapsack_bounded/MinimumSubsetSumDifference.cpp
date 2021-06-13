///   https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+= nums[i];
        }
        int n = nums.size();
        bool dp[n+1][sum];
        dp[0][0]=0; 
        for(int i=1;i<=sum;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=0; 
        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j]=min(abs(j - 2*(dp[i-1][j-nums[i-1]])) , abs(j-2*dp[i-1][j]));
            }
        }
        return dp[n][sum];
        
    }

    int minDiff(int nums[], int n, int maxsum ,int currsum, int pos)
    {
        if(n==pos)
        return abs(maxsum - 2*currsum);

        return min(minDiff(nums, n, maxsum,currsum, pos+1) ,  minDiff(nums,n,maxsum ,currsum+nums[pos],pos+1));
      
    }

};