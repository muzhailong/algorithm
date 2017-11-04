//01背包问题
#include <iostream>
#include <ctime>

using namespace std;
#define N 40
#define M 40

int m;
int n;

int weight[N];
int value[N];
int f[N][M];
int result[N];

void build()//dp算法
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (weight[i] <= j) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
}

void printObject()//打印选择的物品
{

    int i = n, j = m;
    while (i > 0 && j >= 0) {
        if (j >= weight[i] && (f[i][j] = f[i - 1][j - weight[i]] + value[i])) {
            result[i] = true;
            cout << i << "  ";
            j -= weight[i];
        }

        --i;
    }
}

int nextInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}


int main()
{
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        weight[i] = nextInt(1, m + n);
        value[i] = nextInt(1, n + m);
    }
    build();


    cout << f[n][m] << endl;

    printObject();
    for (int i = 1; i <= n; ++i) {
        if (result[i]) {
            cout << i << endl;
        }
    }

    return 0;
}