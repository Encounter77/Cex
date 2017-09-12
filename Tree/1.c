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
	printf("请输入树的先序遍历(叶子结点的左右子树用'*'表示):");
	ti=CreateTree(ti);
	printf("该树的前序遍历为:");
	PreOrderTraverse(ti);
	printf("\n");
	printf("该树的中序遍历为:");
	InOrderTraverse(ti);
	printf("\n");
	printf("该树的后序遍历为:");
	PostOrderTraverse(ti);
	printf("\n");
	return 0;
}
