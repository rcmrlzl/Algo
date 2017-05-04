#include <stdio.h>
#include<malloc.h>
#define  MaxSize 100      //����������ֵ
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
}SqQueue;                //��Ž��Ķ��� 
SqQueue  sq; 
float bestv=0;           //���Ž�  
int n=0;                 //ʵ����Ʒ�� 
float w[MaxSize];        //��Ʒ������ 
float v[MaxSize];        //��Ʒ�ļ�ֵ  
int bestx[MaxSize];      // ������Ž� 
qnode bestE;  
void InitQueue(SqQueue &sq ) //���г�ʼ�� 
{  
	sq.front=1;  
	sq.rear=1;  
}  
bool QueueEmpty(SqQueue sq) //�����Ƿ�Ϊ��
{  
	if(sq.front==sq.rear)    
		return true;   
	else     
		return false;  
}   
void EnQueue(SqQueue &sq,qnode b)  //��� 
{  
	if(sq.front==(sq.rear+1)%MaxSize)  
	{   
		printf("��������!");   
		return;    
	}   
	sq.Q[sq.rear]=b;   
	sq.rear=(sq.rear+1)%MaxSize;  
}  qnode DeQueue(SqQueue &sq)   //���� 
{  
	qnode e;   
	if(sq.front==sq.rear)  
	{   
		printf("�����ѿ�!");   
		return 0;   
	}   
	e=sq.Q[sq.front];   
	sq.front=(sq.front+1)%MaxSize;  
	return e;  
}  
void  EnQueue1(float wt,float vt, int i ,QNode *parent, bool leftchild)
{  
	qnode b;   
	if (i==n)                         //����Ҷ�ӽ��  
	{   if (vt==bestv)

	{   bestE=parent;
	bestx[n]=(leftchild)?1:0;    
	}  
	return;   
	}   
	b=(qnode)malloc(sizeof(QNode));   //��Ҷ�ӽ��  
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
	int i=1;           //��ǰ����չ������ڵĲ�   
	float ew=0;        //��չ�ڵ�����Ӧ�ĵ�ǰ������  
	float ev=0;        //��չ�������Ӧ�ļ�ֵ  
	qnode e=NULL;  
	qnode t=NULL;   
	InitQueue(sq); 
	EnQueue(sq,t);       //�ձ�־������  
	while (!QueueEmpty(sq))  
	{     
		wt=ew+w[i];    
		vt=ev+v[i];   
		if (wt <= c)   
		{    
			if(vt>bestv)       
				bestv=vt;      
			EnQueue1(wt,vt,i,e,true);             // ����ӽ�������    
		}       EnQueue1(ew,ev,i,e,false);        //�Ҷ������ǿ��У�   
		e=DeQueue(sq);                            // ȡ��һ��չ���   
		if (e == NULL)   
		{    
			if (QueueEmpty(sq))   
				break;     
			EnQueue(sq,NULL);        // ͬ����β����־    
			e=DeQueue(sq);           // ȡ��һ��չ���    
			i++;    
		}    
		ew=e->weight;                //���µ�ǰ��չ����ֵ   
		ev=e->value;   
	}   
	printf("����ȡ��Ϊ��\n");   
	for( int j=n-1;j>0;j--)         //�������Ž�  
	{   
		bestx[j]=(bestE->leftChild?1:0);   
		bestE=bestE->parent;   
	}    
	for(int k=1;k<=n;k++)
	{   
		if(bestx[k]==1)     
			printf("��Ʒ%d:������%.1f����ֵ��%.1f\n",k,w[k],v[k]);   
	} 

    printf("����ֵΪ��%.1f\n",bestv);
}
	void main()
	{ 
	   int c;
       float ewv[MaxSize];
	   printf("�����뱳�����������v:");
	   scanf("%d",&c);
	   printf("��������Ʒ����n:");
	   scanf("%d",&n);   
       printf("��������Ʒ�������͵�λ������ֵ:\n");
	   for(int i=1;i<=n;i++)
	   {
		   printf("��%d����Ʒ:",i);
           scanf("%f%f",&w[i],&ewv[i]);
		   v[i]=w[i]*ewv[i];
}
        maxLoading(w,v,c);
}
