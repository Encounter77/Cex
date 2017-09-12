#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef struct stacknode{								//��ջ
	char data;
	struct stacknode* next;
}stacknode,*linkstack;

typedef struct qnode{									//����
	char data;
	struct qnode* next;
}qnode,*queueptr;
typedef struct lq{
	queueptr front;
	queueptr rear;
}*linkqueue;

linkstack InitStack(linkstack p){						//��ʼ����ջ
	p=(linkstack)malloc(sizeof(stacknode));
	p->next=NULL;
	return p;
}

void Push(linkstack p,char c){							//��ջ
	linkstack s;
	s=(linkstack)malloc(sizeof(stacknode));
	s->data=c;
	s->next=p->next;									//ǰ�巨�����½��
	p->next=s;	
}

char Pop(linkstack p){									//��ջ(����ȳ���ʼ�մ���Ԫ����г�ջ)
	char e;
	linkstack r;										//��Ŵ��ͷŽ��
	if(p==NULL) exit(0);
	r=p->next;
	p->next=r->next;
	e=r->data;
	free(r);
	return e;
}

linkqueue InitQueue(linkqueue q){
	q=(linkqueue)malloc(sizeof(struct lq));				//��̬����ٿض��е�ͷ��βָ��Ŀռ�  ********* 
	q->front=q->rear=(queueptr)malloc(sizeof(qnode));	//Ϊͷ��βָ�����ռ� ָ����е�ͷ��� 
	if(!q->front)	exit(0);
	q->front->next=NULL;
	q->rear->next=NULL;
	return q;
}

void EnQueue(linkqueue q,char e){						//����в��� 
	queueptr s;
	s=(queueptr)malloc(sizeof(qnode));
	s->data=e;
	s->next=NULL;
	q->rear->next=s;
	q->rear=s;
}

char DeQueue(linkqueue q){								//�����в��� 
	queueptr r;											//��Ŵ��ͷŽ�� 
	char e;	
	if(q->front==q->rear) exit(0);
	r=q->front->next;
	e=r->data;
	q->front->next=r->next;								
	if(q->rear==r)										//��������е������һ����� 
		q->rear=q->front;
	free(r);
	return e;
}

void main()
{
	linkstack pn;										//��ջָ��
	linkqueue qn;										//����ָ�� 
	int cnt=0;											//������������ͳ�Ƴ�ջ�����ӵ��ַ���ͬ�ĸ��� 
	int i;
	char ep,eq;											//���ճ�ջ�����ӵ��ַ� 
	char str[MAXSIZE];									//�����ַ����� 
	printf("�������ַ���(��󳤶�Ϊ100):");
	scanf("%s",str);
	pn=InitStack(pn);									//��ʼ����ջ 
	qn=InitQueue(qn);									//��ʼ������ 
	for(i=0;i<(int)strlen(str);i++){
		Push(pn,str[i]);
		EnQueue(qn,str[i]);
	}
	for(i=0;i<(int)strlen(str);i++){
		ep=Pop(pn);
		eq=DeQueue(qn);
		if(ep==eq){
			cnt++;
		}
	}
	if(cnt==(int)strlen(str)){
		printf("���ַ����ǻ����ַ���");
	}else{
		printf("���ַ������ǻ����ַ���");
	}
	printf("\n");
}
