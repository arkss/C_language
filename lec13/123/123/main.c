
#include <stdio.h>
int *sum(int a, int b);

int main(int argc, const char * argv[]) {

    int m,n;
    int *p;
    printf("두수 입력해\n");
    scanf("%d %d",&m,&n);
    p = sum(m,n);
    printf("%d입니당!\n",*p);
}
int *sum(int a, int b)
{
    static int pt;
    printf("%d%d",a,b);
    pt = a +b;
    return &pt;
}
