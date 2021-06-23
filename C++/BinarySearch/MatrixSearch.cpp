
#include <bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    
    int N =A.size();
    int M =A[0].size();
    int i=0, j =M-1;
    
    while(i<N && j>=0)
    {
       // cout<<A[i][j];
        if(A[i][j]==B)
        return 1;
        
        else if(A[i][j]<B)
        i++;
        
        else
        j--;
    }
    return 0;
}