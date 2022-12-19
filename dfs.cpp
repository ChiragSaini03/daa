#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > adj;
 
void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void dfs(int start, vector<bool>& visited)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < adj[start].size(); i++) {
        if (adj[start][i] == 1 && (!visited[i])) {
            dfs(i, visited);
        }
    }
}
 
int main()
{
    int v = 5;
    int e = 4;
    cin>>e;
    adj = vector<vector<int> >(v, vector<int>(v, 0));
    for (int i=0;i<e;i++){
        int n,m;
        cin>>n>>m;
        addEdge(n,m);
    }
    vector<bool> visited(v, false);
    dfs(0, visited);
}
