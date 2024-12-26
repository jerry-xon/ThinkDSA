#include <stdio.h>
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int dayfine = 15;
    int monthfine = 500;
    int yearfine = 10000;
    int fine = 0;
    if (y1 == y2)
    {

        if (m1 == m2)
        {
            if (d1 <= d2)
            {
                fine = 0;
            }
            else if (d1 > d2)
            {
                fine += (d1 - d2) * dayfine;
            }
        }else if(m1<m2){
            fine = 0;
        }
        else if (m1 > m2)
        {

            fine += (m1 - m2) * monthfine;
        }
    }else if(y1 < y2){
        fine = 0;
    }
    else if (y1 > y2)
    {
        fine += (y1 - y2) * yearfine;
    }
    return fine;
}
int main()
{
    int d1, m1, y1;
    int d2, m2, y2;
    scanf("%d %d %d", &d1, &m1, &y1);
    scanf("%d %d %d", &d2, &m2, &y2);
    int fine = libraryFine(d1, m1, y1, d2, m2, y2);
    printf("%d", fine);

    return 0;
}