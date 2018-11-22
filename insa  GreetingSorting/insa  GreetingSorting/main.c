// 기말에 삽입정렬 무조건 나옴

#include <stdio.h>
#include <string.h>

void init_intro(char (*intro)[80], char **pint);
int input_intro(char (*intro)[80]);
void sort_intro(char **pint, int cnt);
void print_intro(int mode, void *vp, int cnt);

int main(int argc, const char * argv[]) {
    
    char intro[10][80];
    char *pint[10];
    int cnt;
    
    init_intro(intro,pint);
    cnt = input_intro(intro);
    
    sort_intro(pint,cnt);
    print_intro(0,intro,cnt);
    printf("-----------------------------\n");
    print_intro(1,pint,cnt);
    
    
    return 0;
}
void init_intro(char (*intro)[80], char **pint)
{
    int i;
    
    for (i=0;i<10;i++)
    {
        pint[i] = intro[i];
    }
}

int input_intro(char (*intro)[80])
{
    int count = 0;
    
    while (1)
    {
        printf("인사말을 입력하세요\n");
        scanf("%s", intro[count]);
        if (strcmp(intro[count], "end") == 0)
        {
            break;
        }
        count++;
    }
    return count;
}

void sort_intro(char **pint, int cnt)
{
    int i,j;
    int min;
    char *temp;
    /*
    배열의 원소가 지금 cnt개 있다.
    표 1. strcmp()의 리턴값
    값    의미
    0보다 작음    string1이 string2보다 작음
    0    string1이 string2와 같음
    0보다 큼    string1이 string2보다 큼
    */
    for (i=0;i<cnt-1;i++)
    {
        min = i;
        for (j=i+1;j<cnt;j++)
        {
            if (strcmp(pint[min],pint[j]) > 0)
            {
                min = j;
            }
            if (min != i)
            {
                temp = pint[i];
                pint[i] = pint[min];
                pint[min] = temp;
            }
            
        }
    }
}

void print_intro(int mode, void *vp, int cnt)
{
    int i;
    // 입력한 순서대로 출력
    if (mode==0)
    {
        char (*intro)[80] = vp; // 배열 포인터
        /*
            다음과 같은 과정 없이
            printf("%s\n", vp[i]);
            라고 하면 vp는 void 형이기 때문에 사용이 불가능하다.
            따라서 원래의 데이터와 같게끔 바꿔줘야한다.
         
         */
        for(i=0;i<cnt;i++)
        {
            printf("%s\n", intro[i]);
        }
    }
    
    else
    {
        char **intro = vp;
        /*
         이중 포인터를 사용한 이유를 생각해보자.
         char *pint[10];
         다음과 같은 형태를 하고 있는데 pint[10] 는 intro 배열에서
         각각의 1차원 배열들 맨 앞을 가르키는 포인터이고 이를 다시 *로
         선언 했기 때문에 이중 포인터가 된다.
         
         char **intro;
         intro = (char **)vp;
         라고 쓸 수 있다.
         
         */
        
        
        for(i=0;i<cnt;i++)
        {
            printf("%s\n", intro[i]);
        }
    }
}
