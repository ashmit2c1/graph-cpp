#include<bits/stdc++.h>
using namespace std;
// 2 MEANS EULER CIRCUIT ( AND EULER PATH )
// 1 MEANS EULER PATH AND NOT EULER CIRCUIT 
// 0 MEANS NO EULER PATH ( HENCE NO CIRCUIT )
void dfsFunction(int node,vector<bool>&visited,vector<int>adj[]){
    visited[node]=true;int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){dfsFunction(neighbor,visited,adj);}
    }
}
int isEuler(int V,vector<int>adj[]){
    vector<int>degree(V,0);int odd=0;
    vector<bool>visited(V,false);
    for(int i = 0; i<V ; i++){
        degree[i]=adj[i].size();
        if(degree[i]%2!=0){odd++;}
    }
    if(odd!=0 & odd!=2){return 0;}
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfsFunction(i,visited,adj);
        }
    }
    for(int i=0;i<V;i++){
        if(degree[i]!=0 && visited[i]==false){return 0;}
    }
    if(odd==0){return 2;}
    else if(odd==2){return 1;}
    else{return 0;}
}
