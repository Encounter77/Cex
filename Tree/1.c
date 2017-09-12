#include<stdio.h>
#include<stdlib.h>
typedef struct BiNode{
	char data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}tree,*bitree;

bitree CreateTree(bitree t){
	char value;
	scanf("%c",&value);
	if(value=='*')
	{
		t=NULL;
	}else
	{
		t=(bitree)malloc(sizeof(tree));
		if(t)
		t->data=value;
		t->lchild=CreateTree(t->lchild);
		t->rchild=CreateTree(t->rchild);
	}
	return t;
}

void PreOrderTraverse(bitree t){
	if(t){
		printf("%c ",t->data);
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
  }

void InOrderTraverse(bitree t){
	if(t){
		InOrderTraverse(t->lchild);
		printf("%c ",t->data);
		InOrderTraverse(t->rchild);
	}
}

void PostOrderTraverse(bitree t){
	if(t){
		PostOrderTraverse(t->lchild);
		PostOrderTraverse(t->rchild);
		printf("%c ",t->data);
	} 
} 
int main(){
	bitree ti;
	printf("�����������������(Ҷ�ӽ�������������'*'��ʾ):");
	ti=CreateTree(ti);
	printf("������ǰ�����Ϊ:");
	PreOrderTraverse(ti);
	printf("\n");
	printf("�������������Ϊ:");
	InOrderTraverse(ti);
	printf("\n");
	printf("�����ĺ������Ϊ:");
	PostOrderTraverse(ti);
	printf("\n");
	return 0;
}
