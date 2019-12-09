#include <math.h>

/*
Nelson Swasono & Malia Bowman
CSE140 
Project 3
12/4/2019
*/


//REORDERING
//Implementation Details: Compared to the naive implementation, here we switched the first and second loops including the curly braces because it speeds up processing. 
void dgemm(int m, int n, float *A, float *C ){
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
			C[j + k * m] += A[j + i * m] * A[k + i * m];
			}
		}
	}
}


//UNROLLING
//Implementation Details: Very similar to the reordering (peephole) implementation but also included an if-else statement in the case that we can skip an iteration if we have an even length. 
void dgemm(int m, int n, float *A, float *C) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				if (m %2 != 0) {
					C[j + k * m] += A[j + i * m] * A[i + k * m];
				}
				else {
					C[j + k * m] += A[i + j * m] * A[i + k * m];
					C[j + (k + 1) * m] += A[i + j * m] * A{(k + 1) + i * m];
					k++;
				}
			}
		}
	}
}

//BLOCKING
//Implementation Details: Similar to the naive implementation, but with an added for loop to block the matrix.
void dgemm(int m, int n, float *A, float *C) {
	int blockSize = m;
	
	for (int l = 0; l < m; l+= blockSize) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					C[(l + k) + i * m] += A[(l + k) + i * m] * A[i + j * m];
				}
			}
		}
	}
}

//https://people.eecs.berkeley.edu/~driscoll/cs267/hw1.html 