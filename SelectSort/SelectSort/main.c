/* 선택정렬
 1. 주어진 리스트 중 최소값 찾기
 2. 그 값을 맨 앞의 값과 교체
 3. 맨 처음 위치를 뺀 나머지를 같은 방법으로 교체
 */

#include <stdio.h>

int main(void) {
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    int min_index = 0;
    int i,j,temp;
    
    for (i=0;i<10;i++)
    {
        min_index = i;
        for (j=i+1;j<10;j++)
        {
            if (array[min_index] > array[j])
            {
                min_index = j;
            }
            temp = array[min_index];
            array[min_index] = array[i];
            array[i] = temp;
        }
    }
    for (i=0;i<10;i++)
        printf("%d|",array[i]);
}
