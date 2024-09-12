#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second

int N, ans, X, capCity;
vector < pair <int, int > > nextDis[101000];
queue < pair <int, int> > BFS;
queue < pair <int, int> > getCost;
int level[101000];
bool visited[101000];

int main (){
	
	memset(level,-1,sizeof(level));
	
	cin >> N >> X;
	for (int i = 0; i < N; i++){
		int A, B, C; cin >> A >> B >> C;
		nextDis[A].pb({B, C});
		nextDis[B].pb({A, C});
	}
	for (int i = 1; i <= N + 1; i++){
		if (nextDis[i].size() == 1) {
			level[i] = 1;
			BFS.push({i,1});
		}
	}
	//Find Capital City
	while (!BFS.empty()){
		pair <int, int> now = BFS.front(); BFS.pop();
		bool done = true;
		for (int i = 0; i < nextDis[now.fi].size(); i++){
			int nextDistrik = nextDis[now.fi][i].fi;
			if (level[nextDistrik] == -1){
				level[nextDistrik] = now.se + 1;
				BFS.push({nextDistrik, now.se + 1});
				done = false;
			}
		}
		if (done){
			capCity = now.fi;
		}
	}
	//Count Cost
	memset(visited, false, sizeof(visited));
	getCost.push({X,0});
	
	while (!getCost.empty()){
		pair <int, int> now = getCost.front(); getCost.pop();
		if (now.fi == capCity){
			cout << now.se << endl;
			return 0;
		}
		for (int i = 0; i < nextDis[now.fi].size(); i++){
			int nextDistrik = nextDis[now.fi][i].fi;
			if (level[nextDistrik] > level[now.fi]) {
				getCost.push({nextDistrik, now.se + nextDis[now.fi][i].se });
			}
		}
	}
	
	
}
