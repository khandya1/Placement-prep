// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/


#include<bits/stdc++.h>
using namespace std;
int maxSubArray(const vector<int> &A) {
    
    int sum =A[0], temp=A[0];
    int max_sum =A[0];
    int position;
    
    for(int i=1;i<A.size();i++)
    {
        sum = max(sum + A[i], A[i]);
        if(sum>=temp)
        {
            temp = sum;
           //cout<<"temp  "<<temp <<"sum  "<<sum<<"\n";
        }
       
        max_sum = max(max_sum, temp);
    }
    return max_sum;
    
}
void main()
{
    vector<int> A = {1, 2, 3};
    cout<<maxSubArray(A);
}