#include <stdio.h>
#include <math.h>
#define MAXCHAR 10

int char_to_num(char ch);
char num_to_char(int num);
long source_to_decimal(char temp[], int source);
int decimal_to_object(char temp[], long decimal_num, int object);
void output(char temp[], int length)