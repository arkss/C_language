#include <stdio.h>

int fibo(int n)
{
    if (n==1)
        return 0;
    if (n==2)
        return 1;
    return fibo(n-1)+fibo(n-2);
}

int main(void) {
    int result;
    int n;
    printf("n값을 입력하세요.\n");
    scanf("%d",&n);
    result = fibo(n);
    printf("%d번째 피보나치 수는 %d 입니다.",n,result);
}
