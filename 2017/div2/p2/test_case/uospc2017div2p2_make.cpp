/* University Of Seoul Programming Contest 2017
 * Division 2, Problem 2, "소공이의 씨꾸릿-★ 뽀올더"(Sogong's Secret Folder)
 * Written with C++ by Choe Hyeong Jin, AL林
 */

#include <iostream>
#include <cstdio>
using namespace std;

long long get_gcd(long long a, long long b){ // 유클리드 호제법
	return (a%b==0 ? b : get_gcd(b, a%b)); // 재귀함수. 삼항연산자.
}

int main(){
	long long folder_name, num_of_files;
	// 연산 도중 오버플로우 발생 방지를 위해 long long 으로 선언.
	FILE *in, *out;
	in = fopen("input10.txt", "r");
	out = fopen("uospc2017div2p2.10.out", "w");
	fscanf(in, "%lld %lld", &folder_name, &num_of_files);
	//cin >> folder_name >> num_of_files; // 폴더 이름과 파일 개수 입력.
	for(long long i=0;i<num_of_files;i++){
		long long file_name;
		fscanf(in, "%lld", &file_name);
		//cin >> file_name; // 파일 이름 입력.
		long long gcd = get_gcd(folder_name, file_name); // 폴더 이름과 해당 파일 이름의 최대공약수 구함.
		long long lcm = folder_name * file_name / gcd; // 폴더 이름과 해당 파일 이름의 최소공배수 구함.
		fprintf(out, "%lld\n", lcm);
		//cout << lcm << "\n"; // 최소공배수 출력.
	}
	fclose(in);
	fclose(out);
	return 0;
}