#include <stdio.h>
 
int cur[5][5], max_cl[5][5], available[5];
int counter = 0, i, j, exe, resources, proceses, k = 1;
int m[5], run[5], safe_state = 0;
int allocation[5] = {0, 0, 0, 0, 0};

int main()
{
    printf("\nEnter number of proceses: ");
        scanf("%d", &proceses);
 
        for (i = 0; i < proceses; i++) 
    {
            run[i] = 1;
            counter++;
        }
 
        printf("\nEnter number of resources: ");
        scanf("%d", &resources);
 
        printf("\nEnter Claim Vector:");
        for (i = 0; i < resources; i++) 
    { 
            scanf("%d", &m[i]);
        }
 
       printf("\nEnter Allocated Resource Table:\n");
        for (i = 0; i < proceses; i++) 
    {
            for(j = 0; j < resources; j++) 
        {
              scanf("%d", &cur[i][j]);
            }
        }
 
        printf("\nEnter Maximum Claim Table:\n");
        for (i = 0; i < proceses; i++) 
    {
            for(j = 0; j < resources; j++) 
        {
                    scanf("%d", &max_cl[i][j]);
            }
        }
 
    printf("\nThe Claim Vector is: ");
        for (i = 0; i < resources; i++) 
    {
            printf("\t%d", m[i]);
    }
 
        printf("\nThe Allocated Resource Table:\n");
        for (i = 0; i < proceses; i++) 
    {
            for (j = 0; j < resources; j++) 
        {
                    printf("\t%d", cur[i][j]);
            }
        printf("\n");
        }
 
        printf("\nThe Maximum Claim Table:\n");
        for (i = 0; i < proceses; i++) 
    {
            for (j = 0; j < resources; j++) 
        {
                printf("\t%d", max_cl[i][j]);
            }
            printf("\n");
        }
 
        for (i = 0; i < proceses; i++) 
    {
            for (j = 0; j < resources; j++) 
        {
                    allocation[j] += cur[i][j];
            }
        }
 
        printf("\nAllocated resources:");
        for (i = 0; i < resources; i++) 
    {
            printf("\t%d", allocation[i]);
        }
 
        for (i = 0; i < resources; i++) 
    {
            available[i] = m[i] - allocation[i];
    }
 
        printf("\nAvailable resources:");
        for (i = 0; i < resources; i++) 
    {
            printf("\t%d", available[i]);
        }
        printf("\n");
 
        while (counter != 0) 
    {
            safe_state = 0;
            for (i = 0; i < proceses; i++) 
        {
                    if (run[i]) 
            {
                        exe = 1;
                        for (j = 0; j < resources; j++) 
                {
                                if (max_cl[i][j] - cur[i][j] > available[j]) 
                    {
                                    exe = 0;
                                    break;
                                }
                        }
                        if (exe) 
                {
                                printf("\nProcess%d is exeuting\n", i + 1);
                                run[i] = 0;
                                counter--;
                                safe_state = 1;
 
                                for (j = 0; j < resources; j++) 
                    {
                                    available[j] += cur[i][j];
                                }
                            break;
                        }
                    }
            }
            if (!safe_state) 
        {
                    printf("\nThe proceses are in unsafe_state state.\n");
                    break;
            } 
        else 
        {
                    printf("\nThe process is in safe_state state");
                    printf("\nAvailable vector:");
 
                    for (i = 0; i < resources; i++) 
            {
                        printf("\t%d", available[i]);
                    }
 
                printf("\n");
            }
        }
        return 0;
        printf ("\n this project has been made by @diti p@ndey")
}

