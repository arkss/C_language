//
//  main.c
//  number_pramid
//
//  Created by ark on 2018. 10. 2..
//  Copyright © 2018년 ark. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i,j;
    
    for(i=0;i<5;i++)
    {
        int number = 1;
        for(j=0;j<9;j++)
        {
            if ((j-i)<5 && (i+j)>3)
            {
                printf("%d",number);
                number++;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}
