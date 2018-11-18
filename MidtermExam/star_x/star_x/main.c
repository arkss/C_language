//
//  main.c
//  star_x
//
//  Created by ark on 2018. 10. 2..
//  Copyright © 2018년 ark. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i,j;
    for (i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if ((i==j) || ((i+j)==4))
                printf("*");
            else
                printf(" ");
        
        }
        printf("\n");
    }
}
