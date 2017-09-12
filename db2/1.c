#include<stdio.h>
#include<stdlib.h>
typedef struct polynome{
	int coef;
	int expn;
	struct polynome* next;
}polynome,*polynomial;

polynomial CreatePoly(polynomial p,int num)				//前插法创建多项式
{
	polynomial prep,s;
	int i;
	p=(polynomial)malloc(sizeof(polynome));
	prep=p;
	for(i=1;i<=num;i++)
	{
		s=(polynomial)malloc(sizeof(polynome));
		scanf("%d %d",&s->coef,&s->expn);
		prep->next=s;
		prep=s;
	}
	prep->next=NULL;
	return p;
}

polynomial AddPoly(polynomial a,polynomial b)
{
	polynomial ashow,bshow;
	polynomial c,prec,s;
	int sum;

	ashow=a->next;
	bshow=b->next;

	c=(polynomial)malloc(sizeof(polynome));
	prec=c;

	while((ashow!=NULL)&&(bshow!=NULL))
	{
		s=(polynomial)malloc(sizeof(polynome));
		if(ashow->expn>bshow->expn)
		{
			s->coef=ashow->coef;
			s->expn=ashow->expn;
			ashow=ashow->next;
			prec->next=s;
			prec=s;
		}else if(ashow->expn<bshow->expn)
		{
			s->coef=bshow->coef;
			s->expn=bshow->expn;
			bshow=bshow->next;
			prec->next=s;
			prec=s;
		}else
		{
			sum=ashow->coef+bshow->coef;
			if(sum!=0)
			{
				s->coef=sum;
				s->expn=ashow->expn;
				prec->next=s;
				prec=s;
			}
			ashow=ashow->next;
			bshow=bshow->next;
		}
	}
	/*
	if(ashow==NULL)
	{
		while(bshow)
		{
			s=(polynomial)malloc(sizeof(polynome));
			s->coef=bshow->coef;
			s->expn=bshow->expn;
			bshow=bshow->next;
			prec->next=s;
			prec=s;
		}
	
	}

	if(bshow==NULL)
	{
		while(ashow)
		{
			s=(polynomial)malloc(sizeof(polynome));
			s->coef=ashow->coef;
			s->expn=ashow->expn;
			ashow=ashow->next;
			prec->next=s;
			prec=s;
		}
	
	}
	prec->next=NULL;
	*/
	prec->next=ashow?ashow:bshow;	//****
	return c;
}

polynomial MultPoly(polynomial a,polynomial b)		//***************
{
	polynomial d,pred,s,mr;
	polynomial ashow,bshow;
	ashow=a->next;
	bshow=b->next;//*********************************************important code
	/*d=(polynomial)malloc(sizeof(polynome));
	d->next=NULL;
	pred=d;*/
	mr=CreatePoly(mr,0);//**********************************创建空的链表					
	if(ashow==NULL||bshow==NULL)
		return mr;
	while(ashow!=NULL)
	{
		d=(polynomial)malloc(sizeof(polynome));
		pred=d;
		bshow=b->next;
		while(bshow!=NULL)
		{
			s=(polynomial)malloc(sizeof(polynome));
			s->coef=ashow->coef*bshow->coef;
			s->expn=ashow->expn+bshow->expn;
			bshow=bshow->next;
			pred->next=s;
			pred=s;
		}
		pred->next=NULL;
		mr=AddPoly(mr,d);
		ashow=ashow->next;
	}
	return mr;
}

void PrintPoly(polynomial l)
{
	int flag=0;
	polynomial lshow;
	lshow=l->next;
	if(lshow==NULL) printf("0 0");
	while(lshow)
	{
		if(flag)
			printf(" ");
		else
			flag=1;
		printf("%d %d",lshow->coef,lshow->expn);
		lshow=lshow->next;
	}
}

int main()
{
	int m,n;
	polynomial La,Lb,Lc,Ld;
	scanf("%d",&m);
	La=CreatePoly(La,m);
	scanf("%d",&n);
	Lb=CreatePoly(Lb,n);
	Lc=AddPoly(La,Lb);
	Ld=MultPoly(La,Lb);
	PrintPoly(Ld);
	printf("\n");
	PrintPoly(Lc);
	printf("\n");
	return 0;
}