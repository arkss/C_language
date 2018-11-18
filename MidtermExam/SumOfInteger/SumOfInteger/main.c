#include <stdio.h>
int get_sum(int a, int b)
{
    int i;
    int sum;
    for(i=a;i<=b;i++)
    {
        sum += i;
    }
    return sum;
}
int main(void) {
    int a,b;
    int result;
    printf("두 수 사이의 합을 구합니다.");
    scanf("%d %d",&a,&b);
    result = get_sum(a,b);
    printf("합은 %d입니다.\n",result);
    
    
}
