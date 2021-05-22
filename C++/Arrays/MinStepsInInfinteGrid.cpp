//https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

#include<bits/stdc++.h>
using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    
    int count;
    for(int i=0,j=0;i<A.size()-1;i++,j++)
    {
        
        int x= abs((A[i+1])-(A[i]));
        int y= abs((B[i+1])-(B[i]));
        count=count+max(x,y);
    }
    return count;
}
void main()
{
    vector<int> A = {1, 2, 3};
    vector<int> B = {4,5,6};
    cout<<coverPoints(A, B);
}
