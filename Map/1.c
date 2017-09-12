#include<stdio.h>
#include<stdlib.h>
#define MVNum 100
typedef struct Map{
	char vers[MVNum];
	int arcs[MVNum][MVNum];
	int vernum,arcnum;
}amgraph,*graph;

int visit[MVNum]={0};								//定义DFS临时访问数组 
int sum=0;											//保存已经访问的顶点个数 

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
	printf("请输入总顶点数和总边数(以空格分隔):");
	scanf("%d %d",&g->vernum,&g->arcnum);
	getchar();										//接收回车
	printf("请输入顶点的信息(以空格分隔):");
	for(i=0;i<g->vernum;i++){
		scanf("%c",&g->vers[i]);
		getchar();									//接收每一个字符后面的空格，最终接收最后一个字符后的回车
	}
	for(i=0;i<g->vernum;i++){
		for(j=0;j<g->vernum;j++){
			g->arcs[i][j]=0;
		}
	}
	printf("请输入对应边所依附的顶点(两个顶点之间以逗号分隔,每条边以空格分隔):");
	for(k=0;k<g->arcnum;k++){	
		scanf("%c,%c",&v1,&v2);
		getchar();									//接收每一条边后的空格
		i=LocateVex(g,v1);
		j=LocateVex(g,v2);
		g->arcs[i][j]=1;
		g->arcs[j][i]=g->arcs[i][j];
	}
	return g;
}

void DFS(graph g,int c){
	int i;
	printf("%2c",g->vers[c]);						//打印对应下标的顶点元素 
	sum++;											//记录已被访问的顶点个数 
	if(sum==g->vernum)
		exit(0);
	for(i=0;i<g->vernum;i++){
		if((g->arcs[c][i]!=0)&&(visit[i]==0)){		//以行为单位遍历顶点数组，判断邻接矩阵中元素是否为1并且临时访问数组元素是否为0 
			visit[i]=1;								//标记被访问的顶点 
			DFS(g,i);								//进行递归操作 
		}
	}
}

void Result(graph g){
	int i,j;
	printf("邻接矩阵为:\n");
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
	printf("请输入您要进行遍历的开始顶点序号:");
	scanf("%d",&c);
	visit[c-1]=1;									//该顶点已被访问，临时数组元素值改变(第c个顶点下标为c-1) 
	printf("DFS结果为:");
	DFS(g,c-1);
	printf("\n");
	return 0;
}
