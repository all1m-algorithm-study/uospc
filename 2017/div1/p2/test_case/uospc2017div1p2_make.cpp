/* University Of Seoul Programming Contest 2017
 * Division 1, Problem 2, "음수의 개수"(The number of negatives)
 * Written with C++ by Kim Hoon, AL林
 */

#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<ctime>
#include<functional>
#include<deque>
using namespace std;

int N,Q;
int a[100004];
int tree[400004];

int init(int s,int e,int node){
    if(s==e){
        if(a[s]<0)
            return tree[node]=1;
        else
            return tree[node]=0;
    }
    else
        return tree[node] = init(s,(s+e)/2,node*2)+init((s+e)/2+1,e,node*2+1);
}
int minus_num(int s,int e,int u,int v,int node){
    if(v<s||e<u)
        return 0;
    if(u<=s&&e<=v)
        return tree[node];
    return minus_num(s,(s+e)/2,u,v,node*2)+minus_num((s+e)/2+1,e,u,v,node*2+1);
}
void change_mark(int s,int e,int u,int diff,int node){
    if(u<s||e<u)
        return;
    tree[node]+=diff;
    if(s!=e){
        change_mark(s,(s+e)/2,u,diff,node*2);
        change_mark((s+e)/2+1,e,u,diff,node*2+1);
    }
}
int main(){
    FILE *in, *out;
    in = fopen("input20.txt","r");
    out = fopen("output20.txt","w");
    fscanf(in, "%d %d",&N,&Q);
    for(int i=1;i<=N;i++){
        fscanf(in, "%d",&a[i]);
    }
    init(1,N,1); // initialize segment tree
    for(int i=0;i<Q;i++){
        int b;
        fscanf(in, "%d",&b);
        if(b==1){
            int x,y;
            fscanf(in, "%d %d",&x,&y);
            fprintf(out, "%d\n",minus_num(1,N,x,y,1));
        }
        else{
            int x;
            fscanf(in, "%d",&x);
            a[x] = -a[x]; // change a[x]'s mark
            if(a[x]<0){
                change_mark(1,N,x,1,1);
            }
            else{
                change_mark(1,N,x,-1,1);
            }
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
