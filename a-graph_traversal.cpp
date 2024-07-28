#include<bits/stdc++.h>
using namespace std;
// BREADTH FIRST SEARCH 
vector<int>bfsTraversal(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    vector<int>ans;
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while(q.empty()==false){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        int n = adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor = adj[node][i];
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    return ans;
}
// DEPTH FIRST SEARCH 
void dfsFunction(int node,vector<int>&ans,vector<bool>&visited,vector<int>adj[]){
    visited[node]=true;
    int n = adj[node].size();
    ans.push_back(node);
    for(int i = 0; i<n ; i++){
        int neighbor = adj[node][i];
        if(visited[neighbor]==false){
            dfsFunction(neighbor,ans,visited,adj);
        }
    }
}
vector<int>dfsTraversal(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    int start = 0;
    vector<int>ans;
    dfsFunction(start,ans,visited,adj);
    return ans;
}