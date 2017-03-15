#include<iostream>
using namespace std;

void IS(int a[],int n)
{
	for(int j=1;j<n;j++)
	{
		int key = a[j];
		int i=j-1;
		while(i>=0&a[i]>key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

int main()
{
	int a[6] = {2,6,8,4,1,5};
	IS(a,6);
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}