// 2. 꼬리잡기

// 출제의도
// 1. DFS를 구현할 수 있는가?
// 2. DFS의 탐색 진행 중 다음 탐색을 위해 현재 탐색에서 진행한 방문 여부를 초기화 할 수 있는가?

#include <cstdio>
#include <utility>

#define DIRECTION 4
#define SIZE 101
#define MAX(x,y) ((x)>(y))?x:y

int x_direction[DIRECTION]={-1,1,0,0};
int y_direction[DIRECTION]={0,0,-1,1}; //순서대로 상,하,좌,우 탐색 조건

using namespace std;

void search(int x,int y,int map[][SIZE],int max_tail[][SIZE],int visited[],int sum[][SIZE],int n,int m){
	int next_x; //다음 x방향
	int next_y; //다음 y방향
	
	visited[map[x][y]]=1; //현재 꼬리 번호 체크	 	
	
	for(int i=0;i<DIRECTION;i++){
		next_x=x+x_direction[i];
		next_y=y+y_direction[i];
		
		if(next_x>=0 && next_x<n && next_y>=0 && next_y<m && visited[map[next_x][next_y]]==0 && map[x][y]<map[next_x][next_y]){
			max_tail[next_x][next_y]=MAX(max_tail[next_x][next_y],max_tail[x][y]+1);
			//이번 탐색으로 다음에 잡을 꼬리의 갯수와 다른 경로를 통해 잡을 수 있는 꼬리 갯수 중 최댓값 선택
			sum[next_x][next_y]=MAX(sum[next_x][next_y],sum[x][y]+map[next_x][next_y]); 
			//이번 탐색으로 다음에 잡을 꼬리의 번호의 합과 다른 경로를 통해 잡을 수 있는 꼬리 번호의 합 중 최댓값 선택
			search(next_x,next_y,map,max_tail,visited,sum,n,m);
			visited[map[next_x][next_y]]=0; 			
			//다른 탐색을 위해 해당 탐색에서 이동했던 방문 여부 <초기화>
		}
		// 탐색 조건
		// 1. 다음에 이동할 지점은 구역 내의 지점
		// 2. 다음에 잡을 꼬리가 여태 잡은 꼬리인가 확인
		// 3. 다음에 잡을 꼬리가 자신이 잡았던 꼬리번호 보다 큰지 확인
	}
}//DFS 진행 함수
pair<int,int> max(int max_tail[][SIZE],int sum[][SIZE],int n,int m){
	pair<int,int> ret=make_pair(0,0); //first : 꼬리 갯수 , second : 꼬리 번호 합
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ret.first<=max_tail[i][j]){
				ret.first=max_tail[i][j];
				ret.second=MAX(ret.second,sum[i][j]);				
			}			
		}
	}
	return ret;
}//DFS 탐색을 끝낸 후 꼬리 갯수의 최댓값과 꼬리 번호 합의 최댓값 도출
int main(){
	int n; //총 세로
	int m; //총 가로
	int map[SIZE][SIZE]={0}; //입력값
	int max_tail[SIZE][SIZE]={0}; //꼬리 번호의 최대 갯수
	int sum[SIZE][SIZE]={0}; //꼬리 번호 합의 최대
	int visited[SIZE*SIZE]={0}; //배열로 여태 잡았던 꼬리 번호 체크
	pair<int,int> p;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	
	max_tail[0][0]=1;
	sum[0][0]=map[0][0]; //초기값 셋팅
	search(0,0,map,max_tail,visited,sum,n,m);
	
	p=max(max_tail,sum,n,m);
	printf("%d %d",p.first,p.second);
	
	return 0;
}
//시간 복잡도 : 4(4방향 탐색)*100(가로 길이)*100(세로 길이)*4(연산:max_tail,sum,visited,max) = 160000
//공간 복잡도 : 101(가로 길이)*101(세로 길이)*4(int:4Byte)*4(배열:map,max_tail,sum,visited) = 163216 (0.16MB)