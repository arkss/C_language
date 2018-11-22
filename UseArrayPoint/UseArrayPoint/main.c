
#include <stdio.h>
#include <string.h>

int main(void)
{
    int ary[4][7] = {
        {70,45,100,92,150,81},
        {88,92,77,30,52,55},
        {50,90,88,75,77,49},
        {120,92,80,150,130,105}
    };
    int i, j;
    int total;
    int *temp;
    int max;
    int *sort[4] = {ary[0],ary[1],ary[2],ary[3]};
    
    
     //sort 초기화 시키기, 각 1차원 배열들의 맨 앞 주소로 초기화 된다.
   /*
    sort[0] = ary[0];
    sort[1] = ary[1];
    sort[2] = ary[2];
    sort[3] = ary[3];
   */
    for(i=0;i<4;i++)
    {
        printf("%p\n", sort[i]);
    }
    
    // 평균구하기
    for (i=0;i<4;i++)
    {
        total = 0;
        for (j=0;j<6;j++)
        {
            total += ary[i][j];
            
        }
        ary[i][6] = total / 6;
    }
    
    
    // 각 1차원 배열의 첫번째 주소를 가르키는 sort 배열을 sorting하기
    
    for(i=0;i<3;i++)
    {
        max = i;
        for(j=i+1;j<4;j++)
        {
            if (sort[j][6] > sort[max][6] )
            {
                max = j;
            }
            
            if( max != i)
            {
                temp = sort[i];
                sort[i] = sort[max];
                sort[max] = temp;
            }
        }
    }
    // 바꿘 데이터 출력
    for (i=0;i<4;i++)
    {
        for (j=0;j<7;j++)
        {
            printf("%5d", sort[i][j]);
        }
        printf("\n");
    }
    
    printf("------------------------------------\n");
    // 원래 데이터 출력
    for (i=0;i<4;i++)
    {
        for (j=0;j<7;j++)
        {
            printf("%5d", ary[i][j]);
        }
        printf("\n");
    }
    
    
    

    
    return 0;
    
}




