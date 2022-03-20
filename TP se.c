#include <stdio.h>
int main()
{
    int pageref[] = {0,0,1,0,3,1,2,2,4,4,3,0};
    int defaultpage = 0;
    int cadre = 4;
    int i, n, s,pg;

    pg= sizeof(pageref)/sizeof(pageref[0]);
    printf("reference \t cadre 1 \t cadre 2 \t cadre 3");
    int temp[cadre];
    for(i = 0; i < cadre; i++)
    {
        temp[i] = -1;
    }
    for(i = 0; i < pg; i++)
    {
        s = 0;
        for(n = 0; n < cadre; n++)
        {
            if(pageref[i] == temp[n])
            {
                s++;
                defaultpage--;
            }
        }
        defaultpage++;
        
        if((defaultpage <= cadre) && (s == 0))
        {
            temp[i] = pageref[i];
        }
        else if(s == 0)
        {
            temp[(defaultpage - 1) % cadre] = pageref[i];
        }
      
        printf("\n");
        printf("%d\t\t\t",pageref[i]);
        for(n = 0; n < cadre; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf("/ \t\t\t");
        }
    }
    printf("\nTotal default page:\t%d\n", defaultpage);
    return 0;
}

