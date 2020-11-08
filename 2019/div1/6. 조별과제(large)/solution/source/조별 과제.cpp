#include <iostream>
#include <algorithm>
#define DIFF_MAX_COUNT 10000
#define MEM_MAX_COUNT 1000

typedef long long Long;

// chCount > memCount
int chCount;
int memCount;
Long diff[DIFF_MAX_COUNT + 1];
Long diffSum[DIFF_MAX_COUNT + 1];
Long dp[MEM_MAX_COUNT + 1][DIFF_MAX_COUNT + 1];
Long properK[MEM_MAX_COUNT + 1][DIFF_MAX_COUNT + 1];

Long Cost(int i, int j)
{
    return (diffSum[j] - diffSum[i - 1]) * (j - i + 1);
}

void Find(int memNum, int l, int r, int p, int q)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    dp[memNum][mid] = -1;
    properK[memNum][mid] = -1;

    for (int k = p; k <= q; ++k)
    {
        Long current = dp[memNum - 1][k] + Cost(k + 1, mid);

        if (dp[memNum][mid] == -1 || dp[memNum][mid] > current)
        {
            dp[memNum][mid] = current;
            properK[memNum][mid] = k;
        }
    }

    Find(memNum, l, mid - 1, p, properK[memNum][mid]);
    Find(memNum, mid + 1, r, properK[memNum][mid], q);
}

int main()
{
    scanf("%d %d", &chCount, &memCount);

    for (int i = 1; i <= chCount; ++i)
    {
        scanf("%lld", diff + i);
        diffSum[i] = diffSum[i - 1] + diff[i];
    }

    for (int i = 1; i <= chCount; ++i)
        dp[1][i] = Cost(1, i);

    for (int memNum = 2; memNum <= memCount; ++memNum)
        Find(memNum, 1, chCount, 1, chCount);

    printf("%lld", dp[memCount][chCount]);

    return 0;
}