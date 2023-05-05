#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Coordinate {
	int line;                       //行号
	int row;                        //列号
	struct Coordinate* next;
} Coord;
 
typedef struct NUM {
	char Num[100];					//单词
	float i;						//次数
	Coord *P;
	struct NUM* next;
} number;
 
void Sum();
 
int main() {
	Sum();				//统计单词总数
	return 0;
}
void Sum() {
	int i,j,row_1=1,line_1=1;
	float sum=0;
	char ch;
	number *N,*head,*end;
	head=(number*)malloc(sizeof(number));
	end=head;
	FILE*file;
	if((file=fopen("input.txt","r"))==NULL) {          //选择相应的文本文件
		printf("不能打开文件");
		exit(0);
	}
	N=(number*)malloc(sizeof(number));
	while(fscanf(file,"%s",N->Num)!=EOF) {
		N->P=(Coord*)malloc(sizeof(Coord));
		N->i=1;
		end->next=N;
		end=N;
		sum++;
		fscanf(file,"%c",&ch);
		if(ch!='\n') {
			N->P->row=row_1;
			N->P->line=line_1;
			row_1++;
		} else {
			N->P->row=row_1;
			N->P->line=line_1;
			row_1=1;
			line_1++;
		}
		N=(number*)malloc(sizeof(number));
	}
	end->next=NULL;
	fclose(file);
	printf("单词数：%.0f\n",sum);
}
				

