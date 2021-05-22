//  https://www.interviewbit.com/problems/add-one-to-number/

#include<bits/stdc++.h>
using namespace std;



vector<int> plusOne(vector<int> &A) {
  
   // vector<int> x(A.size()+1)
   
   if(A.size()==0)
         {   A.push_back(1);
             return A ;
         }
         
         
     vector<int> x;
     int num, flag=0;
     for(int i=A.size()-1;i>=0;i--)
     {
         if(i==A.size()-1)
         {
             num=A[i]+1;
             if(num>9)
             {
                 flag=1;
                 x.push_back(0);
                 
             }
             else
             {flag=0;
             x.push_back(num);
             }
         }
         else if(flag==1)
         {
             num=A[i]+1;
             //cout<<num;
             if(num>9)
             {
                 flag=1;
                 x.push_back(0);
                 
             }
              else{flag=0;
             x.push_back(num);
             }
             
             
             
             
         }
         else
         {
             x.push_back(A[i]);
         }
     }
     
    if(flag==1)
             x.push_back(1); 
             
             
  auto rit = std::find_if(x.rbegin(), x.rend(),[](int v) 
  { return v != 0; });
    x.erase(rit.base(), end(x));
     
    reverse(x.begin(),x.end());   
    
   
       
   
    return x;
}
void main()
{
    vector<int> A = {1, 2, 3};
    vector<int> x = plusOne(A);
}
