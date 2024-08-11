#include<bits/stdc++.h>
using namespace std;

// check whether graph is bipartite using dfs 
bool checkFor(int node,vector<int>&color,vector<int>adj[]){
    int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i];
        if(color[neighbor]==-1){
            color[neighbor]=1-color[node];
            if(checkFor(neighbor,color,adj)==false){return false;}
        }
    }return true;
}
bool isBipartite(int V,vector<int>adj[]){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;
            if(checkFor(i,color,adj)==false){return false;}
        }
    }return true;
}
// check whether the graph is bipartite or not using bfs 
bool isBipartite(int V,vector<int>adj[]){
    vector<int>color(V,-1);queue<int>q;
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;q.push(i);
            while(q.empty()==false){
                int node=q.front();q.pop();
                int n=adj[node].size();
                for(int j=0;j<n;j++){
                    int neighbor=adj[node][i];
                    if(color[neighbor]==-1){
                        color[neighbor]=1-color[node];
                        q.push(neighbor);
                    }
                    else{
                        if(color[neighbor]==color[node]){return false;}
                    }
                }
            }
        }
    }return true;
}
