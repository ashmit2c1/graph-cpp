#include<bits/stdc++.h>
using namespace std;
// CYCLE DETECTION IN UNDIRECTED GRAPH USING BFS
bool checkForCycle(int node,vector<bool>&visited,vector<int>adj[]){
    queue<pair<int,int>>q;
    visited[node]=true;
    q.push(make_pair(node,-1));
    while(q.empty()==false){
        int node = q.front().first;
        int parent = q.front().second;
        int n = adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor = adj[node][i];
            if(neighbor==parent){
                continue;
            }
            if(visited[neighbor]==true){
                return true;
            }
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                q.push(make_pair(neighbor,node));
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(checkForCycle(i,visited,adj)==true){
            return true;
        }
    }
    return false;
}
// CYCLE DETECTION IN UNDIRECTED GRAPH USING DFS
bool checkForCycle(int node,int parent,vector<bool>&visited,vector<int>adj[]){
    visited[node]=true;
    int n = adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor = adj[node][i];
        if(neighbor==parent){
            continue;
        }
        if(visited[neighbor]==true){
            return true;
        }
        if(visited[neighbor]==false){
            if(checkForCycle(neighbor,node,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(checkForCycle(i,-1,visited,adj)==true){
            return true;
        }
    }
    return false;
}