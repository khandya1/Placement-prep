//   https://leetcode.com/problems/find-and-replace-pattern/      
// problem 890

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        for(string x : words)
        {
            if(match(x)==match(pattern))
                ans.push_back(x);
        }
        return ans;
    }
    string match(string x)
    {
        unordered_map<char,char> check;
        char c = 'a';
        for(int i=0;i<x.size();i++)
        {
            if(check.find(x[i])==check.end())
                check[x[i]]=c++;
        }
        for(int i=0;i<x.size();i++)
        {
                x[i]= check[x[i]];
        }
        return x;
        
    }
};