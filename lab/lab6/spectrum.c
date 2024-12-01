#include <stdio.h>

int binarySearch(int x[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (x[mid] == mid + 1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int data[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }
    printf("%d\n",binarySearch(data,n));
}