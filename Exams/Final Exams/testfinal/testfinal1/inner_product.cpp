#include <iostream>
#include <list>
#include <vector>
using namespace std;

//TODO: implement a template function: inner_product

template<typename elemType, typename source_iter, typename dest_iter>
elemType inner_product(source_iter beg1, source_iter end1, dest_iter beg2, elemType init) {
	while (beg1 != end1) {
		init += (*beg1) * (*beg2);
		beg1++;
		beg2++;
	}
	return init;
}


int main() {
	vector<double> a;
	list<double> b;
	int i, n = 5;
	double x, y;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	cout << "int result:" << inner_product(a.begin(), a.end(), b.begin(), 0) << endl;
	cout << "double result:" << inner_product(a.begin(), a.end(), b.begin(), 0.0) << endl;
}

