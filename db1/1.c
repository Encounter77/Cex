#include<stdio.h>
#include<stdlib.h>
typedef struct number{
	int data;
	struct number* next;
}number;

int main()
{
	number *pre,*p,*s,*q,*w,*h;
	int k,i,v,flag=0,maxsum=0,thissum=0;
	scanf("%d",&k);
	p=(number*)malloc(sizeof(number));
	p->next=NULL;

	for(i=0;i<k;i++)
	{
		s=(number*)malloc(sizeof(number));
		scanf("%d",&s->data);
		//***结点前插
		pre=p;								//***定位头结点
		q=p->next;							//***初始化，指向首元结点
		s->next=q;							//***先连
		pre->next=s;						//***后断
	}

	h=p->next;								//指针h定位到首元结点开始遍历链表，判断是否结点内数据均为负数
	for(i=0;i<k;i++)
	{
		if(h->data<0)
		{
			flag++;
		}
		h=h->next;
	}
	if(flag==k)								//flag变量标记负数结点的个数，如果均为负数，则打印0
		printf("0\n");

	w=p->next;							
	if(flag!=k){							//在链表结点内数据均不为负数的前提下，指针w遍历链表，求出最大子列和
		for(i=0;i<k;i++)
		{
			thissum+=w->data;
			if(thissum>maxsum)
				maxsum=thissum;
			else if(thissum<0)
				thissum=0;
			w=w->next;
		}
		printf("%d\n",maxsum);
	}
	return 0;
}
