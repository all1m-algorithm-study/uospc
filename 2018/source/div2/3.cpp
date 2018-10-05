#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	bool flag;
	int n;
	char c;
	scanf("%d\n", &n);

	while (n--) {
		stack<char> st;
		flag = false;
		while ((c = getchar()) != '\n') {
			if (c == 'M') st.push(c);
			else if (c == 'W')
				if (st.empty()) flag = true;
				else st.pop();
		}
		if (!st.empty()) flag = true;
		flag == true ? printf("no\n") : printf("yes\n");
	}
	return 0;
}