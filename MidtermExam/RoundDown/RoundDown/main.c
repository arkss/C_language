#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    double a; // 소수점을 버린 값
    int b;    // 반올림한 값
    printf("값을 입력하세요");
    scanf("%lf",&a);
    
    if ((a-(int)a) < 0.5)
        b = (int)a;
    else
        b = (int)a + 1;
    
    printf("소수점을 버리는 식은 %d, 반올림 한 식은 %d\n",(int)a,b);
    
}

