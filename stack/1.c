#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct sqstack{
	int* base;					
	int* top;						
	int size;						
}sqstack;

void InitStack(sqstack *s)
{
	s->base=(int*)malloc(sizeof(int)*MAXSIZE);		//为顺序栈动态分配一个MAXSIZE大小的空间
	if(!s->base) exit (0);
	s->top=s->base;
	s->size=MAXSIZE;
}

void Push(sqstack *s,int e)
{
	if(s->top-s->base==s->size)
		exit (0);
	*(s->top)=e;									//***值存入
	s->top++;										//***指针后移
}

void Pop(sqstack *s,int *e)
{
	if(s->base==s->top)
	exit (0);
	s->top--;										//***指针后移
	*e=*(s->top);									//***值保存
}

int StackEmpty(sqstack *s)							//判断是否栈为空
{
	int flag=0;
	if(s->base==s->top)
		flag=1;
	return flag;
}

void conversion(int n)
{	
	int e;
	sqstack s;
	InitStack(&s);
	while(n)
	{
		Push(&s,n%2);
		n/=2;
	}
	while(!StackEmpty(&s))
	{
		Pop(&s,&e);
		printf("%d",e);
	}
	printf("\n");
}


int main()
{
	int n;
	printf("十进制:");
	scanf("%d",&n);
	printf("二进制:");
	conversion(n);
	return 0;
}