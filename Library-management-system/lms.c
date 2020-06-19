#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#define LL sizeof(BOOK_TYPE)

int main()
{	
	int a=maininterface();
	switch(a)	
	{
		case 1:system("clear");infor_input();break;
		case 2:system("clear");refer();break;
		case 3:system("clear");modify();break;
		case 4:system("clear");dl();break;
		case 5:exit(0);
		default:system("clear");printf("\n\n\n\n\t\t无此操作，请按任意键返回：\n");getch();system("clear");
	}
	return 0;
}

int maininterface()
{
	int n;
	printf("\n\n\n\t\t------------图书管理系统-----------\n"); 
	printf("\n\t\t\t\t1:<录入图书信息>\n");
	printf("\n\t\t\t\t2:<查询信息>\n"); 
	printf("\n\t\t\t\t3:<修改图书信息>\n");
	printf("\n\t\t\t\t4:<删除图书信息>\n");
	printf("\n\t\t\t\t5:<退出系统>\n"); 
	printf("\n\t\t\t请输入1--5,其他输入非法！\n"); 
	scanf("%d", &n);
	return n;
}

typedef struct books
{
	char bookname[50];
	char ISBN[50];
	char publisher[50];
	float money;
	struct books *next;
}BOOK_TYPE;


void infor_input()
{
	FILE *fp;
	int n=0;
	BOOK_TYPE ts;
	printf("---------------图书资料基本信息录入--------------\n")
	do
	{
		printf("请输入书名\n");
		scanf("%s",ts.bookname);
		printf("请输入ISBN\n");
		scanf("%s",ts.ISBN);
		printf("请输入出版社\n");
		scanf("%s",ts.publisher);
		printf("请输入价格\n");
		scanf("%f",&ts.money);
		printf("\n\t\t\t请选择(1:确定\t2:取消\t0:重新输入):");
		scanf("%d",&n);
	}while(n==0);
	if(n==1)
	{
		if((fp=fopen("boot.txt","a"))==NULL)
		{
			fp=fopen("book.txt","w+");
		}
		fwrite(&ts,LL,1,fp);
		fclose(fp);
	}
}