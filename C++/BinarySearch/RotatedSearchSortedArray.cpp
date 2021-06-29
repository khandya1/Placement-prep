

#include <bits/stdc++.h>
using namespace std;

int search(const vector<int> &A, int B) {
    
    
    int low=0;
    int high=A.size();
    
    while(low<=high)
    {
        int mid =(low+high)/2;
       // cout<<mid<<" ";
        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[low]<A[mid])
        {
            if(B<A[mid] && A[low]<=B)
            high=mid-1;
            else
            low=mid+1;
        }
        else
        {
            if(B>A[mid] && A[high]>=B)
            low=mid+1;
            else
            high=mid-1;
        }
    }
    return -1;
}
