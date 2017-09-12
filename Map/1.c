#include<stdio.h>
#include<stdlib.h>
#define MVNum 100
typedef struct Map{
	char vers[MVNum];
	int arcs[MVNum][MVNum];
	int vernum,arcnum;
}amgraph,*graph;

int visit[MVNum]={0};								//����DFS��ʱ�������� 
int sum=0;											//�����Ѿ����ʵĶ������ 

int LocateVex(graph g,char u){
	int i;
	for(i=0;i<g->vernum;i++){
		if(u==g->vers[i]){
			return i;
		}
	}
}

graph CreateUDN(graph g){
	int i,j,k;
	char v1,v2;
	printf("�������ܶ��������ܱ���(�Կո�ָ�):");
	scanf("%d %d",&g->vernum,&g->arcnum);
	getchar();										//���ջس�
	printf("�����붥�����Ϣ(�Կո�ָ�):");
	for(i=0;i<g->vernum;i++){
		scanf("%c",&g->vers[i]);
		getchar();									//����ÿһ���ַ�����Ŀո����ս������һ���ַ���Ļس�
	}
	for(i=0;i<g->vernum;i++){
		for(j=0;j<g->vernum;j++){
			g->arcs[i][j]=0;
		}
	}
	printf("�������Ӧ���������Ķ���(��������֮���Զ��ŷָ�,ÿ�����Կո�ָ�):");
	for(k=0;k<g->arcnum;k++){	
		scanf("%c,%c",&v1,&v2);
		getchar();									//����ÿһ���ߺ�Ŀո�
		i=LocateVex(g,v1);
		j=LocateVex(g,v2);
		g->arcs[i][j]=1;
		g->arcs[j][i]=g->arcs[i][j];
	}
	return g;
}

void DFS(graph g,int c){
	int i;
	printf("%2c",g->vers[c]);						//��ӡ��Ӧ�±�Ķ���Ԫ�� 
	sum++;											//��¼�ѱ����ʵĶ������ 
	if(sum==g->vernum)
		exit(0);
	for(i=0;i<g->vernum;i++){
		if((g->arcs[c][i]!=0)&&(visit[i]==0)){		//����Ϊ��λ�����������飬�ж��ڽӾ�����Ԫ���Ƿ�Ϊ1������ʱ��������Ԫ���Ƿ�Ϊ0 
			visit[i]=1;								//��Ǳ����ʵĶ��� 
			DFS(g,i);								//���еݹ���� 
		}
	}
}

void Result(graph g){
	int i,j;
	printf("�ڽӾ���Ϊ:\n");
	for(i=0;i<g->vernum;i++){
		for(j=0;j<g->vernum;j++){
			printf("%2d",g->arcs[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int c;
	graph g=(graph)malloc(sizeof(amgraph));
	g=CreateUDN(g);
	Result(g);
	printf("��������Ҫ���б����Ŀ�ʼ�������:");
	scanf("%d",&c);
	visit[c-1]=1;									//�ö����ѱ����ʣ���ʱ����Ԫ��ֵ�ı�(��c�������±�Ϊc-1) 
	printf("DFS���Ϊ:");
	DFS(g,c-1);
	printf("\n");
	return 0;
}
