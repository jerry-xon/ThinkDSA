#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printRandoms(int min, int max)
{
    return rand() % (max - min + 1) + min; 
}

void checker(int answer, int number)
{
    if (answer == number)
    {
        printf("Hurrayyy you won!\n");
    }
    else
    {
        printf("Oops, try again!\n");
    }
}

int main()
{
    int min = 0, max = 10;
    srand(time(NULL)); 

    int number = printRandoms(min, max); 
    int answer;
    
    printf("**********Enter any number between %d and %d**********\n", min, max);
    

    do {
        scanf("%d", &answer);
        checker(answer, number);
    } while (answer != number);

    return 0;
}
