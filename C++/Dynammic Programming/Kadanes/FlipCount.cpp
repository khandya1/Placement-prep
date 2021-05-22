////   https://www.interviewbit.com/problems/flip/


#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> bruteforcesolution(string A)
    {
        vector<int> x;
        int max_count = 0;
        int pos1, pos2, c = 0, d = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == '1')
                c++;
            if (A[i] == '0')
                d++;
        }
        if (c == A.size())
            return x;
        if (d == A.size())
        {
            x.push_back(1);
            x.push_back(A.size());
            return x;
        }

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i; j < A.size(); j++)
            {

                int count = 0;
                for (int k = 0; k < A.size(); k++)
                {
                    //cout<<"i ="<<i<<"j = "<<j<<"---";
                    //cout<<k>=i;
                    if (k >= i && k <= j && A[k] == '0')
                    {
                        count++;
                    }
                    else if (k > j && A[k] == '1')
                    {
                        count++;
                    }
                    else if (k < i && A[k] == '1')
                    {
                        count++;
                    }

                    // cout<<"k="<<k<<"A[k]= "<<A[k]<<"   "<<count<<"\n";
                }
                //  cout<<count;
                if (count > max_count)
                {
                    max_count = count;
                    pos1 = i;
                    pos2 = j;
                }
            }
        }
        if (max_count == 0)
            return x;
        else
        {
            x.push_back(pos1 + 1);
            x.push_back(pos2 + 1);
            return x;
        }
    }

    vector<int> flipCount(string A)
    {

        vector<int> x;
        int max_count = 0;
        int L, R, templ = 0, tempr = 0, c = 0, d = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == '1')
                c++;
            if (A[i] == '0')
                d++;
        }
        if (c == A.size())
            return x;
        if (d == A.size())
        {
            x.push_back(1);
            x.push_back(A.size());
            return x;
        }
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == '0')
            {
                count++;
                tempr = i;
            }
            else if (A[i] == '1')
            {
                count--;
                if (count < 0)
                {
                    count = 0;
                    templ = i + 1;
                    tempr = i + 1;
                }
            }

            if (count > max_count)
            {
                max_count = count;
                L = templ;
                R = tempr;
            }
        }
        if (max_count == 0)
            return x;
        else
        {
            x.push_back(L + 1);
            x.push_back(R + 1);
            return x;
        }
    }
};

