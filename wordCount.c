#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Coordinate {
	int line;                       //�к�
	int row;                        //�к�
	struct Coordinate* next;
} Coord;
 
typedef struct NUM {
	char Num[100];					//����
	float i;						//����
	Coord *P;
	struct NUM* next;
} number;
 
void Sum();
 
int main() {
	Sum();				//ͳ�Ƶ�������
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
	if((file=fopen("input.txt","r"))==NULL) {          //ѡ����Ӧ���ı��ļ�
		printf("���ܴ��ļ�");
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
	printf("��������%.0f\n",sum);
}
				

