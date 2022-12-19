/**
 * @file 69__DJkstraALgo.cpp
 * @author Chirag Saini
 * @brief single source shortest path
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int dijkstra(int v, vector<vector<int>> edges){
      // creating adjacency list
      unordered_map<int,vector<pair<int,int>>> adj;
      
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<vector<int>> edges;
    for (int i=0;i<e;i++){
        int n,m;
        cin>>n>>m;
        edges.push_back({n,m});
    }
    cout<<dijkstra(v,edges);
    return 0;
}