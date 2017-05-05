#include<iostream>
using namespace std;
int maxSubArray(vector<int> nums){
	int res = INT_MIN,sum = 0;
	for(int num:nums){
		sum = max(sum+num,num);
		res = max(res,sum);
	}
	return res;
}

int main(){
	int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
	int re = maxSubArray(a,9);
	int sum = 0;
	for(int i=0;i<9;i++){
		sum +=a[i];
	}
	cout<<sum<<endl;
	cout<<re<<endl;
	return 0;
}
