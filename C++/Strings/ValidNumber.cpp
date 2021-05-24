//   https://www.interviewbit.com/problems/valid-number/
/// lc 65
/// https://www.interviewbit.com/problems/valid-number/
//// leetcode testcases are wrong refer to IB

#include <bits/stdc++.h>
using namespace std;

class Solution{

int isNumber(const string A) {
    
      int n = A.size();

int i = 0;
int j =  n-1;
while(A[i]==' ' && i<n) {i++;}



while(A[j]==' ' && j>=0) {j--;}

if( i > j) return 0;

n=j+1;

int start = i;

if(n-start==1) 
{
    if(A[start]>='0' && A[start]<='9') return 1;
    
    else return 0;
}



bool e = false;

int dotCount = 0;

int eCount = 0;



while(i < n)
{
    if(A[i]>='0' && A[i]<='9' && i < n)
    { 
        i++;
    }
    else if(A[i] == 'e')
    {
        eCount++;
        
        if(eCount > 1) return 0;
        
        else if(i==start) return 0;
        
        else if(A[i-1]=='.') return 0;
        
        e = true;
        i++;
    }
    else if(A[i] == '.')
    {
        dotCount++;
        
        if(dotCount > 1) return 0;
        
        else if(e==true) return 0;
        
        else if(i+1==n) return 0;
        
        else 
           i++;
    }
    else if (A[i]=='+' || A[i]=='-')
    {
        if(i==start && i+1 < n) 
        {
            if(A[i+1]=='.')
            {
                i++;
            }
            else if(A[i+1]>='0' && A[i+1]<='9')
            {
                i++;
            }
           else 
                return 0;
        }
        else if(i>start && A[i]=='-')
        {
            if(A[i-1]=='e')
            {
                i++;
            }
        }
        else return 0;
    }
    else return 0;
}

return 1;
   
}
};