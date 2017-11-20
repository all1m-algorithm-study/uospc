/* University Of Seoul Programming Contest 2017
 * Division 2, Problem 1, "세모왕 김세모"(Triangle King Kim Triangle)
 * Written with C++ by Choe Hyeong Jin, AL林
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define POW2(x) ((x)*(x))
using namespace std;

int main(){
	vector<long long> num(3); // 연산 도중 오버플로우 발생을 방지하기 위해 long long으로 선언한다.
	FILE *in, *out;
	in = fopen("input10.txt", "r");
	out = fopen("uospc2017div2p1.10.out", "w");
	for(int i=0;i<3;i++){
		fscanf(in, "%lld", &num[i]);
		//cin >> num[i]; // 세 변의 길이를 입력받는다.
	}
	sort(num.begin(), num.end()); // 오름차순 정렬
	if(POW2(num[0]) + POW2(num[1]) == POW2(num[2])){ // 피타고라스의 법칙이 성립한다면
		//cout << "YES";
		fprintf(out, "YES");
	}
	else{ // 성립하지 않는다면
		//cout << "NO";
		fprintf(out, "NO");
	}
	return 0;
}