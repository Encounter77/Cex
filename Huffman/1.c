#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
typedef char **huffmancode;
typedef struct Huffman{
	int weight;
	char code;
	int parent,lchild,rchild;
}htnode,*huffmantree;
typedef struct Data{      												//定义预先储存的字符及权值 
	int w;
	char c;
}Data;

int Select(huffmantree ht,int n){										//遍历结点寻找最小权值结点，返回对应下标 
	int i,mw = MAX,s;
	for(i = 1;i <= n; i++){
		if(ht[i].weight < mw&&ht[i].parent == 0){
			mw = ht[i].weight;
			s = i;
		}
	}
	return s;
}

huffmantree CreateHuffmanTree(huffmantree ht,int n){					//构造哈弗曼树	
	int s1,s2;
	int m,i;
	Data data[27] = {{186,' '},{64,'a'},{13,'b'},{22,'c'},{32,'d'},{103,'e'},{21,'f'},{15,'g'},{47,'h'},{57,'i'},{1,'j'},{5,'k'},{32,'l'},{20,'m'},{57,'n'},{63,'o'},{15,'p'},{1,'q'},{48,'r'},{51,'s'},{80,'t'},{23,'u'},{8,'v'},{18,'w'},{1,'x'},{16,'y'},{1,'z'}};
	if(n <= 1) exit(0);
	m = 2*n-1;
	ht = (huffmantree)malloc(sizeof(htnode)*(m+1));
	for(i = 1;i <= m; i++){												//初始化结构体数组 
		ht[i].parent = 0;
		ht[i].code = '0';
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	}
	for(i = 1;i <= n; i++){												//分别对叶子结点赋值 
		ht[i].weight = data[i-1].w;
		ht[i].code = data[i-1].c;
	}
	for(i = n+1;i <= m; i++){											//调用Select函数构造哈夫曼树 
		s1=Select(ht,i-1);
		ht[s1].parent = i;
		ht[i].lchild = s1;
		s2=Select(ht,i-1);
		ht[s2].parent = i;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;			
	}
	return ht;
}

huffmancode CreateHuffmanCode(huffmantree ht,huffmancode hc,int n){		//构造哈夫曼编码 
	int i,start,c,f;
	char* ch = (char*)malloc(sizeof(char)*n);
	hc = (huffmancode)malloc(sizeof(char*)*(n+1));
	ch[n-1] = '\0';														//开辟临时数组空间	 
	for(i = 1;i <= n; i++){
		start = n-1;
		c = i;
		f = ht[i].parent;
		while(f != 0){
			--start;
			if(ht[f].lchild == c)
				ch[start] = '0';
			else
				ch[start] = '1';
			c = f;
			f = ht[f].parent;
		}
		hc[i] = malloc(sizeof(char)*(n-start));
		strcpy(hc[i],&ch[start]);										//字符串复制 
	}
	free(ch);
	return hc;
}

void DeCode1(huffmantree ht,huffmancode hc,int n){						//编码函数 
	int i,j;
	char str[100];
	char arr[1000] = {'\0'};
	printf("请输入一段文本:");
//	scanf("%s",str);	//遇到回车或空格就结束
	getchar();															//存回车 
	gets(str);
	for(i = 0;str[i]; i++){
//		char arr[10];
		for(j = 1;j <= n; j++){
			if(str[i] == ht[j].code){
//              赋值相当于赋地址。
//				p[i]=hc[j];
//				int len=strlen(hc[j]);
//				p[i]=(char*)malloc(sizeof(char)*len);
				strcat(arr,hc[j]);										//字符串连接 
//				arr[k++]=hc[j];
//				printf("%s",arr);
//				for(p=0;hc[j][p];p++){
//					arr[k++]=hc[j][p];
//				}
			}
		} 
	}
	printf("编码结果为:");
	printf("%s\n",arr);	
}

void DeCode2(huffmantree ht,int n){										//译码函数 
	int m = 2*n-1;
	int i,j = 0;
	char binarycode[100];
	char encode[1000] = {'\0'};
	printf("请输入您所要编译的二进制编码:");
	scanf("%s",binarycode);
	for(i = 0;binarycode[i]; i++){										//从根结点开始遍历，遇到0就到左子树，反之右子树，当到叶子节点时为止 
		if(binarycode[i] == '0'){
			m = ht[m].lchild;
		}else{
			m = ht[m].rchild;
		}
		if(ht[m].lchild == 0&&ht[m].rchild == 0){
			encode[j++]=ht[m].code;										//到达叶子节点将对应的字符赋值给encode数组 
			m = 2*n-1;            			   							//找到叶子结点后，重置m到根结点 
		}
	}
	printf("译码结果为:");
	puts(encode);
}

void Result(huffmantree ht,huffmancode hc,int n){
	int i;
	printf("哈夫曼树为:\n");
	for(i=1;i<=2*n-1;i++){
		printf("%4d%4c%4d%4d%4d\n",ht[i].weight,ht[i].code,ht[i].parent,ht[i].lchild,ht[i].rchild);
	}
	printf("哈夫曼编码为:\n");
	for(i=1;i<=n;i++){
		printf("%4c\t%s\n",ht[i].code,hc[i]);
	}
}   

void show(){
	printf("哈夫曼数及其编码已经完成，请进行其他操作。\n");
	printf("\n");
	printf("-----欢迎使用哈夫曼编译码器-----\n");
}

void FunctionalInterface(huffmantree ht,huffmancode hc,int n){
	int r;
	char c; 
	do{
		printf("请输入您需要进行的操作:\n");
		printf("0.输出哈弗曼树及其编码\n");
		printf("1.编码\n");
		printf("2.译码\n");
		printf("3.退出\n");
		printf("您的操作为:");
		scanf("%d",&r);
		switch(r){
		case 0: Result(ht,hc,n);break;
		case 1: DeCode1(ht,hc,n);break;
		case 2: DeCode2(ht,n);break;
		case 3: break;
		}
		getchar();
		if(r!= 3){
			printf("\n您是否还需要继续进行操作:(Y/N)");
			scanf("%c",&c);
			getchar();
		} else{
			c = 'N';
		}
	} while(c != 'N');
	printf("感谢您的使用，再见。");
}                                                                           

int main(){
	int n = 27;
	huffmantree ht;
	huffmancode	hc;
	ht = CreateHuffmanTree(ht,n);
	hc = CreateHuffmanCode(ht,hc,n);
	show();
	FunctionalInterface(ht,hc,n);
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
