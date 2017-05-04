#include "stdafx.h"
#include "Queue.h"  
#include <fstream>   
#include <iostream>  
using namespace std;  
  
ifstream fin("6d4.txt");   
  
const int n = 7;  
const int m = 7;  
int grid[n+2][m+2];    
  
struct Position    
{    
    int row;    
    int col;    
};   
  
bool FindPath(Position start,Position finish,int& PathLen,Position *&path);  
  
int main()  
{  
    int PathLen;  
      
    Position start,finish,*path;  
  
    start.row = 3;  
    start.col = 2;  
  
    finish.row = 4;  
    finish.col = 6;  
  
    cout<<"�������"<<endl;    
    cout<<start.col<<" "<<start.row<<endl;    
    cout<<"���߽�����"<<endl;    
    cout<<finish.col<<" "<<finish.row<<endl;   
  
    cout<<"���߷�����������(0��ʾ�����ߣ�1��ʾ��������)��"<<endl;  
    for(int i=1; i<=m; i++)  
    {  
        for(int j=1; j<=n; j++)  
        {  
            fin>>grid[i][j];  
            cout<<grid[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
      
    FindPath(start,finish,PathLen,path);  
  
    cout<<"���߳���Ϊ:"<<PathLen<<endl;  
    cout<<"����·�����£�"<<endl;    
    for(int i=0; i<PathLen; i++)    
    {    
        cout<<path[i].col<<" "<<path[i].row<<endl;    
    }    
  
    return 0;  
}  
  
bool FindPath(Position start,Position finish,int& PathLen,Position *&path)  
{  
    //�������ʼλ��start��Ŀ��λ��finish����̲���·��  
    if((start.row == finish.row) && (start.col == finish.col))  
    {  
        PathLen = 0;  
        return true;  
    }  
  
    //���÷������С�Χǽ��  
    for(int i=0; i<= m+1; i++)  
    {  
        grid[0][i]=grid[n+1][i]=1; //�����͵ײ�  
    }  
    for(int i=0; i<= n+1; i++)  
    {  
        grid[i][0]=grid[i][m+1]=1; //���������  
    }  
  
    //��ʼ�����λ��  
    Position offset[4];  
  
    offset[0].row=0;  
    offset[0].col=1;//��  
  
    offset[1].row=1;   
    offset[1].col=0;//��  
  
    offset[2].row=0;   
    offset[2].col=-1;//��  
      
    offset[3].row=-1;  
    offset[3].col=0;//��  
      
    int NumOfNbrs=4;//���ڷ�����  
    Position here,nbr;  
    here.row=start.row;  
    here.col=start.col;  
  
    grid[start.row][start.col]=2;//��ǿɴ﷽��λ��  
    Queue<Position> Q;  
  
    do {//������ڿɴ﷽��  
        for(int i=0; i<NumOfNbrs; i++)  
        {  
            nbr.row=here.row + offset[i].row;  
            nbr.col=here.col+offset[i].col;  
  
            if(grid[nbr.row][nbr.col]==0)//�÷���δ�����  
            {  
                grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;  
                if((nbr.row==finish.row) && (nbr.col==finish.col))  
                {  
                    break; //��ɲ���  
                }  
                Q.Add(nbr);  
            }  
        }  
        //�Ƿ񵽴�Ŀ��λ��finish��  
        if((nbr.row==finish.row) && (nbr.col==finish.col))  
        {  
            break;//��ɲ���  
        }  
  
        //��������Ƿ�ǿգ�  
        if(Q.IsEmpty())  
        {  
            return false;//�޽�  
        }  
        Q.Delete(here);//ȡ��һ����չ���  
    }while(true);  
  
    //������̲���·��  
    PathLen=grid[finish.row][finish.col]-2;  
    path=new Position[PathLen];//��Ŀ��λ��finish��ʼ����ʼλ�û���  
    here=finish;  
    for(int j=PathLen-1; j>=0; j--)  
    {  
        path[j]=here;//��ǰ��λ��  
        for(int i=0; i<NumOfNbrs; i++)  
        {  
            nbr.row=here.row+offset[i].row;  
            nbr.col=here.col+offset[i].col;  
            if(grid[nbr.row][nbr.col]==j+2)  
            {  
                break;  
            }  
        }  
        here=nbr;//��ǰ�ƶ�  
    }  
    return true;  
}  
