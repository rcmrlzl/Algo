#include<stdio.h>
#include<string.h>
#define N 3//作业数目
#define MAX 1000
int x[N+1]={0,1,2,3};
int m[3][N+1]={
            0,0,0,0,
    0,2,3,2,
    0,1,1,3
};
int bestx[N+1];//用于保存结果调度顺序
int f2[N+1];//第i阶段机器2完成处理的时间
int f1=0;//机器1完成处理时间
int f=0;//当前完成时间和
int bestf=MAX;
void swap(int &a,int &b)
{
        int temp=a;
        a=b;
        b=temp;
}


void Backtrace(int t)
{
        if(t>N)
            {
                    bestf=f;
                    for(int i=1;i<=N;i++)
                        {
                                bestx[i]=x[i];
                            }
                }
        else
            {
                    for(int i=t;i<=N;i++)
                        {
                      swap(x[t],x[i]);
                                f1+=m[1][x[t]];
                                f2[t]=(f2[t-1]>f1?f2[t-1]:f1)+m[2][x[t]];
                                f+=f2[t];
                                
                                if(f<bestf)
                                    {
                                            Backtrace(t+1);
                                        }
                                
                                f1-=m[1][x[t]];
                                f-=f2[t];     //这里要注意递归回来后恢复原先的值！！！！！！！！！！
                    swap(x[t],x[i]);
                }
                }
}


int main()
{
        memset(bestx,0,(N+1)*sizeof(int));
        memset(f2,0,(N+1)*sizeof(int));
        Backtrace(1);
        printf("该作业调度的最优完成时间和为：%d\n调度顺序为：\n",bestf);
        for(int i=1;i<=N;i++)
            {
                    printf("%d ",bestx[i]);
                }
    printf("\n");
        return 0;
}
