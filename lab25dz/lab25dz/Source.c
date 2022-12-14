#include <stdio.h>
#define N 10

void print_array(int A[])
{
    for (int i = 0; i < N; ++i)
        printf("%3d ", A[i]);
    printf("\n");
}
void main()
{
    int A[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int B[N] = { 0 };
    for (int i = 0; i < N; ++i)
        B[i] = A[N - 1 - i];
    print_array(A);
    print_array(B);
}