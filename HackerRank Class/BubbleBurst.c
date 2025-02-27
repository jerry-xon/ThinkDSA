#include <stdio.h>

int cal(int nums[], int i, int n)
{
    if (i <= 0 || i >= n - 1)
        return 0;
    return nums[i - 1] * nums[i] * nums[i + 1];
}

int bubbleburst(int nums[], int n)
{
    int sum = 0;

    while (n > 2)
    {
        int current = nums[1];
        int index = 1;

        for (int j = 1; j < n - 1; j++)
        {
            if (nums[j] < current)
            {
                current = nums[j];
                index = j;
            }
        }

        sum += cal(nums, index, n);

        for (int k = index; k < n - 1; k++)
        {
            nums[k] = nums[k + 1];
        }
        n--;
    }

    if (nums[0] > nums[1])
    {
        sum += (nums[0] * nums[1]) + nums[0];
    }else{
        sum += (nums[0] * nums[1]) + nums[1];
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 2)
    {
        printf("0\n");
        return 0;
    }

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = bubbleburst(nums, n);
    printf("%d\n", result);

    return 0;
}
