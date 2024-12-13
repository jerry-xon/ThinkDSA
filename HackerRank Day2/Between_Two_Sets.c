#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{

    int result = ((a < b) ? a : b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }

    return result;
}

int findGCD(int b, int B[b])
{
    int result = B[0];
    for (int i = 1; i < b; i++)
    {
        result = gcd(result, B[i]);
    }
    if(result == 1){
        return 1;
    }
    return result;
}

int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
int getLCM(int a, int A[a]){
    int result = A[0];
    for(int i = 1 ; i < a ; i++){
        result = lcm(result,A[i]);
    }
    return result;
}
int getTotalX(int Alcm, int Bgcd)
{

   int count = 0;
    for (int x = Alcm; x <= Bgcd; x += Alcm) {
        if (Bgcd % x == 0) {
            count++;
        }
    }
    return count;
}
int main()
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int A[a];
    int B[b];
    
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &B[i]);
    }

    int Alcm = getLCM(a,A);
    int Bgcd = findGCD(b,B);

    int X = getTotalX(Alcm,Bgcd);

    printf("%d",X);
    return 0;
}
