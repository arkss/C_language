/*
최초 설정한 시간에서 일정 시간이 흐른 후 현재 시간을 출력하는 프로그램
최초 시간 설정은 24시간 단위로 입력하며 출력할 때는 AM, PM을 사용하여 12시간 단위로 출력
아래의 제시된 함수를 구현하고 실행 결과를 참고
void set(int h, int m);        // 최초 시간과 분을 설정하는 함수
void show(void);        // 시간과 분을 화면에 출력하는 함수
void move(void);        // 한 번 호출될 때마다 1분씩 시간 증가
[실행 결과]
최초 시간과 분 입력 (24시간): 11 55 (enter)    // 최초 설정 시간 입력
설정된 시간: 11:55(AM)            // 설정된 시간 출력
경과 시간 입력(분): 10 (enter)        // 경과된 시간 입력
현재 시간: 12: 05(PM)                // 현재 시간 출력
*/
#include <stdio.h>

int hour, min;

void set(int h, int m);
void show(void);
void move_(void);

int hour, min;

int main(int argc, const char * argv[]) {
    int i;
    int h,m;
    
    printf("시간과 분을 입력하세요.");
    scanf("%d %d", &h,&m);
    set(h,m);
    printf("몇 분 추가할지 입력하세요.");
    scanf("%d", &m);
    for (i=0;i<m;i++)
    {
        move_();
    }
    show();
    
    return 0;
}

void set (int h, int m)
{
    hour = h;
    min = m;
}

void move_(void)
{
    min += 1;
    if (min>=60)
    {
        min -= 60;
        hour += 1;
    }
}

void show (void)
{
    if (hour >= 12)
        printf("현재 시간: %d: %d(PM)",hour,min);
    else
        printf("현재 시간: %d: %d(AM)",hour,min);
}
