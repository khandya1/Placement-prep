
using namespace std;
#include <bits\stdc++.h>

class Solution
{
public:
int MaxRoddCutting(int n)
{
    if(n==1)
    return 1;
    int maxi = INT_MIN;
    for(int i=1;i<n;i++)
    {
            maxi = max(maxi , max(i*(n-i) , MaxRoddCutting(n-i)*i));
    }
    return maxi;
}
int MaxRoddCuttingDP(int n , vector<int> dp)
{
    dp[0]=dp[1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        
            dp[i]=max(dp[i] , max(j*(i-j) , dp[i-j]*j));
            cout<<dp[i]<<"\n";
    }
    return dp[n];
}
};
int main()
{
    int n =10;
    Solution s;
    vector<int> dp(n+1,-1);
    cout<<s.MaxRoddCuttingDP(n,dp);
}