#include<stdio.h>
#include<stdlib.h>
int solve(int A, int B) {
    	// Compute the number of digits of A
	// and prepare 'base' power of 10 to compute the alpha-bonded pair
    	int base = 1, temp = A;
    	while (temp >= 10) {
        	base *= 10;
        	temp /= 10;
    	}

    	int ans = 0;
    	for (int n = A; n <= B; ++n) {
		// Compute the alpha-bonded pair of 'n'
        	temp = n;
        	while (true) {
            		temp = (temp / 10) + ((temp % 10) * base);
            		if (temp == n)
                		break;
            		if (temp > n && temp <= B)
                		ans++;
        	}
    	}
    	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		int A,B;
		scanf("%d %d",&A,&B);
		printf("%d\n",solve(A,B));
	}
}
