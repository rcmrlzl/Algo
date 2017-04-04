#include<iostream>
using namespace std;
void Matrix(int *p,int m[6][6],int s[6][6],int n){
		int q = 0;
		int j = 0;
	for(int i=0;i<n;i++)	
		m[i][i] = 0;
	for(int l=2;l<=n;l++){
		for(int i=0;i<n-l+1;i++){
			j = i+l-1;
			m[i][j] = 100000;
			for(int k=i;k<j;k++){
				q = m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print(int s[6][6],int i,int j){
	if(i==j){
		cout<<"A"<<i+1;
	}
	else{
		cout<<"(";
		print(s,i,s[i][j]);
		print(s,s[i][j]+1,j);
		cout<<")";
	}
}

int main(){
	int p[7] = {30,35,15,5,10,20,25};
	int m[6][6] = {0};
	int s[6][6] = {0};
	int n=6;
	Matrix(p,m,s,n);
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			if(m[i][j]!=0&&s[i][j]!=0){
			cout<<"m"<<"["<<i<<"]"<<"["<<j<<"]="<<m[i][j]<<"  ";
			cout<<"s"<<"["<<i<<"]"<<"["<<j<<"]="<<s[i][j]<<endl;
			}
	cout<<endl<<"最后的括号分化为：";
	print(s,0,5);
	return 0;
}