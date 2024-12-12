#include <stdio.h>

void Compair(int A[3], int B[3], int R[2])
{
    
    for(int i = 0;i<3;i++){
        if(A[i]>B[i]){
        R[0]++;
    }
    else if(A[i] == B[i]){
        R[i] = R[i];
    }
    else{
        R[1]++;
    }

    }

}
int main()
{
    int A[3];
    int B[3];
    int R[2] = {0,0};
    for (int i = 0; i < 3; i++)
    {
        
        scanf("%d", &A[i]);
    }
    for (int j = 0; j < 3; j++)
    {
       
        scanf("%d", &B[j]);
    }
    Compair(A,B,R);
    for(int i =0; i<2;i++){
        printf("%d ",R[i]);
    }
    return 0;
}