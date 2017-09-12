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
		pre->Next=s;							//***ǰ�巨������
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
	L=(List)malloc(sizeof(struct Node));			//�ϲ��������
	c=L;
	while(a&&b)
	{
		if(a->Data<=b->Data){
			c->Next=a;								//��L1��L2�з��������Ľ�����ӵ�L��							
			c=a;
			a=a->Next;
		}else{
			c->Next=b,
			c=b;
			b=b->Next;
		}
	}
	c->Next=a?a:b;									//��һ������Ϊ��ʱ�����ӷǿս���ʣ����
	L1->Next=NULL;									//��ԭ������Ϊ��
	L2->Next=NULL;
	return L;
}



