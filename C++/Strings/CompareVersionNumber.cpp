// Run a single loop over both the strings, v1 and v2.
// Keep two temporary strings, s1 and s2 to accumulate the characters of v1 and v2, respectively, till you encounter .
// Now, it's time to compare the strings, s1 and s2. First, compare their lengths. The larger length string is greater than the other, according to the question. If they have the same lengths, then you need to compare them lexicographically. Use s1.compare(s2) for this.
// Return the result accordingly.
// Here 0 is not to be counted , we have to check for each number between '.'
//https://leetcode.com/problems/compare-version-numbers/
// lc 165
// https://www.interviewbit.com/problems/compare-version-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int ans = 0;
        int n1 = v1.size(), n2 = v2.size();
        
        for(int i=0,j=0; i<n1 || j<n2; ++i, ++j) {
            
            string s1 = "", s2 = "";

            while(i<n1 && v1[i] != '.') {
                if(s1.size() == 0 && v1[i] == '0') {
                    ++i; continue;
                }
                
                s1 += v1[i++];
            }
            
            while(j<n2 && v2[j] != '.') {
                if(s2.size() == 0 && v2[j] == '0') {
                    ++j; continue;
                }
                
                s2 += v2[j++];
            }
            
            if(s1.size() < s2.size()) return -1;
            else if(s2.size() < s1.size()) return 1;
            
            ans = s1.compare(s2);
            if(ans < 0) return -1;
            else if(ans > 0) return 1;
        }
        
        return 0;
        
    }
};