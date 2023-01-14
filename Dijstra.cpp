#include <iostream>
#include <vector>

using namespace std;

int minDistance(vector<bool> &mstSet, vector<int> &dist, int no_of_nodes) {
    int min=INT_MAX;
    int min_idx=0;
    for(int v=0;v<no_of_nodes;v++) {
        if(mstSet[v]==false && dist[v]<=min) {
            min=dist[v];
            min_idx=v;
        }
    }
    return min_idx;
}

void prin(vector<int> & dist, int no_of_nodes) {
    cout<<"city"<<" "<<"shortest ditance from the city:"<<endl;
    for(int i=0;i<no_of_nodes;i++) {
        cout<<i<<" "<<dist[i];
    }
    cout<<endl;
}


void Dijkstra(vector<vector<int>> & graph, int no_of_nodes) {
    int src;
    vector<bool> mstSet;
    vector<int> dist;
    cout<<"enter the source node:"<<endl;
    cin>>src;
    for(int i=0;i<no_of_nodes;i++) {
        mstSet[i]=false;
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    for(int i=0;i<no_of_nodes;i++) {
        int u=minDistance(mstSet,dist,no_of_nodes);
        mstSet[u]=true;
        for(int v=0;v<no_of_nodes;v++) {
            if(mstSet[v]==false && graph[u][v] && dist[u]+graph[u][v]<dist[v] && dist[u]!=INT_MAX) {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    prin(dist,no_of_nodes);
}

int main() {
    vector<vector<int>> graph;
    int no_of_nodes=0;
    cout<<"enter the no of nodes"<<endl;
    cin>>no_of_nodes;
    cout<<"enter the distances for each pair of cities:"<<endl;
    for(int i=0;i<no_of_nodes;i++) {
        for(int j=0;j<no_of_nodes;j++) {
            cin>>graph[i][j];
        }
    }
    Dijkstra(graph,no_of_nodes);
    return 0;
}
