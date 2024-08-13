#include<bits/stdc++.h>
using namespace std;
// FLOYD WARSHALL 
void floydWarshall(vector<vector<int>>&matrix){
    int n=matrix.size();int infinity=INT_MAX/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1 && i!=j){
                matrix[i][j]=infinity;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][k]!=infinity && matrix[k][j]!=infinity){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==infinity){
                matrix[i][j]=-1;
            }
        }
    }
}
