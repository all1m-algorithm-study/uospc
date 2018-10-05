#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, score[2], oc[2], turn, innings;
bool base[2][5], inning_start;
string str;

void BB_func(int t)
{
    int i = 1;
    while(base[t][i])
        i++;
    for(int j=1; j<=i; j++)
        base[t][j] = true;
    if(base[t][4])
    {
        base[t][4] = false;
        score[t]++;
    }
}

void GO_func(int t)
{
    oc[t]--;
    if(oc[t] <= 0)
        return;
    for(int i=3;i>0;i--)
    {
        if(base[t][i])
        {
            base[t][i+1] = true;
            base[t][i] = false;
        }
    }
    if(base[t][4])
    {
        score[t]++;
        base[t][4] = false;
    }
    return;
}

void OF_func(int t)
{
    oc[t]--;
    if(oc[t] <= 0)
        return;
    if(base[t][3])
    {
        score[t]++;
        base[t][3] = false;
    }
    return;
}

void HR_func(int t)
{
    int cnt = 1;
    for(int i=1;i<4;i++)
    {
        if(base[t][i])
        {
            base[t][i] = false;
            cnt++;
        }
    }
    score[t] += cnt;
    return;
}
void nH_func(int num, int t)
{
    base[t][0] = true;
    for(int i=3;i>=0;i--)
    {
        if(base[t][i])
        {
            base[t][i] = false;
            int temp = i+num;
            if(temp > 3)
                score[t]++;
            else
                base[t][temp] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inning_start = true;
    cin >> n;
    turn = 1;
    for(int i=0;i<n;i++)
    {
        if(oc[turn] <= 0)
        {
            inning_start = true;
            memset(base, false, sizeof base);
            turn = 1 - turn;
        }
        if(inning_start)
        {
            inning_start = false;
            oc[turn] = 3;
            innings++;
        }
        cin >> str;
        if(str == "K")
        {
            oc[turn]--;
        }
        else if(str == "BB")
        {
            BB_func(turn);
        }
        else if(str == "GO")
        {
            GO_func(turn);
        }
        else if(str == "IF")
        {
            oc[turn]--;
        }
        else if(str == "OF")
        {
            OF_func(turn);
        }
        else if(str == "HR")
        {
            HR_func(turn);
        }
        else
        {
            int num = str[0]-'0';
            nH_func(num ,turn);
        }
    }
    cout << innings << '.' << oc[0] << '\n' << score[0] << '\n' << innings << '.' << oc[1] << '\n'  << score[1] << '\n';
}

