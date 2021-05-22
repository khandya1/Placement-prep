// http://www.interviewbit.com/problems/maximum-absolute-difference/

#include<bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    
    //Difference of sums: (A[i]+i) - (A[j]+j)
    //Difference of differences: (A[i]-i) - (A[j]-j)
   int max1 = INT_MIN, max2 = INT_MIN;
   int min1 = INT_MAX, min2 =INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        max1= max(A[i]+i, max1);
        max2= max(A[i]-i, max2);
        min1= min(A[i]+i, min1);
        min2= min(A[i]-i, min2);
    }
    return max(abs(max1-min1),abs(max2-min2));
}

void main()
{
    vector<int> A = {1, 2, 3};
    cout<<maxArr(A);
}


