#include <iostream>
#include <algorithm>
#include <limits>
#define INF (INT64_MAX / 2)

typedef long long Long;

Long diff[1001];
Long diffSum[1001];
Long dp[1001][1001];

Long Cost(int i, int j)
{
    return (diffSum[j] - diffSum[i - 1]) * (j - i + 1);
}

Long Find(int memCount, int chCount)
{
    Long& result = dp[memCount][chCount];
    if (result != -1)
        return result;

    if (memCount == 1)
        return result = Cost(1, chCount);

    Long minTime = INF;
    for (int i = memCount - 1; i < chCount; ++i)
        minTime = std::min(minTime, Find(memCount - 1, i) + Cost(i + 1, chCount));

    return result = minTime;
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);

    for (int i = 1; i <= k; ++i)
    {
        scanf("%lld", diff + i);
        diffSum[i] = diffSum[i - 1] + diff[i];
    }

    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(Long), -1);

    printf("%lld", Find(n, k));

    return 0;
}