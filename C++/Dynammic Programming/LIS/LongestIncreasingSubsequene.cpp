#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
int lisrecur(int arr[] , int pos,int prev, int n)
{
    if(pos==n)
    return 0;
    if(arr[pos]<prev)
    {
     return lisrecur(arr, pos+1, prev, n);   
    }
    return max(1+lisrecur(arr,pos+1, arr[pos], n), lisrecur(arr, pos+1, prev, n));
}
int lisdp(int arr[], int n)
{
    vector<int> dp{n,1};
     for(int i=0;i<n;i++)
    {dp[i]=1;}
    int maxi=1;
   // cout<<dp[0][0];
    for(int i=0;i<n;i++)  
    {
        for(int j=i;j<n;j++)
        {
           if(arr[j]>arr[i])
           dp[j] = max(dp[j], 1+dp[i]);
           maxi= max(maxi, dp[j]);

        }
          cout<<dp[i]<<" ";
        //cout<<"\n";
    }
    return maxi;

}


};
int main()
{
    int arr[] ={10, 22, 9, 33, 21, 50, 41, 60, 80};
  //  int arr[] = {3, 10, 2, 11};
    int n = 9;
    Solution s;
  //  cout<<s.lisrecur(arr, 0, -1, 4);
    cout<<s.lisdp(arr, n);
}