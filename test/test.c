#include <stdio.h>
int strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

int strcmp_pro(const char *str1, const char *str2) {
    while ((*str1) && (*str1 == *str2))  
    {  
        str1++;  
        str2++;  
    }  
  
    if (*(unsigned char*)str1 > *(unsigned char*)str2)  
    {  
        return 1;  
    }  
    else if (*(unsigned char*)str1 < *(unsigned char*)str2)  
    {  
        return -1;  
    }  
    else  
    {  
        return 0;  
    }    
}

int main()
{
    char str1[14] = "baidu";
    char str2[14] = "google";
    int cmp1;
    int cmp2;
    int cmp3;
    int cmp4;

    cmp1 = strcmp(str1, str2);
    cmp2 = strcmp_pro(str1, str2);
    // cmp3 = strcmp(NULL,NULL);
    // cmp4 = strcmp_pro(NULL,NULL);
    printf("strcmp(str1, str1) : %d\n", cmp1);
    printf("strcmp_pro(str1, str1) : %d\n", cmp2);
    printf("strcmp(NULL, NULL) : %d\n", cmp3);
    printf("strcmp_pro(NULL, NULL) : %d\n", cmp4);

	return 0;
}
