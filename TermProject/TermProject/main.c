
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 선수 정보를 저장하는 구조체
struct player
{
    char name[20]; // 선수이름
    int birth_year; // 선수 탄생년도
    char position[8]; // 포지션
    int height; // 신장
    int weight; // 체중
};


int main(void)
{
    struct player list[10];
    int num;
    int i, index;
    int count;  // 선수의 수 저장
    int res;
    char temp[20];
    FILE *fp;
    
    while (1)
    {
        fp = fopen("player.txt","r");
        if (fp == NULL)
        {
            printf("파일이 열리지않았습니다.\n");
            exit(1);
        }
        printf("파일을 읽었습니다.\n");
        
        //파일에서 읽어온 데이터를 구조체 변수에 저장하기
        i=0;
        fseek(fp,0,SEEK_SET); // "a+" 로 열 시 파일 포인터가 파일의 끝을 가리키고 있으므로 아무 것도 저장하지 못한다. 따라서 포인터를 처음 위치로 옮겨야 한다.
        while (1)
        {
            res = fscanf(fp,"%s %d %s %d %d",list[i].name, &list[i].birth_year, list[i].position, &list[i].height, & list[i].weight);
            
            if (res == EOF) break;
            printf("%s %d %s %d %d\n",list[i].name, list[i].birth_year, list[i].position, list[i].height,  list[i].weight);
            i++;
        }
        fclose(fp);
        // 선수가 몇 명인지 count에 저장
        count = i;
        
        printf("총 %d명의 선수가 등록되어있습니다.\n",count);
        printf("(1) 선수검색\n(2) 선수등록\n(3) 선수삭제\n(4) 선수목록\n(5)프로그램 종료\n");
        scanf("%d",&num);
        
        switch(num)
        {
            case 1: // 선수 검색
            {
                while (1)
                {
                    printf("선수의 이름을 입력하세요. 검색을 종료하시려면 end를 입력하세요.\n");
                    scanf("%s",temp);
                    if (strcmp(temp,"end")==0)
                        break;
                    i = 0;
                    while (1)
                    {
                        if (strcmp(temp,list[i].name)==0)
                        {
                            printf("----검색한 선수의 프로필----\n");
                            printf("이름 : %s\n출생년도 : %d\n포지션 : %s\n신장 : %d\n몸무게 : %d\n", list[i].name,list[i].birth_year,list[i].position,list[i].height,list[i].weight);
                            break;
                        }
                        i++;
                        if (i == count)
                        {
                            printf("검색한 선수는 존재하지 않습니다.\n");
                            break;
                        }
                    }
                
                }
                break;
            }
            case 2: // 선수 등록
                fp = fopen("player.txt","a");
                while (1)
                {
                    printf("새로운 선수를 추가합니다.\n");
                    printf("추가할 선수의 이름을 입력하세요. 종료하려면 end를 입력하세요.\n");
                    scanf("%s",temp);
                    if (strcmp(temp,"end")==0)
                        break;
                    i = count + 1; // 마지막 선수의 다음 index에 추가를 해주기 위해 i의 값을 다음과 같이 지정
                    count++; // 선수가 추가되므로 선수를 하나 늘려준다.
                    strcpy(list[i].name,temp);
                    printf("추가할 선수의 출생년도를 입력하세요.\n");
                    scanf("%d",&list[i].birth_year);
                    printf("추가할 선수의 포지션을 입력하세요.\n");
                    scanf("%s",list[i].position);
                    printf("추가할 선수의 키를 입력하세요.\n");
                    scanf("%d",&list[i].height);
                    printf("추가할 선수의 몸무게를 입력하세요.\n");
                    scanf("%d",&list[i].weight);
                    printf("선수등록이 완료 되었습니다.\n");
                    
                    fprintf(fp,"%s %d %s %d %d\n",list[i].name,list[i].birth_year,list[i].position,list[i].height,list[i].weight);
                    
                }
                fclose(fp);
                break;
                
            case 3: // 선수 삭제
            {
                while(1)
                {
                    printf("기존의 선수를 삭제합니다.\n");
                    printf("삭제할 선수의 이름을 입력하세요. 종료하려면 end를 입력하세요.\n");
                    scanf("%s",temp);
                    if (strcmp(temp,"end")==0)
                        break;
                    for(i=0;i<count;i++)
                    {
                        // 입력한 선수의 정보 찾기
                        if (strcmp(list[i].name, temp)==0)
                        {
                            printf("%s의 정보를 삭제합니다.\n",list[i].name);
                            index = i; // 삭제할 선수의 index 저장
                            break;
                        }
                    }
                    if (i == count) // 마지막 선수까지 확인했을 때 동일한 선수가 없으면
                    {
                        printf("입력한 선수는 존재하지 않습니다.\n");
                        break;
                    }
                    for(i=index;i<count-1;i++)
                    {
                        list[i] = list[i+1];
                    }
                    count--; // 삭제되었으므로 전체 선수의 하나 감소
                    fp = fopen("player.txt","w");
                    for(i=0;i<count;i++) // 다시 파일에 써주기
                    {
                        fprintf(fp,"%s %d %s %d %d\n",list[i].name,list[i].birth_year,list[i].position,list[i].height,list[i].weight);
                    }
                     fclose(fp);
                }
               
                break;
            }
                
            case 4:
                printf("등록된 선수들의 명단입니다.\n");
                printf("\t선수이름\t\t 출생년도\t포지션\t 키\t   몸무게\n");
                for (i=0;i<count;i++)
                {
                    printf("%2d. %-13s %-4d %-9s %-6d %3d\n",i+1,list[i].name,list[i].birth_year,list[i].position, list[i].height,list[i].weight);
                }
                break;
                
            case 5:
                printf("프로그램을 종료합니다. 이용해주셔서 감사합니다.\n");\
                exit(0);
                
                    
                
        }
        
        
        
    }
}