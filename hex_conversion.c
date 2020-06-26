#include<stdio.h>
#define MAXCHAR 101  /*最大允许字符串长度*/
 
int char_to_num(char ch);  /*返回字符对应的数字*/ 
char num_to_char(int num);  /*返回数字对应的字符*/
long source_to_decimal(char temp[], int source);  /*返回由原数转换成的10进制数*/
int decimal_to_object(char temp[], long decimal_num, int object);  /*返回转换成目标数制后字符数组的长度*/
void output(char temp[], int length);  /*将字符数组逆序打印*/
 

int main(){
	int source;
	int object;
	int length;
	long decimal_num;
	char temp[MAXCHAR];
	int flag;
	while(flag)
	{
		printf("转换前的数为： ");
		scanf("%s", temp);
		printf("转换前的数制为： ");
		scanf("%d", &source);
		printf("转换后的数制为： ");
		scanf("%d", &object);
		printf("转换后的数为： ");
		decimal_num = source_to_decimal(temp, source);
		length = decimal_to_object(temp, decimal_num, object);
		output(temp, length);
		printf("继续请输入1，否则请输入0： \n");
		scanf("%d", &flag);
	}
	return 0;
}

int char_to_num(char ch){
	if(ch>='0' && ch<='9')
		return ch-'0';
	else
		return ch-'A'+10;
}


int num_to_char(int num){
	if(num>=0 && num<=9)
		return '0'+num;
	else
		return 'A'+num-10;
}

long source_to_decimal(char temp[],int source){
	long decimal_num = 0;
	int length;
	int i;
	for(i=0;temp[i]!='\0';i++)
		length = i;
	for(i=0;i<length;i++)
		decimal_num = char_to_num(temp[i])*source + decimal_num;

}