#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
using namespace std;

set<int> s;
set<int>::iterator it;

int m[1005];
int a[1005];

int main() {
	int T;
	scanf("%d",&T);
	for(int rr=0;rr<T;rr++) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) m[i]=1;
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			m[a[i]]=0;
		}

		if(n==1) {
			printf("%d\n",a[0]-1);
			continue;
		}

		for(int i=1;i<=2*n;i++) {
			if(m[i]) s.insert(i);
		}

		if(a[0]>a[n-1]) {
			a[0]^=a[n-1];
			a[n-1]^=a[0];
			a[0]^=a[n-1];
		}

		// take care of the min(a[0],a[n-1])
		it = s.begin();
		int win = 0;
		if((*it)<a[0]) {
			win++;
			s.erase(it);
		}
		else{
			it++;
			s.erase(it);
		}

		// take care of the max(a[0],a[n-1])
		it=s.begin();
		if((*it)<a[n-1]) win++;
		s.erase(it);

		// take care of other rounds
		for(int i=1;i<n-1;i++) {
			it = s.lower_bound(a[i]);
			if(it==s.end()) {
				it=s.begin();
			}
			else {
				win++;
			}
			s.erase(it);
		}
		printf("%d\n",win);
	}
}
