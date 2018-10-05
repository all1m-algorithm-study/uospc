#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		char link[201];
		char res[201] = "https://www.youtube.com/embed/";
		scanf("%s", link);
		char *ptr = strtok(link, "/=");

		if (strcmp(ptr, "https:") || !ptr) 
			strcpy(res, "error");
		else if (!(ptr = strtok(NULL, "/="))) 
			strcpy(res, "error");
		else if (!strcmp(ptr, "www.youtu.be")) {
			ptr = strtok(NULL, "/=");
			strcat(res, ptr);
		}
		else if (!strcmp(ptr, "www.youtube.com")) {
			ptr = strtok(NULL, "/=");
			if (!strcmp(ptr, "embed")) {
				ptr = strtok(NULL, "/=");
				strcat(res, ptr);
			}
			else if(!strcmp(ptr, "watch?v")){
				ptr = strtok(NULL, "/=");
				strcat(res, ptr);
			}
			else
				strcpy(res, "error");
		}
		else 
			strcpy(res, "error");

		printf("%s\n", res);
	}
	
	return 0;
}