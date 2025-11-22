#include<bits/stdc++.h>
using namespace std;

#define MP(x,y) (make_pair((x),(y)))

int T;
int n,k;

vector<pair<int,int> > edge_list;
vector<pair<int,long long> > edge[1005];

pair<int,int> marked_edge;
priority_queue<pair<long long, int>,
	       vector<pair<long long, int> >,
	       greater<pair<long long, int> > > q;
pair<long long, int> g;
bool visited[1005];
long long best_path, new_best_path;
vector<int> answer;

long long shortest_path() {
//     q = priority_queue<pair<long long, int>,
// 	       vector<pair<long long, int> >,
// 	       greater<pair<long long, int> > >();
	q.push(MP(0,1));
	for(int i=1;i<=n;i++) visited[i]=0;
	while(!q.empty()) {
		g = q.top();
		q.pop();
		int city = g.second;
		long long cost = g.first;
		if(city == n) return cost;
		if(visited[city]) continue;
		visited[city] = 1;
		for(int i=0;i<edge[city].size();i++) {
			int next = edge[city][i].first;
			long long new_cost = cost + edge[city][i].second;
            cerr << "new_cost: " << new_cost << ", city: " << city << ", next: " << next << '\n';
			if(marked_edge == MP(city, next) ||
			   marked_edge == MP(next, city)) {
                cerr << "F: " << marked_edge.first << ", S: " << marked_edge.second << '\n';
				new_cost += 2;
               }
			q.push(MP(new_cost,next));
		}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int rr = 0; rr<T;rr++) {
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;i++) {
			int a,b;
			long long r;
			scanf("%d %d %lld",&a,&b,&r);
			edge_list.push_back(MP(a,b));
			edge[a].push_back(MP(b,r));
			edge[b].push_back(MP(a,r));
		}
		marked_edge = make_pair(-1,-1);
		best_path = shortest_path();
        cerr << "best_path: " << best_path << '\n';
		for(int i=0;i<k;i++) {
			marked_edge = edge_list[i];
			new_best_path = shortest_path();
            cerr << "new_best_path: " << new_best_path << '\n';
			if(new_best_path <= best_path + 1) {
				answer.push_back(i+1);
			}
		}

		printf("%d",answer.size());
		for(int i=0;i<answer.size();i++) printf(" %d",answer[i]);
		printf("\n");

		while(!q.empty()) q.pop();
		edge_list.clear();
		for(int i=1;i<=n;i++) edge[i].clear();
		answer.clear();
	}
}
