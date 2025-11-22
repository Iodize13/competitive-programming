#include<stdio.h>
#include<string.h>
#define MAX_L (1005)
char input[MAX_L];

int main() {
	while(scanf("%s",input)!=EOF) {
		int i = 0;
		int length = strlen(input);
		int ans = 0;
		while(1) {
			// skip all English characters to find number
			while(i < length && (input[i] >= 'a' && input[i] <= 'z')) i++;
			// once found the number, go to the end of the number
			if(i < length) {
				ans++;
				while(i < length && (input[i] >= '0' && input[i] <= '9')) i++;
			}
			else break;
		}
		printf("%d\n",ans);
	}
}
