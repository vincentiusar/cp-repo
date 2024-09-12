#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL volume(LL s, LL V, LL a, LL b){
	return s*(s+a)*(s+b) - V;
}

LL bisection(LL lo, LL hi, LL V, LL a, LL b){
	// finding the root of f(s) = s*(s+a)*(s+b) - V in [lo,hi]
	LL sol = -1; LL mid;
	if (((volume(lo,V,a,b) > 0) && (volume(hi,V,a,b) > 0)) || 
	((volume(lo,V,a,b) < 0) && (volume(hi,V,a,b) < 0))){
		// volume(lo,V,a,b)*volume(hi,V,a,b) > 0
		sol = -1; // no integer solution
	}
	else{
		bool found = false; // found = true if the root is found
		while ((hi - lo > 1) && (found == false)){
			// iteration is performed as long as hi - lo > 1 and the root isn't found
			mid = (lo + hi )/2; // the middle point
			if (volume(mid,V,a,b) == 0){
				found = true;
				sol = mid; // the root is mid
			}
			else if (((volume(lo,V,a,b) < 0) && (volume(mid,V,a,b) > 0)) || 
			((volume(lo,V,a,b) > 0) && (volume(mid,V,a,b) < 0))){
				// volume(lo,V,a,b) * volume(mid,V,a,b) < 0
				hi = mid; // the root is between lo and mid;
			}
			else{
				lo = mid; // the root is between mid and hi
			}
		}		
	}
	return sol;
}

LL solve(LL V, LL a, LL b){
	LL root = bisection(0,1000000,V,a,b);
	return root;
}

LL area(LL s, LL a, LL b){
	return 2*(s*(s+a) + s*(s+b) + (s+a)*(s+b));
}

int main(){
	LL V, a, b, root, q;
	cin >> q;
	while (q--){
		cin >> V >> a >> b;
		root = solve(V, a, b);
		if (root != -1){
			// cout << root << " " << root+a << " " << root+b << " " << area(root,a,b) << "\n";
			cout << area(root,a,b) << "\n";
		}
		else
			cout << "MUSTAHIL" << "\n";
	}
	return 0;
}