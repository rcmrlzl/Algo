#include<iostream>
using namespace std;
int maxSubArray(int a[],int nums) {
        int sum = 0, minSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums; i++) {
            sum += a[i];
            maxSum = max(maxSum, sum - minSum);
            minSum = min(minSum, sum);
        }
        return maxSum;
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