
/*
 매개변수 ps는 단어를 분리할 문장의 포인터이며 반환값은 분리한 단어의 주소
 함수를 반복호출하면 문장의 모든 단어를 분리할 때까지 한 단어씩 주소를 반환
 한수 안에서는 정적변수를 이용하여 끊어 낼 다음 단어의 위치를 기억
 */
#include <stdio.h>
#include <string.h>

char *my_token(char *ps);

int main(int argc, const char * argv[]) {
    char str[256];
    char *p;
    
    printf("문장입력");
    gets(str);
    
    /*
    str 에 아무 값도 들어있지 않음을 확인하기 위해서 다음과 같은 test를 해봤다.
    
     1.
    if (str == NULL)
        printf("#####");
     str 에 아무것도 입력하지 않아도 #이 출력되지않다.
     
     2.
     if (*str == NULL)
        printf("#####");
     str에 아무것도 입력하지 않으면 #이 출력된다.
     
     그 이유에 대해서 알아보자.
     
     NUL 값은 말 그대로 '\0' 을 말하고,
     NULL pointer 는 pointer로서 값이 0x00000000 을 말하며, 흔히 (void *)0 으로 선언되어 있습니다.
     null string은 "" 즉, 빈 문자열이며, 흔히 길이가 1 이며 내용은 NUL 값이 하나 있는 string을 말합니다.
     
     c언어에서 NULL 은 ~~~ 이기 때문에
    */
    while((p=my_token(str))!=NULL)
    {
        printf("%s\n",p);
    }
    return 0;
}

char *my_token(char *str)
{
    static char *mp = NULL;
    static int end = 0;
    char *start, *tp;
    
    // NULL 이 return 되면 main이 종료 되므로 프로그램을
    // 끝내기 위해선 str이 NULL 이거나 end 가 1이어야한다.
    // str 에 아무 입력이 없으면 str == NULL 이 되서 끝난다.
    if ((str == NULL) || (end ==1))
    {
        return NULL;
    }
    
    // 위에서 mp를 NULL 로 초기화 했으므로 if문이 실행된다.
    if (mp == NULL)
    {
        // 입력받은 str을 start에 대입
        start = str;
    }
    //mp 에 값이 있으면
    else
    {
        // start에 mp 다음 주소를 넘겨준다.
        start = mp+1;
    }
    
    tp = start;
    
    while((*tp != '\0')&&(*tp !=' '))
    {
        // tp과 nul 도 아니고 공백도 아니면 tp를 다음문자의 주소를 가리키게 바꿔주고
        tp++;
    }
    
    if(*tp == '\0')
    {
        // '\0' 이었으면 end 에 1대입 그러면 다음 번 함수로 돌아왔을 때 프로그램이 종료된다.
        end = 1;
    }
    // '\0'이 아니면 그 자리에 '\0'을 넣어준다. 즉 공백에 \0을 넣어준 것
    else
    {
        *tp = '\0';
    }
    // mp = tp 가 되고
    mp = tp;
    // start를 return 한다.
    return start;
    
}


