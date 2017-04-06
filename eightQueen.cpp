#include <iostream>  
#include <cmath>  
#include <cstring>  
using namespace std;  
  
int queen[9];  
  
//数组初始化  
void init()  
{  
    memset(queen,0,9*sizeof(int));  
}  
  
//输出结果  
void print()  
{  
    for(int i=1; i<9; i++) cout<<queen[i]<<"  ";  
    cout<<endl;  
}  
  
//剪枝函数  
bool canPlaceQueen(int k)  
{  
    for(int i = 1; i < k; i++)  
    {  
        //判断是否处于同一列或同一斜线  
        if(queen[i] == queen[k] || abs(k-i) == abs(queen[k]-queen[i])) return false;  
    }  
    return true;  
}  
//迭代方法求解八皇后过程  
void eightQueen_1()  
{  
    int k = 1;  
    while(k>=1)  
    {  
        while(queen[k]<=7)  
        {  
            queen[k] += 1;  
            if(k == 8 && canPlaceQueen(k))  
            {  
                print();  
            }  
            else if(canPlaceQueen(k))  
            {  
                k++;  
            }  
        }  
        queen[k] = 0;  
        k--;  
    }  
}  
  
//递归方法求解八皇后过程  
void eightQueen_2(int k)  
{  
    for(int i=1; i<9; i++)  
    {  
        queen[k] = i;  
        if(k == 8 && canPlaceQueen(k))  
        {  
            print();  
            return;  
        }  
        else if(canPlaceQueen(k))  
        {  
            eightQueen_2(k+1);  
        }  
    }  
}  
int main()  
{  
    init();  
    eightQueen_1();  
//    eightQueen_2(1);  
    return 0;  
} 