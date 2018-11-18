/*
 문자열 검색 프로그램
 키보드로 입력한 문장에서 원하는 문자열을 찾아 그 개수를 출력하는 프로그램
 문장은 한 번만 입력하며 문자열 검색은 "end"가 입력될 때 까지 반복

*/
// 현재 실패 ㅠㅠㅠ
#include <stdio.h>
#include <string.h>

int main(void){
    int count =0;
    char *ptr;
    char str1[50];//검색대상이 되는 문자열
    char str2[20];//검색어를 저장할 배열
    
    printf("검색대상이 되는 문자열은?");
    scanf("%s",str1);
    printf("검색어가 되는 문자열은?");
    scanf("%s",str2);
    ptr=strstr(str1, str2);
    printf("%s\n",ptr);
    ptr=strstr(ptr,str2);
    printf("%s\n",ptr);
    
    while (ptr != NULL)
    {
        ptr=strstr(ptr,str2);
        count++;
       
    }
    printf("%s는 총 %d번 나옵니다.",str2,count);
    return 0;
    
}
