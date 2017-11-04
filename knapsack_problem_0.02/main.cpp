//完全背包问题
#include <iostream>

using namespace std;
#define N 100
#define M 100
int n;
int capacity;
int f[M];
int weight[N];
int value[N];

void build()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weight[i] <= j) {
                f[j] = max(f[j], f[j - weight[i]] + value[i]);
            }
        }
    }
}

int main()
{
    return 0;
}