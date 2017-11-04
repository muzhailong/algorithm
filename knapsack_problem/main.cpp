//01背包问题
#include <iostream>
#include <ctime>

using namespace std;

#define N 100
#define M 100
int f[N][M];
int capacity;
int n;
int weight[N];
int value[N];

void build()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weight[i] <= j) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
}

//随机整数
int nextInt(int minValue, int maxValue)
{
    return rand() % (maxValue - minValue + 1) + minValue;
}


int main()
{
    n = 10;
    capacity = 14;
    int minValue = 4;
    int maxValue = 15;

    srand(time(NULL));
    int i;

    for (i = 1; i <= n; ++i) {
        weight[i] = nextInt(minValue, maxValue);
        value[i] = nextInt(minValue, maxValue);
    }

    build();
    cout << f[n][capacity];

    return 0;
}

