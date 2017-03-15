//
//  main.cpp
//  QuickSort
//
//  Created by mson on 2017/2/28.
//  Copyright © 2017年 mson. All rights reserved.
//

#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}

int partition(int a[],int p,int r){
    int i = p-1;
    for(int j=p;j<r;j++){
        if(a[j]<=a[r]){
           swap(a[++i], a[j]);
        }
    }
    swap(a[++i],a[r]);
    return i;
}

void QuickSort(int a[],int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

int main(int argc, const char * argv[]) {
    int a[7] ={3,7,9,8,4,6,5};
    int x=0,y=1;
    swap(x,y);
    cout<<"x="<<x<<" "<<"y="<<y<<endl;
    QuickSort(a,0,6);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
