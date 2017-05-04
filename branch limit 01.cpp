#include <stdio.h>
#include<malloc.h>
#define  MaxSize 100      //结点数的最大值
typedef  struct  QNode
{  
	float  weight;
	float  value;
	int ceng;
	struct  QNode *parent;
	bool leftChild;
}QNode,*qnode;
typedef struct
{    
	qnode  Q[MaxSize];
    int front,rear; 
}SqQueue;                //存放结点的队列 
SqQueue  sq; 
float bestv=0;           //最优解  
int n=0;                 //实际物品数 
float w[MaxSize];        //物品的重量 
float v[MaxSize];        //物品的价值  
int bestx[MaxSize];      // 存放最优解 
qnode bestE;  
void InitQueue(SqQueue &sq ) //队列初始化 
{  
	sq.front=1;  
	sq.rear=1;  
}  
bool QueueEmpty(SqQueue sq) //队列是否为空
{  
	if(sq.front==sq.rear)    
		return true;   
	else     
		return false;  
}   
void EnQueue(SqQueue &sq,qnode b)  //入队 
{  
	if(sq.front==(sq.rear+1)%MaxSize)  
	{   
		printf("队列已满!");   
		return;    
	}   
	sq.Q[sq.rear]=b;   
	sq.rear=(sq.rear+1)%MaxSize;  
}  qnode DeQueue(SqQueue &sq)   //出队 
{  
	qnode e;   
	if(sq.front==sq.rear)  
	{   
		printf("队列已空!");   
		return 0;   
	}   
	e=sq.Q[sq.front];   
	sq.front=(sq.front+1)%MaxSize;  
	return e;  
}  
void  EnQueue1(float wt,float vt, int i ,QNode *parent, bool leftchild)
{  
	qnode b;   
	if (i==n)                         //可行叶子结点  
	{   if (vt==bestv)

	{   bestE=parent;
	bestx[n]=(leftchild)?1:0;    
	}  
	return;   
	}   
	b=(qnode)malloc(sizeof(QNode));   //非叶子结点  
	b->weight=wt;  
	b->value=vt;  
	b->ceng=i;  
	b->parent=parent;   
	b->leftChild=leftchild;   
	EnQueue(sq,b);  
}    
void  maxLoading(float w[],float v[],int c) 
{   
	float wt=0;  
	float vt=0;   
	int i=1;           //当前的扩展结点所在的层   
	float ew=0;        //扩展节点所相应的当前载重量  
	float ev=0;        //扩展结点所相应的价值  
	qnode e=NULL;  
	qnode t=NULL;   
	InitQueue(sq); 
	EnQueue(sq,t);       //空标志进队列  
	while (!QueueEmpty(sq))  
	{     
		wt=ew+w[i];    
		vt=ev+v[i];   
		if (wt <= c)   
		{    
			if(vt>bestv)       
				bestv=vt;      
			EnQueue1(wt,vt,i,e,true);             // 左儿子结点进队列    
		}       EnQueue1(ew,ev,i,e,false);        //右儿子总是可行；   
		e=DeQueue(sq);                            // 取下一扩展结点   
		if (e == NULL)   
		{    
			if (QueueEmpty(sq))   
				break;     
			EnQueue(sq,NULL);        // 同层结点尾部标志    
			e=DeQueue(sq);           // 取下一扩展结点    
			i++;    
		}    
		ew=e->weight;                //更新当前扩展结点的值   
		ev=e->value;   
	}   
	printf("最优取法为：\n");   
	for( int j=n-1;j>0;j--)         //构造最优解  
	{   
		bestx[j]=(bestE->leftChild?1:0);   
		bestE=bestE->parent;   
	}    
	for(int k=1;k<=n;k++)
	{   
		if(bestx[k]==1)     
			printf("物品%d:重量：%.1f，价值：%.1f\n",k,w[k],v[k]);   
	} 

    printf("最大价值为：%.1f\n",bestv);
}
	void main()
	{ 
	   int c;
       float ewv[MaxSize];
	   printf("请输入背包的最大容量v:");
	   scanf("%d",&c);
	   printf("请输入物品总数n:");
	   scanf("%d",&n);   
       printf("请输入物品的重量和单位重量价值:\n");
	   for(int i=1;i<=n;i++)
	   {
		   printf("第%d件物品:",i);
           scanf("%f%f",&w[i],&ewv[i]);
		   v[i]=w[i]*ewv[i];
}
        maxLoading(w,v,c);
}
