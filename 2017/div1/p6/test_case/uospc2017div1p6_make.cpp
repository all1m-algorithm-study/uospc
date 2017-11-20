/* University Of Seoul Programming Contest 2017
 * Division 1, Problem 6, "정기관의 이상한 엘리베이터"(The weird elevator in IT Bldg.)
 * Written with C++ by Kim Hoon, AL林
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
int arr[501][1001];
int value[501];
int s, m;

int func(int a, int b)
{
    int &ret = arr[a][b];
    if(ret != -1)
        return ret;
    if(a == n)
        return ret = b;

    ret = -101010;
    if(b-value[a] >= 0)
    {
        ret = max(ret, func(a+1, b-value[a]));
    }
    if(b+value[a] <= m)
    {
        ret = max(ret, func(a+1, b+value[a]));
    }
    return ret;
}

int main()
{
    memset(arr, -1, sizeof arr);
    FILE *in, *out;
    in = fopen("input20.txt", "r");
    out = fopen("output20.txt","w");
    fscanf(in, "%d %d %d",&n,&s,&m);
    for(int i=0;i<n;i++)
        fscanf(in, "%d", &value[i]);

    arr[0][s] = func(0, s);
    if(arr[0][s] < 0)
    {
        fprintf(out, "-1\n");
        return 0;
    }
    fprintf(out, "%d\n", arr[0][s]);

    return 0;
}
