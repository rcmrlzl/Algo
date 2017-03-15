#include<iostream>
#include<algorithm>
using namespace std;

void MaxHeap(int a[],int i,int max){
	int l = 2*i;
	int r = l+1;
	int largest =i;
	if(l<max&&a[i]<a[l]){
		 largest = l;
	}
	if(r<max&&a[largest]<a[r])
		largest = r;
	if(largest!=i){
		swap(a[i],a[largest]);
		MaxHeap(a,largest,max);
	}
}

void BuildHeap(int a[],int max){
	for(int i=max/2-1;i>=0;--i){
		MaxHeap(a,i,max);
	}
}

void HeapSort(int a[],int max)
{
	int heapsize  = max;
	BuildHeap(a,heapsize);
	for(int i=heapsize-1;i>=1;--i){
		swap(a[i],a[0]);
		MaxHeap(a,0,i);
	}
}

int main(){
	int a[6] = {4,1,5,3,9,7};
	HeapSort(a,6);
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}