#include<vector>
#include <iostream>

using namespace std;

vector<vector<int>> printNewSubSet(int elem, vector<vector<int>> temp){
	if(temp.size() == 0) {
		cout << "Some Thing Wrong!\n";
		exit(0);
	}

	for(auto& v_int : temp) {
		v_int.push_back(elem);
		cout << "[";
		for(auto v: v_int)
			cout << v << ",";
		cout << "\b]\n";
	}
	return temp;
}

vector<vector<int>> printTotalSubSet(int *a, unsigned int len){
	if(len == 0) {
		vector<vector<int>> v_v_int;
		vector<int> empty;
		v_v_int.push_back(empty);
		cout << "(),"; // empty set.
		return v_v_int;
	}

	vector<vector<int>> temp = printTotalSubSet(a, len-1); // n-1 TSS
	vector<vector<int>> newSubSet = printNewSubSet(a[len-1], temp); // merge (n-1 TSS) with nth element.

	temp.insert(end(temp), begin(newSubSet), end(newSubSet)); // combine temp and newSubset	
	return temp;
}

int main(int argc, char** argv)
{
	if(argc == 1) {
		cout << "Give a small number (suggested<=20).\n";
		return 0;
	}
	
	int N = atoi(argv[1]);
	int *a = (int*) malloc(sizeof(int) * N);
	for(unsigned int i = 0; i < N; ++i) {
		a[i] = i;
	}

	cout << "N = " << N << "\n";

	size_t len = printTotalSubSet(a, N).size();

	cout << "The Number of TSS: " << len << "\n";
	printf("\n");
	return 0;
}
