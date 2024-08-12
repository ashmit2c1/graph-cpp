#include<bits/stdc++.h>
using namespace std;

// DIJKSTRA ALGORITHM 
vector<int>dijkstraAlgorithm(int V,vector<vector<int>>adj[],int src){
    vector<bool>visited(V,false);
    vector<int>distance(V,INT_MAX);
    distance[src]=0;
    for(int cnt=0;cnt<V-1;cnt++){
        int node=-1;int value=INT_MAX;
        for(int i=0;i<V;i++){
            if(visited[i]==false && distance[i]<value){
                node=i;
                value=distance[i];
            }
        }
        if(node==-1){
            break;
        }
        visited[node]=true;int n=adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor=adj[node][i][0];int weight=adj[node][i][1];
            if(visited[neighbor]==false && distance[neighbor]>distance[node]+weight){
                distance[neighbor]=distance[node]+weight;
            }
        }
    }
    return distance;
}
