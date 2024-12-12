#include <stdio.h>
#define MULTI 200

long Progap(long MonthlyEMI, long MonthlyEx, long Present, long progap)
{
    long total;
    long CN;
    total = (MonthlyEMI + MonthlyEx);
    CN = (MULTI * total);

    progap = (CN - Present);

    return progap;
};
int main()
{
    long MonthlyEMI;
    long MonthlyEx;
    long Present;
    long progap;

    printf("*****Enter deatils*****\n");
    printf("Enter Monthly Expenditure: \n");
    scanf("%ld", &MonthlyEx);
    printf("Enter Monthly EMI: \n");
    scanf("%ld", &MonthlyEMI);
    printf("Enter Present coverage: \n");
    scanf("%ld", &Present);
    progap = Progap(MonthlyEMI, MonthlyEx, Present, progap);
    printf("Progag %ld \n", progap);



    return 0;
}