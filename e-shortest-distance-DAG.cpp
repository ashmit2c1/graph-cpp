#include<bits/stdc++.h>
using namespace std;
// find the shortest distance between nodes in directed acyclic graph 
void topoSortFunction(int node,stack<int>&st,vector<bool>&visited,vector<pair<int,int>>adj[]){
    visited[node]=true;int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i].first;
        if(visited[neighbor]==false){topoSortFunction(neighbor,st,visited,adj);}
    }st.push(node);
}
vector<int>shortestPath(int N,int M,vector<vector<int>>edges){
    vector<pair<int,int>>adj[N];
    for(int i=0;i<M;i++){
        int u=edges[i][0];int v=edges[i][1];int weight=edges[i][2];
        adj[u].push_back(make_pair(v,weight));
    }stack<int>st;vector<bool>visited(N,false);
    topoSortFunction(0,st,visited,adj);vector<int>distance(N,INT_MAX);
    while(st.empty()==false){
        int node=st.top();st.pop();
        int n=adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor=adj[node][i].first;int weight=adj[node][i].second;
            distance[neighbor]=min(distance[neighbor],weight+distance[node]);
        }
    }return distance;
}
