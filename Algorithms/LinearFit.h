#ifndef LINEARFIT
#include <stdio.h>
#include <vector>
#include <tuple>
//#include <cmath>
#include <iostream>
#include <math.h>

std::vector<double> LUPSolve(std::vector<std::vector<double>> A, std::vector<int> pi, std::vector<double> b) {
	int n = A.size();
	double subtr = 0;
	std::vector<double> x;
	x.resize(n,0.0);
	std::vector<double> y(b);

	//y[0] = b[pi[0]];
	for (int i = 0; i < n; i++) {
		subtr = 0;
		for (int j = 0; j <= i-1 ; j++) {
			subtr += (A[i][j]*y[j]);
		}
		y[i] = b[pi[i]] - subtr;
	}

	//x[n - 1] = y[n - 1] / A[n-1][n-1];
	for (int i = n-1; i >= 0; i--)
	{
		subtr = 0;
		for (int j = i+1; j < n; j++) {
			subtr += (A[i][j] * x[j]);
		}
		x[i] = (y[i] - subtr) / A[i][i];
	}
	return x;
}

std::vector<int> LUPDecomposition(std::vector<std::vector<double>> &A) {
	int n = A.size();
	int kp = 0;
	std::vector<int> pi(n);

	for (int i = 0; i < n; i++) {
		pi[i] = i;
	}

	for (int k = 0; k < n; k++) {
		double p = 0;
		for (int i = k; i < n; i++) {
			if (fabs(A[i][k]) > p) {
				p = fabs(A[i][k]);
				kp = i;
        std::cout << "DATA: " << p << "\n";
			}
		}
		if (p == 0) {
			//std::cout << "singular error";
			return std::vector<int>(1, -1);
		}

		//exchange pi(k) w/ pi(k')
		int tmp = pi[k];
		pi[k] = pi[kp];
		pi[kp] = tmp;

    std::cout << "TEMP: " << tmp << "\n";

		for (int i = 0; i < n; i++) {
			//exchange A[k][i] w/ A[k'][i]
			tmp = A[k][i];
			A[k][i] = A[kp][i];
			A[kp][i] = tmp;
      std::cout << "TEMP2: " << tmp << "\n";
		}
		for (int i = k + 1; i < n; i++) {
			A[i][k] = A[i][k] / A[k][k];
			for (int j = k + 1; j < n; j++) {
				A[i][j] = A[i][j] - (A[i][k] * A[k][j]);
			}
		}
	}
	return pi;
}

void printVect(std::vector<std::vector<double>> &data) {
	//std::cout << "Dimensions: " << data.size() << " " << data[0].size() << "\n";
	for (int i = 0; i<data.size(); ++i) {
		for (int j = 0; j < data[0].size(); ++j) {
			//std::cout << data[i][j] << " ";
		}
		//std::cout << "\n";
	}
	getchar();
}

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> AT) {
	printVect(AT);
	int m = AT.size();
	int n = AT[0].size();
	std::vector<std::vector<double>> A(n, std::vector<double>(m)), ret(m, std::vector<double>(m));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[j][i] = AT[i][j];
		}
	}

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < m; col++) {
			for (int inner = 0; inner < n; inner++) {
				ret[row][col] += A[inner][row] * AT[col][inner];
				//std::cout << "A[" << inner << "][" << row << "] = " << A[inner][row] << " AT[" << col << "][" << inner << "] = " << AT[col][inner] << "\n";
				//std::cout << "ret[" << row << "][" << col << "] = " << ret[row][col] << "\n\n";
			}
		}
	}
	printVect(ret);
	return A;
}

template<class T, class F>
std::vector<double> fitFuncs(const std::vector<T> &data, const std::vector<F> &functions) {
  //for(auto a : data) { std::cout << a << "\n"; }
	int m = data.size();
	int n = functions.size();
	std::vector <int> pi;
	std::vector <double> y(m);
	std::vector<std::vector<double>> A(n, std::vector<double>(m)), AT(m, std::vector<double>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			AT[i][j] = functions[j](data[i].x);
			A[j][i] = functions[j](data[i].x);
		}
		y[i] = data[i].y;
	}
	
  // A= transpose(AT);

  std::vector<std::vector<double>> finA;
  std::vector<double> finB(functions.size(), 0.0);

  finA.resize(functions.size(), std::vector<double>(functions.size(),0.0));

  for(int i = 0; i < functions.size(); i++) {
    for(int j = 0; j < functions.size(); j++) {
      for(int k = 0; k < data.size(); k++) {
        finA[i][j] += (A[i][k] * AT[k][j]);
      }
    }
  }


  for(int i = 0; i < functions.size(); ++i) {
    for(int j = 0; j < data.size(); ++j) {
      finB[i] += (A[i][j] * y[j]); //this is wrong, working on wrong transposed thingie
    }
  }     
  
	pi = LUPDecomposition(finA);

  

  //std::vector<double> empty;
  //empty.push_back(99);
  //empty.push_back(99);
  //return empty;
	
  return LUPSolve(finA, pi, finB);
}

#endif
