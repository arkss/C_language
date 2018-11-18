// 길이가 가장 긴 단어 찾기
// mac 에서의 EOF은 ctrl + D 이다.
#include <stdio.h>

int main(void)
{
    int ch;
    int len, max = 0;
    
    while (1)
    {
        len = 0;
        ch = getchar();
        while ((ch != -1) && (ch != '\n'))
        // 버퍼에는 \n 도 들어가는데 이는 len의 개수로 세주면 안되므로 고려해줘야 한다.
        {
            len++;
            ch = getchar();
        }
        if (ch == -1)
        {
            break;
        }
        if (len > max)
        {
            max = len;
        }
    }
    printf("max = %d\n", max);
    
    
    return 0;
}

