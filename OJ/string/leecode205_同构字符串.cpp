/*************************************************************************
	> File Name: leecode205_同构字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/27 01:05:52 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    map<char,char> s2t;
    map<char,char> t2s;
    bool isIsomorphic(string s, string t) {
        if(s.size() == 0) return true;
        for(int i = 0; s[i]; i++){
            if(s2t.find(s[i]) == s2t.end())
                s2t.insert({s[i],t[i]});
            else if( (*(s2t.find(s[i]))).second != t[i] )
                return false;
            if(t2s.find(t[i]) == t2s.end())
                t2s.insert({t[i],s[i]});
            else if( (*(t2s.find(t[i]))).second != s[i] )
                return false;   
        
            
        }
        return true;
    }
};
