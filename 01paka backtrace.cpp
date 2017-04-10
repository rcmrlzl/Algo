#include<iostream>
using namespace std;
int n,c,bestp;//物品的个数，背包的容量，最大价值
int p[10000],w[10000],x[10000],bestx[10000];//物品的价值，物品的重量，x[i]暂存物品的选中情况,物品的选中情况

double Backtrack(int i,int cp,int cw)
{ //cw当前包内物品重量，cp当前包内物品价值
    int j;
    double sum = 0;
    if(i>n)//回溯结束
    {
        if(cp>bestp)
        {
            bestp=cp;
            for(i=0;i<=n;i++) bestx[i]=x[i];
        }
    }
    else
        for(j=0;j<=1;j++)
        {
            x[i]=j;
            if(cw+x[i]*w[i]<=c)
            {
                cw+=w[i]*x[i];
                cp+=p[i]*x[i];
                Backtrack(i+1,cp,cw);
                cw-=w[i]*x[i];
                cp-=p[i]*x[i];
            }
        }
    for(int i=0;i<n;i++){
        if(bestx[i] == 1){
            sum+=p[i];
        }
    }
    return sum;
}

int main()
{
    int i;
    bestp=0;
    cout<<"请输入最大背包容量:"<<endl;
    cin>>c;
    cout<<"请输入物品个数:"<<endl;
    cin>>n;
    cout<<"请依次输入物品重量:"<<endl;
    for(i=1;i<=n;i++)
        cin>>w[i];
    cout<<"请输入物品的价值:"<<endl;
    for(i=1;i<=n;i++)
        cin>>p[i];
    double sum = Backtrack(1,0,0);
    cout<<"被选中的物品依次是(0表示未选中，1表示选中)"<<endl;;
    for(i=1;i<=n;i++)
        cout<<bestx[i];
    cout<<endl;
    cout<<"最大价值为:"<<sum<<endl;
    return 0;
}
