#include<bits/stdc++.h>
using namespace std;
// find the distance from source node to all nodes in undirected unweight graph 
vector<int>shortestPath(int N,int M,int src,vector<vector<int>>edges){
    vector<vector<int>>adj(N);
    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }vector<int>distance(N,-1);vector<bool>visited(N,false);
    queue<int>q;visited[src]=true;distance[src]=0;q.push(src);
    while(q.empty()==false){
        int node=q.front();q.pop();int n=adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==true){continue;}
            else{visited[neighbor]=true;
            distance[neighbor]=1+distance[node];q.push(neighbor);}
        }
    }return distance;

}
