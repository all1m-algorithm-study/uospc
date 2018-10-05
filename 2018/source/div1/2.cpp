#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int N;

struct MAT{
    long long m[3][3];

    MAT operator * (const MAT &t)const{
        MAT ret;
        for (int i=0;i<3;i++) for (int j=0;j<3;j++){
            ret.m[i][j] = 0;
            for (int k=0;k<3;k++) ret.m[i][j] = (ret.m[i][j] + m[i][k]*t.m[k][j])%MOD;
        }
        return ret;
    }
} A, B;


int main()
{
    scanf("%d", &N);
    N--;
    A.m[0][0] = 1;
    for (int i=0;i<3;i++) B.m[0][i] = 1; // every column = 1
    for (int i=1;i<3;i++) B.m[i][i-1] = 1; // diagonal = 1
    for (;N;N>>=1,B=B*B) if (N&1) A = A*B; // while(N div 2) B=B*B, --> N--> binary : N=2^n+2^(n-1)+2^(n-2)+...  
    printf("%d\n", A.m[0][0]);
}


