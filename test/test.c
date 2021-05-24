#include <stdio.h>

int main()
{
	int cursor_x;
	while(1){
		printf("enter cursor: ");
		scanf("%d", &cursor_x);
		printf("input num : %d 0x%x\n", cursor_x, cursor_x);
		cursor_x = (cursor_x+8) & ~(8-1);
		printf("output num : %d 0x%x\n", cursor_x, cursor_x);
	}
	return 0;
}
