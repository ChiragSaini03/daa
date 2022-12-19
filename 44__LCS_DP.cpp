// Longest Common Subsequence
// abcd
// aadheb
// common subsequence:- ab,ad
#include <iostream>
#include <string>
using namespace std;


int lcs(string _s, string s_){      // brute force
    // base case
    if (_s.size()==0 || s_.size()==0) return 0;
    // recursive calls
    if (_s[0]==s_[0]){
        return 1+lcs(_s.substr(1),s_.substr(1));
    }
    int a=lcs(_s.substr(1),s_);
    int b=lcs(_s,s_.substr(1));
    int c=lcs(_s.substr(1),s_.substr(1));
    return max(a,max(b,c));
}

int lcsMemo(string _s, string s_, int ** dp){      // memoisation
    // base case
    if (_s.size()==0 || s_.size()==0) return 0;
    // checking
    if (dp[_s.size()][s_.size()]!=-1) return dp[_s.size()][s_.size()];
    // recursive calls
    int ans;
    if (_s[0]==s_[0]){
        ans= 1+lcsMemo(_s.substr(1),s_.substr(1),dp);
        dp[_s.size()][s_.size()]=ans;
        return ans;
    }
    int a=lcsMemo(_s.substr(1),s_,dp);
    int b=lcsMemo(_s,s_.substr(1),dp);
    int c=lcsMemo(_s.substr(1),s_.substr(1),dp);
    ans=max(a,max(b,c));
    dp[_s.size()][s_.size()]=ans;
    return ans;
}

int lcsDP(string _s, string s_){
    return 1;
}

int main(){
    string a="abcd";
    string b="badce";  
    int ** dp=new int*[a.size()+1];
    for (int i=0;i<=a.size();i++){
        dp[i]=new int [b.size()+1];
    }
    for (int i=0;i<=a.size();i++){
        for (int j=0;j<=b.size();j++){
            dp[i][j]=-1;
        }
    }
    cout<<lcsMemo(a,b,dp);
    return 0;
}