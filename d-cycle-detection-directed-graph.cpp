#include<bits/stdc++.h>
using namespace std;

// detect cycle in directed graph  using dfs
bool checkForCycle(int node,vector<bool>&visited,vector<bool>&path,vector<int>adj[]){
    visited[node]=true;path[node]=true;int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(path[neighbor]){return true;}
        if(visited[neighbor]==true){continue;}
        if(visited[neighbor]==false){
            if(checkForCycle(neighbor,visited,path,adj)==true){return true;}
        }
    }
    path[node]=false;
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,false);vector<bool>path(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(checkForCycle(i,visited,path,adj)==true){return true;}
        }
    }return false;
}
// detect cycle in directed graph using bfs 
bool isCycle(int V,vector<int>adj[]){
    vector<int>ans;vector<int>inDegree(V,0);queue<int>q;
    for(int i=0;i<V;i++){
        int n=adj[i].size();
        for(int j=0;j<n;j++){
            int node=adj[i][j];inDegree[node]++;
        }
    }
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){q.push(i);}
    }
    while(q.empty()==false){
        int node=q.front();q.pop();int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];inDegree[neighbor]--;
            if(inDegree[neighbor]==0){q.push(neighbor);}
        }
    }
    int cnt=ans.size();
    if(cnt!=V){return true;}//cycle exists
    else{return false;}//cycle does not exist
}
