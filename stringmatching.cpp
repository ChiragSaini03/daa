#include <bits/stdc++.h>
using namespace std;


// Brute Force
pair<int,int> BruteForce(string T,string P){
    int cmp=0;
    pair<int,int> p;
    p.first=-1;
    for (int  i=0;i<=T.size()-P.size();i++){
        cmp+=P.size();
        if (T.substr(i,P.size())==P){
            p.first=i;
            p.second=cmp;
            return p;
        }
    }
    p.second=cmp;
    return p;
}


// Boyer Moore Algorithm
# define NO_OF_CHARS 256 

void badCharHeuristic( string str, int size, int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;
	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}

int search( string txt, string pat,int &cmp)
{
	int m = pat.size();
	int n = txt.size();
	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, badchar);
	int s = 0; 
	while(s <= (n - m))
	{
		int j = m - 1;
        cmp++;
		while(j >= 0 && pat[j] == txt[s + j]){
            cmp++;
			j--;}
		if (j < 0)
		{
			return s;
			s += (s + m < n)? m-badchar[txt[s + m]] : 1;
		}
		else
			s += max(1, j - badchar[txt[s + j]]);
    }
    return -1;
}

pair<int,int> boyerMoore(string T,string P){
    pair <int,int> ans;
    int cmp=0;
    ans.first=search(T,P,cmp);
    ans.second=cmp;
    return ans;
}


// KMP Algorithm
vector<int> prefix_arr(string s,int &cmp){
    int n=s.size();
    vector<int> pi(n,0);
    for (int i=1;i<n;i++){
        int j=pi[i-1];
        while (j>0 &&  s[i]!=s[j]){
            j=pi[j-1];
        }
        cmp++;
        if (s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
}
pair<int,int> KMP(string T,string P){
    pair <int,int> ans;
    int cmp=0;
    ans.first=-1;
    vector<int> prefix=prefix_arr(P,cmp);
    int i=0,j=0;
    while (i<T.size()){
        cmp++;
        if (T[i]==P[j]){
            i++;
            j++;
        }
        else{
            cmp++;
            if (j!=0){
                j=prefix[j-1];
            }
            else{
                i++;
            }
        }
        if (j==P.size()){
            ans.first=i-P.size();
            break;
        }
    }
    ans.second=cmp;
    return ans;
}


int main(){
    string T,P;
    cin>>T;
    cin>>P;
    pair<int,int> bruteForce=BruteForce(T,P);
    pair<int,int> boyer=boyerMoore(T,P);
    pair<int,int> kmp=KMP(T,P);
    cout<<endl;
    cout<<"Algorithm \t \t Found at "<<"\t Comparisons done\n";
    cout<<"Brute Force \t \t "<<bruteForce.first<<" \t \t "<<bruteForce.second<<"\n";
    cout<<"Boyer Moore Algo \t "<<boyer.first<<"\t \t "<<boyer.second<<"\n";
    cout<<"KMP Algo \t \t "<<kmp.first<<"\t \t "<<kmp.second<<"\n";
    cout<<endl;
    return 0;
}