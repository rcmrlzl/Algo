#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
#define MAXCOST 100000000
int Prime(int graph[][MAX],int n){
    int lowcost[MAX];
    int mst[MAX];
    int i,j, min,minid,sum = 0;
    for(i=2;i<=n;i++){
        lowcost[i] = graph[1][i];
        mst[i] = 1;
    }
    mst[1] = 0;
    for(i=2;i<=n;i++){
        min = MAXCOST;
        minid = 1;
        for(j=2;j<=n;j++){
            if(lowcost[j]<min&&lowcost[j]!=0){
                min = lowcost[j];
                minid = j;
            }
        }
        cout<<"V"<<mst[minid]<<"-"<<"V"<<minid<<":"<<min<<endl;
        lowcost[minid] = 0;
        sum+=min;
        for(j=2;j<=n;j++){
            if(graph[minid][j]<lowcost[j]){
                lowcost[j] = graph[minid][j];
                mst[j] = minid;
            }
        }
    }
    return sum;
}

int graph[MAX][MAX];
int main() {
    int m,n;
    int v1,v2,cost;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            graph[i][j] = MAX;
            graph[j][i] = MAX;
        }
    }
    for(int i=0;i<n;i++){
        cin>>v1>>v2>>cost;
        graph[v1][v2] = cost;
        graph[v2][v1] = cost;
    }
    int sum = Prime(graph, m);
    cout<<"最小权值为："<<sum<<endl;
    return 0;
}