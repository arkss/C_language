#include <stdio.h>

int main(void) {
    int a;
    printf("값을 입력하세요.");
    scanf("%d",&a);
    a>=0 ? printf("양수입니다.") : printf("음수입니다.");
}
