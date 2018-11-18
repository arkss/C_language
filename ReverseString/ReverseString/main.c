// 문자열을 거꾸로 출력하는 프로그램
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    int length;
    int temp,i;
    printf("문자열을 입력하세요.");
    scanf("%s",str);
    
    length = strlen(str);
    
    
    
    
    for (i=0;i<length/2;i++)
    {
        temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }
    printf("%s",str);
}

