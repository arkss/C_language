#include <stdio.h>

int main(void) {
    int n,i,j;
    int count =0;
    printf("n까지의 소수를 출력합니다.\n");
    scanf("%d",&n);
    for (i=2;i<=n;i++) // 2부터 n까지의 수를 검사한다.
    {
        
        for (j=2;j*j<=i;j++) // 루트를 쓰는 대신 제곱을 해서 대신 함
        {
            if (i%j==0)
                break;
        }
        if (j*j>i)
        {
            printf("%3d",i);
            count++;
            if (count == 5) // 5개씩 한 줄에 출력하기 위한 counting
            {
                
                printf("\n");
                count = 0;
            }
        }
    }
}
