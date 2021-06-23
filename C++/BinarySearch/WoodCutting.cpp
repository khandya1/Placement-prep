// interview bit

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
    int maxi = *max_element(A.begin(),A.end());

    int start = 0;
    int end = maxi;
    int mid;
    while(start<end)
    {
        long sum =0;
        mid = (start +end)/2;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>=mid)
            sum += A[i]-mid;
            
        }
      //  cout<<sum;
        if(sum==B || start ==mid)
        return mid;
        if(sum<B)
        end = mid;
        else
        start = mid;
    }
    return mid;
}
