#include<stdio.h>
#include<stdlib.h>

typedef struct PNode
{
	float coef;										//多项式系数
	int expn;										//多项式指数
	struct PNode *next;
}PNode,*Polynomial;

Polynomial CreatPolyn(Polynomial p,int n)			//创建多项式
{
	Polynomial s,q,pre;
	int i;
	p=(Polynomial)malloc(sizeof(PNode));
	p->next=NULL;									//创建只有头结点的空链表
	for(i=1;i<=n;i++)
	{
		s=(Polynomial)malloc(sizeof(PNode));		//创建新结点
		printf("请输入第%d项的系数和指数:",i);
		scanf("%f %d",&s->coef,&s->expn);
		pre=p;
		q=p->next;
	while(q&&(q->expn<s->expn))						//通过比较指数找到第一个大于输入项指数的项
	{
		pre=q;
		q=q->next;
	}
		s->next=q;
		pre->next=s;
	}
	return p;										//返回链表的头结点
}


void AddPolyn(Polynomial m,Polynomial n)			//多项式相加
{
	float sum=0;									//存放相同指数的系数和
	Polynomial p1,p2,p3,r;							//r存放需要被释放的结点
	p1=m->next;
	p2=n->next;
	p3=m;											//p3指向和多项式头结点m(a)
	while(p1&&p2)
	{
		if(p1->expn==p2->expn)
		{
			sum=p1->coef+p2->coef;
			if(sum!=0)
			{
				p1->coef=sum;
				p3->next=p1;
				p3=p1;								//p3指向p1
				p1=p1->next;					
				r=p2;								
				p2=p2->next;
				free (r);		
			}else{
				r=p1;
				p1=p1->next;
				free (r);
				r=p2;
				p2=p2->next;
				free (r);
			}
		}else if(p1->expn<p2->expn)
		{
			p3->next=p1;
			p3=p1;
			p1=p1->next;
		}else
		{
			p3->next=p2;
			p3=p2;
			p2=p2->next;	
		}
	}
	p3->next=p1?p1:p2;
	free (n);										//释放b链表
}


void main()
{
	Polynomial a,b;							
	Polynomial ashow,bshow,k;						//输出a,b链表结点内数据分别用ashow,bshow来控制,k是控制和多项式的输出
	int m,n;										//a,b多项式项的个数
	int i;											//循环控制变量i
	//int cnt;
	printf("请输入多项式a,b的项数:\n");
	scanf("%d %d",&m,&n);
	printf("请输入多项式a:\n");
	a=CreatPolyn(a,m);								//函数调用
	printf("请输入多项式b:\n");
	b=CreatPolyn(b,n);								//函数调用
	
	printf("多项式pa:\n");
	ashow=a->next;									//a链表定位到首元节点
	for(i=1;i<=m;i++)
	{
		if(ashow->next)								//分格式输出结点内数据
		printf("(%.2f)x^%d+",ashow->coef,ashow->expn);
		else
		printf("(%.2f)x^%d",ashow->coef,ashow->expn);
		ashow=ashow->next;							//指针后移
	}
	printf("\n");
	
	printf("多项式pb:\n");		
	bshow=b->next;									//b链表定位到首元节点	
	for(i=1;i<=n;i++)
	{		
		if(bshow->next)								//分格式输出结点内数据
		printf("(%.2f)x^%d+",bshow->coef,bshow->expn);
		else
		printf("(%.2f)x^%d",bshow->coef,bshow->expn);
		bshow=bshow->next;							//指针后移
	}
	printf("\n");

	printf("多项式a和b的和为:\n");
	AddPolyn(a,b);									//函数调用
	k=a->next;										//k指向和多项式的首元结点
	//cnt=1;
	/*while(k)
	{
		if(cnt=0)
			printf("+");
		printf("(%.2f)x^%d",k->coef,k->expn);	
		cnt=0;
		k=k->next;
	}*/
	for(;k->next;k=k->next)							//循环控制和多项式的输出
	{
		printf("(%.2f)^x%d+",k->coef,k->expn);
	}
		printf("(%.2f)^x%d",k->coef,k->expn);		//最后一项后没有"+"号
		printf("\n");
}