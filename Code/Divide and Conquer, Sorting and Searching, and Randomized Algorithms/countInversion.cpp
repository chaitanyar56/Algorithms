#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
//merge and count split inversions
long long countSplitInversions(vector<int> left, vector<int> right, vector<int> &arr) {

	size_t i = 0,l = left.size();
	size_t j = 0,r = right.size();

	size_t k = 0;

	long long inv = 0;

	//merge left and right

	while(i < l && j < r) {


		if ( left[i] <= right[j] ) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];

			inv += l - i;
		}
	}

	//copy the remaining elements
	while( i < l) arr[k++] = left[i++];

	while( j < r) arr[k++] = right[j++];

	return inv;
}

long long countInversions(vector<int> &arr) {

	int n = arr.size();

	long long inv = 0;

	if (n == 1) {
		return 0;
	} else {
		//divide arr into left and right
		vector<int> left(arr.begin(), arr.begin() + n/2);
		vector<int> right(arr.begin() + n/2, arr.end());


		// inversions in each half
		inv += countInversions(left);
		inv += countInversions(right);

		//split inversions
		inv += countSplitInversions(left, right, arr);

		//return total inversions
		return inv;
	}
}


int main(){

	//test case 1
	vector<int> arr { 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };

	cout << "test case 1 inversions = " << countInversions(arr) << endl; // ans  = 590

	//for (size_t i =0; i < arr.size(); i++) cout << arr[i] << " ";
	//cout << endl;

	cout<<"test case 2 - data/IntegerArray_CountInv.txt" << endl;

	vector<int> arr2;

	ifstream myfile("data/IntegerArray_CountInv.txt");

	if (myfile.is_open()){
		int temp;
		while (myfile >> temp) arr2.push_back(temp);

	} else {
		cout<<"cant open the file" << endl;
	}

	cout << "inversions = " << countInversions(arr2) << endl;


	return 0;

}
