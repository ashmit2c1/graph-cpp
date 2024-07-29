#include<bits/stdc++.h>
using namespace std;
// TOPOLOGICAL SORT 
void topoSortFunction(int node,vector<bool>&visited,stack<int>&st,vector<int>adj[]){
    visited[node]=true;
    int n = adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor = adj[node][i];
        if(visited[neighbor]==false){
            topoSortFunction(neighbor,visited,st,adj);
        }
    }
    st.push(node);
}
vector<int>topologicalSort(int V,vector<int>adj[]){
    vector<int>ans;
    stack<int>st;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topoSortFunction(i,visited,st,adj);
        }
    }
    while(st.empty()==false){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// KAHNS ALGORITHM ( TOPOLOGICAL SORT USING BFS )
vector<int>kahnsAlgorithm(int V,vector<int>adj[]){
    vector<int>ans;
    vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
        int n = adj[i].size();
        for(int j=0;j<n;j++){
            int node = adj[i][j];
            inDegree[node]++;
        }
    }
    queue<int>q;
    for(int i = 0; i<V; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(q.empty()==false){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        int n = adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor = adj[node][i];
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    return ans;
}