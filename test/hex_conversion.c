#include "lib/common.h"
 
// int char_to_num(char ch);
// char num_to_char(int num);
// long source_to_decimal(char temp[], int source);
// int decimal_to_object(char temp[], long decimal_num, int object);
// void output(char temp[], int length);

// int main(){
	// int source;
	// int object;
	// int length;
	// long decimal_num;
	// char temp[MAXCHAR];
	// int flag = 1;
	// while(flag)
	// {
		// printf("old num: ");
		// scanf("%s", temp);
		// printf("old hex: ");
		// scanf("%d", &source);
		// printf("new hex: ");
		// scanf("%d", &object);
		// printf("new num: ");
		// decimal_num = source_to_decimal(temp, source);
		// length = decimal_to_object(temp, decimal_num, object);
		// output(temp, length);
		// printf("keep going: 1,or else: 0: \n");
		// scanf("%d", &flag);
	// }
	// return 0;
// }

int char_to_num(char ch){
	if(ch>='0' && ch<='9')
		return ch-'0';
	else
		return ch-'A'+10;
}


char num_to_char(int num){
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
	for(i=0;i<=length;i++)
		decimal_num += char_to_num (temp[i])*pow(source,length-i);
	return decimal_num;

}

int decimal_to_object(char temp[], long decimal_num, int object){
	int i = 0;
	while(decimal_num){
		temp[i] = num_to_char(decimal_num%object);
		decimal_num = decimal_num/object;
		i++;
	}
	temp[i]='\0';
	return i;
}

void output(char temp[], int length){
	int i;
	for(i=length-1;i>=0;i--)
		printf("%c",temp[i]);
	printf("\n");
}

