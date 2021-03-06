///   https://leetcode.com/problems/partition-equal-subset-sum/
/// lc 416

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+= nums[i];
        }
        if(sum%2!=0)
            return false;
        int n = nums.size();
        bool dp[n+1][sum/2 +1];
        dp[0][0]=true; // sum 0 element 0 is possible
        for(int i=1;i<=sum/2;i++)
            dp[0][i]=false;
        for(int i=1;i<=n;i++)
            dp[i][0]=true; //// if don't take the element sum 0 is possible-> across the row 
        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=sum/2;j++)
            {
                
                if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];/// if we decrease the element the remaining sum should be possible
            }
        }
        return dp[n][sum/2];
        
    }

    bool equalSum(int nums[], int n, int sum , int pos)
    {
        if(sum==0)
        return true;
        if(n==pos)
        return false;

        if(nums[pos]>sum)
        return equalSum(nums, n, sum, pos+1);
        else
        return equalSum(nums, n, sum, pos+1)|| equalSum(nums,n,sum-nums[pos],pos+1);
      
    }

};