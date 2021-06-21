
// https://leetcode.com/problems/perfect-squares/submissions/
using namespace std;
#include <bits\stdc++.h>
class Solution {
public:
    int numSquares(int n) {
        
        if(n<=0)
            return 0;

        
        int mini =n;
        // for(int i=1;i*i<=n;i++)
        // {
        //     mini = min(mini , numSquares(n - (i*i)));
        // }
                 // return mini+1;

       
        
        vector<int> dp(n+1 , n);
        dp[0]=0;
        for(int s = 1;s<=n;s++)
        {
            for(int i=1;i*i<=s;i++)
        {
            dp[s] = min(dp[s] , dp[s-(i*i)]+1);
          //  mini = mini+1;
        }
        }
        
        return dp[n];

    }
};