/**
 * @file 64__primsAlgo.cpp
 * @author Chirag Saini
 * @brief Algo to find minimum spanning tree in a graph
 *      n nodes
 *      n-1 edges
 *      no cycles
 *      each node are connected to the structure
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> primsMST(int v, vector<pair<pair<int,int>,int>> edges){
    // adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for (int i=0;i<edges.size();i++){
        int u=edges[i].first.first;
        int v=edges[i].first.second;
        adj[u].push_back(make_pair(v,edges[i].second));
        adj[v].push_back(make_pair(u,edges[i].second));
    }
    vector<int> key(v+1,INT_MAX);
    vector<bool> mst(v+1,false);
    vector<int> parent(v+1,-1);
    // algo
    
}

int main(){
    int v;
    cin>>v;
    int noedges;
    cin>>noedges;
    vector<pair<pair<int,int>,int>> edges;
    for (int i=0;i<noedges;i++){
        int n,m;
        cin>>n>>m;
        int weight;
        cin>>weight;
        edges.push_back(make_pair(make_pair(n,m),weight));`
    }

    return 0;
}