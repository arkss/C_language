// 입력한 문자열을 숫자로 바꾸는 프로그램
// atoi 함수 구현하기
#include <stdio.h>

int my_atoi(char const *c);


int main(void)
{
    int i;
    char *str;
    printf("정수로 바꿀 문자열을 입력하세요");
    scanf("%s",str);
    i = my_atoi(str);
    printf("i = %d\n",i);
}

int my_atoi(char const *c){
    
    int value = 0;
    int positive = 1;
    
    if(*c == '\0')
        return 0;
    
    if(*c == '-')
        positive = -1;
    
    while(*c) {
        if(*c > '0' && *c < '9')
            value = value * 10 + *c - '0';
        c++;
    }
    
    return value*positive;
}
