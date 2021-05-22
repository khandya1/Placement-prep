//  https://www.interviewbit.com/problems/partitions/


#include<bits/stdc++.h>
using namespace std;


int solve(int A, vector<int> &B) {
    
    
    int csum =0,count=0;
    for(int i=0;i<B.size();i++)
    {
        csum= csum + B[i];
    }
    if((csum%3) !=0)
    return 0;
    vector<int> prefix(B.size());
    prefix[0]=B[0];
    for(int i=1;i<B.size();i++)
    {
        prefix[i]= prefix[i-1]+B[i];
      
    }
    vector<int> suffix(B.size());
    suffix[B.size()-1]=B[B.size()-1];
    for(int i=B.size()-2;i>0;i--)
    {
        suffix[i]= suffix[i+1]+B[i];
      
    }
    
    vector<int> cnt_sum(B.size());
        if(suffix[B.size()-1]==csum/3) 
        cnt_sum[B.size()-1]=1;
        else    
        cnt_sum[B.size()-1]=0;
        
        for(int i=B.size()-2;i>=0;i--)
        {
            if(suffix[i]==csum/3)   
            cnt_sum[i]=cnt_sum[i+1]+1;
            else    
            cnt_sum[i]=cnt_sum[i+1];
        }
        
        
        for(int i=0;i<B.size()-2;i++)
        {
            if(prefix[i]==csum/3)
            {
                count+=cnt_sum[i+2];
            }
        }

        return count;
   
}


void main()
{
    vector<int> A = {1, 2, 3};
    cout<<solve(3, A);
}

