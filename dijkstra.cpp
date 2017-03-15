#include<iostream>
#include<algorithm>
using namespace std;
#define MAXNUM 100
#define MAXINT 100000
int dist[MAXNUM];
int m,n;
bool S[MAXNUM];
void dijkstra(int A[][MAXNUM],int v){
	int prev[100];
	for(int i=1;i<=v;i++){
		dist[i] = A[1][i];
		S[i] = false;
		if(dist[i] == MAXINT)
			prev[i] = -1;
		else prev[i] = 1;
	}

	dist[1] = 0;
	S[1] = true;

	for(int i=2;i<=v;i++){
		int mindist = MAXINT;
		int u;
		for(int j=1;j<=v;j++){
			if(S[j]==0&&dist[j]<mindist){
				mindist = dist[j];
				u = j;
			}
		}
		cout<<"u="<<u<<endl;
		S[u] = true;
		for(int j=1;j<=v;j++){
			if(S[j]==0&&A[u][j]<MAXINT){
				if(dist[u]+A[u][j]<dist[j]){
					dist[j] = dist[u]+A[u][j];
					prev[j] = u;
				}
			}
		}
	}
}

int main(){

	int v1,v2,cost;
	int a[MAXNUM][MAXNUM];
	for(int i=0;i<MAXNUM;i++){
		for(int j=0;j<MAXNUM;j++){
			a[i][j] = MAXINT;
		}
	}
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>v1>>v2>>cost;
		a[v1][v2] = cost;
		a[v2][v1] = cost;
	}
	dijkstra(a,m);
	for(int i=1;i<=m;i++){
		cout<<dist[i]<<endl;
	}
	cout<<dist[5];
	return 0;
}