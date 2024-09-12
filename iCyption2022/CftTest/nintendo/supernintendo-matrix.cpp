#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector <LL> VL;
typedef vector <VL> ML;

LL const MOD = 1e9+9;

ML identity(LL n){
	// constructing identity matrix of size n by n
	ML Id(n, VL(n));
	for (LL i = 0; i < n; i++){
		for (LL j = 0; j < n; j++){
			if ( i == j)
				Id[i][j] = 1;
			else
				Id[i][j] = 0;
		}
	}
	return Id;
}

ML multiply(ML A , ML B){
	// multiplying the matrix A and A
	LL rowA = A.size(); LL colA = A[0].size(); // dimension of the matrix A
	LL rowB = B.size(); LL colB = B[0].size(); // dimension of the matrix B
	assert(colA == rowB);
	ML R(rowA, VL(colB)); // R = A*B of size rowA x colB
	for (LL i = 0; i < rowA; i++){
		for (LL j = 0; j < colB; j++){
			R[i][j] = 0;
			for (LL k = 0; k < colA; k++){
				R[i][j] = (R[i][j] + (A[i][k]*B[k][j])%MOD)%MOD;
			}
		}
	}
	return R;
}

ML modmatexpo(ML A, LL k){
	// computing (A^k)%MOD
	LL row = A.size(); LL col = A[0].size();
	assert (row == col);
	ML Res(row,VL(row)); // a matrix of size row x row
	Res = identity(row);
	while (k > 0){
		if (k % 2 == 1){
			Res = multiply(Res,A);
		}
		k = k/2;
		A = multiply(A,A);
	}
	return Res;
}

LL s0, s1, s2, n;
int main(){
	cin >> n;
	s0 = 0; s1 = 0; s2 = 1;
	ML A {{1,1,0,2},{1,0,0,0},{0,1,0,0},{0,0,0,2}}; // 4-by-4 matrix
	ML Res(4,VL(4,0)); // exponentiation matrix
	ML s {{s2},{s1},{s0},{1}}; // the initial state vector
	if (n == 2)
		cout << 1 << "\n";
	else{
		Res = modmatexpo(A,n-2);
		ML Product = multiply(Res,s);
		cout << Product[0][0] << "\n";
	}
}