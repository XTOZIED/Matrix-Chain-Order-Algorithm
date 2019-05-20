#include <iostream>
using namespace std;
//Referenced sudo code from pg. 377 of textbook.
void print(int** s, int i, int j){
	if(i == j)
		cout << "A" << i - 1;
	else{
		cout << "("; 
		print(s, i, s[i][j]); 
		print(s, s[i][j] + 1, j); 
		cout << ")";
	}
} 
/* void prMat(int **x, int n){
	cout << "Matrix M:" << endl;
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++)
			cout << x[i][j] << "\t";
		cout << endl;
	}	
} */
//Referenced sudo code from pg. 375 of textbook.
void matrixChainOrder(int* p,int n){
	int **m = new int*[n],**s = new int*[n];
	int j,q;
	//Initialize these two double pointers.
	for(int i = 1; i < n; i++){
		m[i] = new int[n];
		s[i] = new int[n];
		m[i][i] = 0;
	}
	//Calculating some numbers...
    for (int l = 2; l < n; l++){
        for(int i = 1; i < n-l+1; i++){
            j = i + l - 1;
            m[i][j] = 2147483647;
            for (int k = i; k <= j-1; k++){
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
					s[i][j] = k;
                }
				//prMat(m, n);
            }
        }
    }
	cout << m[1][n-1] << endl;
	//Print.
	print(s, 1,n-1);
	//Delete pointers in memory.
	for(int i = 1; i < n; i++){
		delete[] m[i];
		delete[] s[i];
	}
	delete[] m;
	delete[]s;
}
//Retreive values in main.
int main(){
	int numMatrix;
	cin >> numMatrix;
	int *data = new int[numMatrix + 1];
	for(int i = 0; i <= numMatrix; i++)
		cin >> data[i];
	matrixChainOrder(data,numMatrix + 1);
	cout << endl;
	delete[] data;
	return 0;
}
