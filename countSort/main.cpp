//计数排序
#include <iostream>


void swap(int &a, int &b)
{

    int c = a;
    a = b;
    b = c;
}

int choose_pivot(int A[], int left, int right)
{
    int mid = (left + right) / 2;
    if (A[left] > A[mid]) {
        swap(A[left], A[mid]);
    }

    if (A[mid > A[right]]) {
        swap(A[mid], A[right]);
    }

    if (A[left] > A[right]) {
        swap(A[left], A[right]);
    }

    swap(A[mid], A[right - 1]);
    return A[right - 1];
}

void quick_choose(int A[], int left, int right, int k)
{

    if (left >= right) {
        return;
    }
    int i, j;
    int pivot = choose_pivot(A, left, right);
    i = left;
    j = right - 1;

    while (true) {
        while (A[++i] < pivot) {}

        while (A[--j] > pivot) {}

        if (i >= j) {
            break;
        }
        swap(A[i], A[j]);
    }

    swap(A[i], A[right - 1]);

    if (k > i) {
        quick_choose(A, i + 1, right, k);
    } else if (k < i) {
        quick_choose(A, left, i - 1, k);
    }
}


void sort(int A[], int B[], int len)
{
    quick_choose(A, 0, len - 1, len - 1);
    int maxValue = A[len - 1];

    int *tempArr = new int[maxValue + 1]{0};
    int i;
    for (i = 0; i < len; ++i) {
        ++tempArr[A[i]];
    }

    for (i = 1; i <= maxValue; ++i) {
        tempArr[i] = tempArr[i] + tempArr[i - 1];
    }

    for (i = len - 1; i >= 0; --i) {
        B[--(tempArr[A[i]])] = A[i];
    }

    delete[] tempArr;
}


int main()
{
    int A[] = {12, 12, 33, 15, 24};
    int B[5];
    sort(A, B, 5);
    return 0;
}