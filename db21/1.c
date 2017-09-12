#include<stdio.h>
#include<stdlib.h>
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef struct Node
{
	int Data;
	List Next;
};
List Merge( List L1, List L2 );
List CreatList(int n);
void PrintList(List L);

int main()
{
	List L1,L2,L;
	int m,n;
	scanf("%d",&m);
	L1=CreatList(m);
	scanf("%d",&n);
	L2=CreatList(n);
	//PrintList(L1);
	L=Merge(L1,L2);
	PrintList(L);
	PrintList(L1);
	return 0;
}

List CreatList(int n)
{
	int i;
	List p,pre,s;
	p=(List)malloc(sizeof(struct Node));
	p->Next=NULL;
	pre=p;
	for(i=0;i<n;i++)
	{
		s=(List)malloc(sizeof(struct Node));
		scanf("%d",&s->Data);
		pre->Next=s;							//***前插法插入结点
		pre=s;									//***
	}
	pre->Next=NULL;								//***
	return p;
}

void PrintList(List L)
{
	List r;
	r=L->Next;
	while(r)
	{
		printf("%d\n",r->Data);
		r=r->Next;
	}

}

List Merge( List L1, List L2 )
{
	List a,b,c,L;
	a=L1->Next;
	b=L2->Next;
	L=(List)malloc(sizeof(struct Node));			//合并后的链表
	c=L;
	while(a&&b)
	{
		if(a->Data<=b->Data){
			c->Next=a;								//将L1，L2中符合条件的结点链接到L中							
			c=a;
			a=a->Next;
		}else{
			c->Next=b,
			c=b;
			b=b->Next;
		}
	}
	c->Next=a?a:b;									//当一个链表为空时，连接非空结点的剩余结点
	L1->Next=NULL;									//将原链表置为空
	L2->Next=NULL;
	return L;
}



