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
	s->base=(int*)malloc(sizeof(int)*MAXSIZE);		//Ϊ˳��ջ��̬����һ��MAXSIZE��С�Ŀռ�
	if(!s->base) exit (0);
	s->top=s->base;
	s->size=MAXSIZE;
}

void Push(sqstack *s,int e)
{
	if(s->top-s->base==s->size)
		exit (0);
	*(s->top)=e;									//***ֵ����
	s->top++;										//***ָ�����
}

void Pop(sqstack *s,int *e)
{
	if(s->base==s->top)
	exit (0);
	s->top--;										//***ָ�����
	*e=*(s->top);									//***ֵ����
}

int StackEmpty(sqstack *s)							//�ж��Ƿ�ջΪ��
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
	printf("ʮ����:");
	scanf("%d",&n);
	printf("������:");
	conversion(n);
	return 0;
}