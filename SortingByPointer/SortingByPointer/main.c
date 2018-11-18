// 키보드로 부터 실수를 3개 받고 크기 순으로 정렬하기
#include <stdio.h>


void swap(double *pA,double *pB);

void line_up(double *maxp,double *midp,double *minp);

int main(void) {
    double max,mid,min;
    printf("실수값을 3개 입력하세요.");
    scanf("%lf %lf %lf",&max,&mid,&min);
    line_up(&max,&mid,&min);
    printf("%.1lf|%.1lf|%.1lf",max,mid,min);
    
}

void swap(double *pA,double *pB)
{
    int temp;
    temp = *pA;
    *pA = *pB;
    *pB = temp;
}

void line_up(double *maxp,double *midp,double *minp)
{
    if (*minp < *midp)
        swap(minp,midp);
    if (*midp < *maxp)
        swap(maxp,midp);
    if (*minp < *midp)
        swap(minp,midp);
}
