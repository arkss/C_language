/* 삽입정렬
 
 
 
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    
    int arr[5] = {1,3,2,4,5};
    
    int min; // 처음 index를 나타내는 값
    int i,j;
    int temp;
    
    for (i=0;i<4;i++)
    {
        min = i;
        for (j=i+1;j<5;j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; // 가장 작은 값이 있는 index를 저장
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            
        }
        
    }
    
    for (i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    
    
}
