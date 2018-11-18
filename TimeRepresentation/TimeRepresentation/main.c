#include <stdio.h>

int main(void) {
    double time;
    int hour,min,sec;
    printf("시간을 입력하세요.");
    scanf("%lf",&time);
    
    sec = time * 60 * 60;
    
    min = sec / 60;
    hour = min / 60;
    min = min % 60;
    sec = sec % 60;
    
    printf("시간은 %d시 %d분 %lf초 입니다.",hour,min,sec);
    
    
}
