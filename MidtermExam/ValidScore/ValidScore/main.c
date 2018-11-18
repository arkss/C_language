#include <stdio.h>

int main(void) {
    int i,j,temp,sum;
    int score[5];
    for(i=0;i<5;i++) // 값 5개 입력받기
    {
        printf("%d번째 심사위원의 점수를 입력하세요.",i+1);
        scanf("%d",&score[i]);
    }
    
    // 최고점과 최소점을 제외하기 위해서 버블정렬하기
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if (score[j] > score[j+1] )
            {
                temp = score[j+1];
                score[j+1] = score[j];
                score[j] = temp;
            }
        }
    }
    printf("유효점수는 ");
    for (i=1;i<4;i++) // 유효점수 출력
    {
        printf("%d|",score[i]);
        sum += score[i];
    }
    printf("다음과 같습니다.");
    printf("유효점수의 평균은 %d과 같습니다.",sum / 3);
}
