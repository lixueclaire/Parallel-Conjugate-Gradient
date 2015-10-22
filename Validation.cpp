#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;
const int N = 100010;
const double eps = 1e-5;
double a[N], b[N], c[N];

int main(int argc, char* argv[]){
	
	bool t = true;
	double x;

	ifstream f1("ans");
	if (!f1.is_open()) {
		cout<<"Error: ans file not found"<<endl;
		return 0;
	}
	int n = 0;
	while (f1 >> x) {
		a[n++] = x;
	}
	
	ifstream f2("cpu");
	if (!f2.is_open()) {
		cout<<"Error: cpu file not found"<<endl;
		return 0;
	}
	int n1 = 0;
	while (f2 >> x) {
		b[n1++] = x;
	}
	if (n1 != n) {
		cout<<"CPU file invalid!"<<endl;
		t = false;
	} else {
		for (int i = 0; i < n; i++)
			if (fabs(a[i] - b[i]) > eps) {
				cout<<"CPU file invalid!"<<endl;
				t = false;
				break;
			}
	}
	
	ifstream f3("mpi");
	if (!f3.is_open()) {
		cout<<"Error: mpi file not found"<<endl;
		return 0;
	}
	int n2 = 0;
	while (f3 >> x) {
		c[n2++] = x;
	}
	
	if (n2 != n) {
		cout<<"MPI file invalid!"<<endl;
		t = false;
	} else {
		for (int i = 0; i < n; i++)
			if (fabs(a[i] - c[i]) > eps) {
				cout<<"MPI file invalid!"<<endl;
				t = false;
				break;
			}
	}
	if (t)
		cout<<"Valid!"<<endl;
	
	return 0;
}
