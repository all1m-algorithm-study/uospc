// 팩토리얼 LCS
// 출제의도
// 1. DP의 개념이 깔려있는 LCS 알고리즘을 알고 있는가?
// 2. DP를 구현할 때 메모리를 최소화 할 수 있는가?
// 3. 팩토리얼 계산시 주어진 수가 큰 수라도 표현해낼 수 있는가?

#include <cstdio>

#define MAX(x,y) ((x)>(y))?x:y
#define SIZE 10000 //1~3000 -> 3000에서 9131자리(팩토리얼 함수 구현으로 도출가능)


int factorial(int number,int* seq){	
	int tmp_seq[SIZE]={0};
	int start_index;
	int end_index=1;
	int tmp=0;
	
	tmp_seq[1]=1;
	
	for(int i=2;i<=number;i++){		
		for(int j=1;j<=end_index;j++){
			tmp+=tmp_seq[j]*i;
			tmp_seq[j]=tmp%10;			
			tmp/=10;
		} // 주어진 자릿수 까지만 처리				 
		while(tmp){
			tmp_seq[++end_index]=tmp%10;
			tmp/=10;
		} // 위에서 자릿수를 벗어나서 남아있는 tmp값 처리 -> 자릿수 확장		
	}
	
	for(int i=1;i<=end_index;i++)
		seq[end_index-i+1]=tmp_seq[i]; //배열 역전
	
	return end_index;
}//팩토리얼 계산 -> 각 자릿수를 배열로 구성
int lcs(int* seq_1,int* seq_2,int seq_length_1,int seq_length_2){
	int check[2][SIZE]={0};	//자릿수가 크기 때문에 배열의 최소화
	int index=0;
	int max;	
	
	for(int i=1;i<=seq_length_1;i++){
		index=(index+1)%2; //인덱스 진동 0,1
		for(int j=1;j<=seq_length_2;j++){
			if(seq_1[i]==seq_2[j]){
				if(index==1)
					check[index][j]=MAX(check[index-1][j-1]+1,MAX(check[index-1][j],check[index][j-1]));				
				else
					check[index][j]=MAX(check[index+1][j-1]+1,MAX(check[index+1][j],check[index][j-1]));					
			}
			else{
				if(index==1)
					check[index][j]=MAX(check[index-1][j],check[index][j-1]);
				else
					check[index][j]=MAX(check[index+1][j],check[index][j-1]);
			}
		}			
	}
	max=check[index][seq_length_2];

	return max;
}//구해낸 수열로 LCS 계산
int main(){
	int num1;
	int num2; //주어진 수 A,B
	int seq_1[SIZE]={0};
	int seq_2[SIZE]={0}; //A,B를 통해 구해낸 팩토리얼의 각 자릿수
	int seq_length_1; //A! 길이
	int seq_length_2; //B! 길이
	
	scanf("%d %d",&num1,&num2);
	
	seq_length_1=factorial(num1,seq_1);
	seq_length_2=factorial(num2,seq_2);
	
	printf("%d",lcs(seq_1,seq_2,seq_length_1,seq_length_2));	
	
	return 0;
}


// 최대 메모리 : Check 배열 : 2(index)*10000(SIZE)*4Byte(int) = 80000(Byte) (128MB이내)
// 시간        : LCS함수 계산 : worst case - 10000*10000*2(if연산) = 2*10^8 (1초이내)
