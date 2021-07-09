///  https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

#include <bits/stdc++.h>
using namespace std; 
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        for(int i=0;i<n-1;i++)
        {
            int l = i+1;
            int r = n-1;
            while(l<r)
            {
                if(arr[i]+arr[l]+arr[r] ==0)
                return 1;
                
                else if(arr[i]+arr[l]+arr[r] >0)
                r--;
                
                else 
                l++;
                
            }
        }
        return 0;
    }
};