/// 대문자는 소문자로, 소문자는 대문자로 변경
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    int i,length;
    printf("문자열을 입력하세요.");
    scanf("%s",str);
    
    length = strlen(str);
    for (i=0;i<length;i++)
    {
        if (str[i]<='Z' && str[i]>='A')
        {
            str[i] = str[i] + 32;
            continue;
        }
        if (str[i]<='z' && str[i]>='a')
        {
            str[i] = str[i] - 32;
        }
    }
    
    printf("바뀐 문자열은 %s입니다.",str);
}
