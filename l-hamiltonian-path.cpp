#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define for(x,y) for(int i=x;i<y;i++)

bool dfsHamPath(int node,vector<bool>&visited,vector<vector<int>>adj,int&cnt,int N){
    visited[node]=true;int n=adj[node].size();cnt++;
    if(cnt==N){return true;}
    for(0,n){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            if(dfsHamPath(neighbor,visited,adj,cnt,N)==true){return true;}
        }
    }
    visited[node]=false;cnt--;return false;
}

bool check(int N,int M,vector<vector<int>>edges){
    vector<vector<int>>adj(N);
    for(0,M){
        adj[edges[i][0]-1].push_back(edges[i][1]-1);
        adj[edges[i][1]-1].push_back(edges[i][0]-1);
    }
    vector<bool>visited(N,false);int cnt=0;
    for(0,N){
        if(dfsHamPath(i,visited,adj,cnt,N)==true){return true;}
    }
    return false;
}

int main(){
    int n=4;int m=4;
    vector<vector<int>>edges={ {1,2}, {2,3}, {3,4}, {2,4} };
    bool ans=check(n,m,edges);
    if(ans==true){cout << 1 << "\n";}
    else{cout << 0 << "\n";}
}
