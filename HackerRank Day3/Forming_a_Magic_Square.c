#include <stdio.h>
#include <stdlib.h>

int formingMagicSquare(int matrix[3][3])
{
    int magicSquares[8][3][3] = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};

        int mincost = 81;


        for(int k = 0 ; k < 8 ; k++){
            int cost = 0;

            for(int i = 0;i<3;i++){
                for(int j=0;j<3;j++){
                    cost += abs(matrix[i][j] - magicSquares[k][i][j]);
                }
            }
            if(cost < mincost){
                mincost = cost;
                }
        }
        return mincost;
}
int main()
{
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // printf("Enter element for matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int result = formingMagicSquare(matrix);
    printf("%d",result);
    return 0;
}