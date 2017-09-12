#include<stdio.h>
#include<stdlib.h>

typedef struct PNode
{
	float coef;										//����ʽϵ��
	int expn;										//����ʽָ��
	struct PNode *next;
}PNode,*Polynomial;

Polynomial CreatPolyn(Polynomial p,int n)			//��������ʽ
{
	Polynomial s,q,pre;
	int i;
	p=(Polynomial)malloc(sizeof(PNode));
	p->next=NULL;									//����ֻ��ͷ���Ŀ�����
	for(i=1;i<=n;i++)
	{
		s=(Polynomial)malloc(sizeof(PNode));		//�����½��
		printf("�������%d���ϵ����ָ��:",i);
		scanf("%f %d",&s->coef,&s->expn);
		pre=p;
		q=p->next;
	while(q&&(q->expn<s->expn))						//ͨ���Ƚ�ָ���ҵ���һ������������ָ������
	{
		pre=q;
		q=q->next;
	}
		s->next=q;
		pre->next=s;
	}
	return p;										//���������ͷ���
}


void AddPolyn(Polynomial m,Polynomial n)			//����ʽ���
{
	float sum=0;									//�����ָͬ����ϵ����
	Polynomial p1,p2,p3,r;							//r�����Ҫ���ͷŵĽ��
	p1=m->next;
	p2=n->next;
	p3=m;											//p3ָ��Ͷ���ʽͷ���m(a)
	while(p1&&p2)
	{
		if(p1->expn==p2->expn)
		{
			sum=p1->coef+p2->coef;
			if(sum!=0)
			{
				p1->coef=sum;
				p3->next=p1;
				p3=p1;								//p3ָ��p1
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
	free (n);										//�ͷ�b����
}


void main()
{
	Polynomial a,b;							
	Polynomial ashow,bshow,k;						//���a,b�����������ݷֱ���ashow,bshow������,k�ǿ��ƺͶ���ʽ�����
	int m,n;										//a,b����ʽ��ĸ���
	int i;											//ѭ�����Ʊ���i
	//int cnt;
	printf("���������ʽa,b������:\n");
	scanf("%d %d",&m,&n);
	printf("���������ʽa:\n");
	a=CreatPolyn(a,m);								//��������
	printf("���������ʽb:\n");
	b=CreatPolyn(b,n);								//��������
	
	printf("����ʽpa:\n");
	ashow=a->next;									//a����λ����Ԫ�ڵ�
	for(i=1;i<=m;i++)
	{
		if(ashow->next)								//�ָ�ʽ������������
		printf("(%.2f)x^%d+",ashow->coef,ashow->expn);
		else
		printf("(%.2f)x^%d",ashow->coef,ashow->expn);
		ashow=ashow->next;							//ָ�����
	}
	printf("\n");
	
	printf("����ʽpb:\n");		
	bshow=b->next;									//b����λ����Ԫ�ڵ�	
	for(i=1;i<=n;i++)
	{		
		if(bshow->next)								//�ָ�ʽ������������
		printf("(%.2f)x^%d+",bshow->coef,bshow->expn);
		else
		printf("(%.2f)x^%d",bshow->coef,bshow->expn);
		bshow=bshow->next;							//ָ�����
	}
	printf("\n");

	printf("����ʽa��b�ĺ�Ϊ:\n");
	AddPolyn(a,b);									//��������
	k=a->next;										//kָ��Ͷ���ʽ����Ԫ���
	//cnt=1;
	/*while(k)
	{
		if(cnt=0)
			printf("+");
		printf("(%.2f)x^%d",k->coef,k->expn);	
		cnt=0;
		k=k->next;
	}*/
	for(;k->next;k=k->next)							//ѭ�����ƺͶ���ʽ�����
	{
		printf("(%.2f)^x%d+",k->coef,k->expn);
	}
		printf("(%.2f)^x%d",k->coef,k->expn);		//���һ���û��"+"��
		printf("\n");
}