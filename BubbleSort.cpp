#include <iostream>
#include <algorithm>
using namespace std;

void Bubblesort(int a[],int max){
    for(int i=0;i<max-1;i++){
        for(int j=max-1;j>i;j--){
            if(a[j]<a[j-1])
                std::swap(a[j], a[j-1]);
        }
    }
}

int main() {
    const int n =10;
    int a[n]={3,7,9,8,4,6,5,10,2,1};
    Bubblesort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
