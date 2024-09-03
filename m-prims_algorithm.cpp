#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";
// find the total weight of the min spanning tree using prim's algorithm
ll spanningTree(ll V,vector<vector<int>>adj[]){
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>,greater<pair<ll,pair<ll,ll>>>>>pq;
    vector<bool>isMST(V,false);vector<ll>parent(V);ll cost=0;
    pq.push({0,{0,-1}});
    while(pq.empty()==false){
        ll weight=pq.top().first;
        ll node=pq.top().second.first;
        ll par=pq.top().second.second;
        pq.pop();
        if(isMST[node]==false){
            isMST[node]=true;
            parent[node]=par;
            cost+=weight;
            ll n =adj[node].size();
            forloop(0,n){
                ll neighbor=adj[node][i][0];
                ll edgeWeight=adj[node][i][1];
                if(isMST[neighbor]==false){
                    pq.push({edgeWeight,{neighbor,node}});
                }
            }
        }
    }
    return cost;
}
