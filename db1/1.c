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
		//***���ǰ��
		pre=p;								//***��λͷ���
		q=p->next;							//***��ʼ����ָ����Ԫ���
		s->next=q;							//***����
		pre->next=s;						//***���
	}

	h=p->next;								//ָ��h��λ����Ԫ��㿪ʼ���������ж��Ƿ��������ݾ�Ϊ����
	for(i=0;i<k;i++)
	{
		if(h->data<0)
		{
			flag++;
		}
		h=h->next;
	}
	if(flag==k)								//flag������Ǹ������ĸ����������Ϊ���������ӡ0
		printf("0\n");

	w=p->next;							
	if(flag!=k){							//�������������ݾ���Ϊ������ǰ���£�ָ��w�����������������к�
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
