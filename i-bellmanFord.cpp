#include<bits/stdc++.h>
using namespace std;

// BELLMAN FORD ALGORITHM
vector<int>bellmanFordAlgorithm(int V,vector<vector<int>>edges,int src){
    int infinity=100000000;vector<int>distance(V,infinity);int n=edges.size();
    for(int cnt=0;cnt<V-1;cnt++){
        for(int i = 0; i<n ; i++){
            int u =edges[i][0];int v=edges[i][1];int weight=edges[i][2];
            if(distance[u]!=infinity && distance[u]+weight<distance[v]){
                distance[v]=distance[u]+weight;
            }
        }
    }
    for(int i = 0; i<n ; i++){
        int u=edges[i][0];int v=edges[i][1];int weight=edges[i][2];
        if(distance[u]!=infinity && distance[u]+weight<distance[v]){
            return {-1};
        }
    }
    for(int i=0;i<V;i++){if(distance[i]==infinity){distance[i]=-1;}}
    return distance;
}
