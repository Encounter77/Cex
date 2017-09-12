#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef struct stacknode{								//链栈
	char data;
	struct stacknode* next;
}stacknode,*linkstack;

typedef struct qnode{									//链队
	char data;
	struct qnode* next;
}qnode,*queueptr;
typedef struct lq{
	queueptr front;
	queueptr rear;
}*linkqueue;

linkstack InitStack(linkstack p){						//初始化链栈
	p=(linkstack)malloc(sizeof(stacknode));
	p->next=NULL;
	return p;
}

void Push(linkstack p,char c){							//进栈
	linkstack s;
	s=(linkstack)malloc(sizeof(stacknode));
	s->data=c;
	s->next=p->next;									//前插法插入新结点
	p->next=s;	
}

char Pop(linkstack p){									//出栈(后进先出，始终从首元结点中出栈)
	char e;
	linkstack r;										//存放待释放结点
	if(p==NULL) exit(0);
	r=p->next;
	p->next=r->next;
	e=r->data;
	free(r);
	return e;
}

linkqueue InitQueue(linkqueue q){
	q=(linkqueue)malloc(sizeof(struct lq));				//动态分配操控队列的头，尾指针的空间  ********* 
	q->front=q->rear=(queueptr)malloc(sizeof(qnode));	//为头，尾指针分配空间 指向队列的头结点 
	if(!q->front)	exit(0);
	q->front->next=NULL;
	q->rear->next=NULL;
	return q;
}

void EnQueue(linkqueue q,char e){						//入队列操作 
	queueptr s;
	s=(queueptr)malloc(sizeof(qnode));
	s->data=e;
	s->next=NULL;
	q->rear->next=s;
	q->rear=s;
}

char DeQueue(linkqueue q){								//出队列操作 
	queueptr r;											//存放待释放结点 
	char e;	
	if(q->front==q->rear) exit(0);
	r=q->front->next;
	e=r->data;
	q->front->next=r->next;								
	if(q->rear==r)										//如果出队列的是最后一个结点 
		q->rear=q->front;
	free(r);
	return e;
}

void main()
{
	linkstack pn;										//链栈指针
	linkqueue qn;										//链队指针 
	int cnt=0;											//计数器，用来统计出栈，出队的字符相同的个数 
	int i;
	char ep,eq;											//接收出栈，出队的字符 
	char str[MAXSIZE];									//定义字符数组 
	printf("请输入字符串(最大长度为100):");
	scanf("%s",str);
	pn=InitStack(pn);									//初始化链栈 
	qn=InitQueue(qn);									//初始化链队 
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
		printf("该字符串是回文字符串");
	}else{
		printf("该字符串不是回文字符串");
	}
	printf("\n");
}
