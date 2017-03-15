#include<iostream>
using namespace std;
void Merge(int a[], int p,int q,int r)
{
    int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	for(int i=0;i<n1;i++){
		L[i] = a[p+i];
	}
	
	for(int j=0;j<n2;j++){
		R[j] = a[q+j+1];
	}
	L[n1] = 1000000;
	R[n2] = 1000000;
	int i=0,j=0;
	for(int k=p;k<=r;k++){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;}
		else {a[k] = R[j];
		j++;}
	}
	delete[] L;
	delete[] R;
}
void MergeSort(int a[],int p,int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
} 

int main()
{
	int a[6] = {4,6,1,2,9,5};
	MergeSort(a,0,5);
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
}