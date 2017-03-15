#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_V 100000
#define MAX_E 100000
int fa[MAX_V];
int v,l;
struct Edge{ 
     int fm,to,cost;      
}e[MAX_E];

bool cmp(Edge a,Edge b){
	return a.cost<b.cost;
}

int getfa(int x){
	if(x == fa[x]) return fa[x];
	else return fa[x] = getfa(fa[x]);
}

int same(int x,int y){
	return getfa(x) == getfa(y);
}

void merge(int x,int y){
	int fax = getfa(x),fay = getfa(y);
	fa[fax] = fay;
}

int kruskal(Edge e[MAX_E]){
	sort(e+1,e+l+1,cmp);
	for(int i=1;i<=v;i++){
		fa[i] = i;	
	}
	int rst = v,sum = 0;
	for(int i=1;i<=l&&rst>1;i++){
		int x = e[i].fm,y = e[i].to;
		if(same(x,y)) continue;
		else{
			merge(x,y);
			rst--;
			sum+=e[i].cost;
		}
	}
	return sum;
}

int main(){
	cin>>v>>l;
	for(int i=0;i<l;i++){
		cin>>e[i].fm>>e[i].to>>e[i].cost;
	}
	int sum = kruskal(e);
	cout<<"最小权值为："<<sum<<endl;
	return 0;
}