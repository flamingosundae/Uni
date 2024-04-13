#include <stdlib.h>
#include <stdio.h>

void istogramma(int h[], int n);

void main()
{
    int a[] = {1, 3, 5, -3, 5};
    int n = 5;
    istogramma(a, n);

}



void istogramma(int h[], int n)
{
    int i;
    int c, r;
    int max_r = 0;
    int min_r = 0;
    for(i = 0; i < n; i++)
    {
        if (h[i] > max_r)
        {
            max_r = h[i];
        }

        if(h[i] < min_r)
        {
            min_r = h[i];
        }
    }
    for(r = max_r; r > min_r; r--)
    {
        for(c=0; c < n; c++)
        {
            if (r == 0)
            {
                printf("-");
            }
            else if(r > 0)
            {
                if (h[c] >= r)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            else if(r < 0)
            {
                if(h[c] <= r)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}