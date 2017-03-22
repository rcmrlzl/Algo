#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
struct TH{
	double w;
	double v;
}obj[];
bool cmp(TH a,TH b){
	return a.v/a.w>b.v/b.w;
}
int Greedy(TH obj[],int x,int y){
	sort(obj,obj+x,cmp);
	double allw = 0,sum = 0;
	int i=0,u = 0;
	while(allw<y){
		if(allw<y){
			allw+=obj[i].w;
			sum+=obj[i].v;
		}else
			allw-=obj[i].w;
			u = i;
		++i;
	}
	sum-=obj[u].v;
	allw-=obj[u].w;
	if(y-allw){
		sum+=obj[u].v/obj[u].w*(y-allw);
	}
	allw+=(y-allw);
	cout<<"装入的总重量为："<<allw<<endl;
	return sum;
}
int main(){
	double s,n;
	cout<<"请输入背包容量：";
	cin>>s;
	cout<<"请输入物品的个数：";
	cin>>n;
	cout<<"请输入物品的重量：";
	TH t[MAX];
	for(int i=0;i<n;i++){
		cin>>t[i].w;
	}
	cout<<"请输入物品的价值：";
	for(int j=0;j<n;j++){
		cin>>t[j].v;
	}
	double sum = Greedy(t,n,s);
	cout<<"装入物品最大总价值为："<<sum<<endl;
	return 0 ;
}