#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class qs {
  public:
    int comparisons;

    qs() {
      comparisons = 0;
    }

    void clearComparisons () {
      comparisons = 0;
    }
    // function to sort the array using quick sort
    void quickSort(vector<int> &arr, int left, int right, int partitionType);
    //function to partition
    int partition(vector<int> &arr, int left, int right);
    //swap median to First
    void swapMedianOfThree(vector<int> &arr, int left, int right);
    // function to print the array
    void printVector(vector<int> arr);
};

void qs::printVector(vector<int> arr) {
  for(size_t i = 0; i < arr.size(); i++) cout<< arr[i] << " ";
  cout << endl;
}

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void qs::swapMedianOfThree(vector<int> &arr, int left, int right) {
  int diff = right - left - 1;
  int mid =  left + diff/2;
  int median;

  if ((arr[left] - arr[mid]) * (arr[right - 1] - arr[left]) > 0) {
       median = left;
   } else if ((arr[mid] - arr[left]) * (arr[right -1] - arr[mid]) > 0) {
       median = mid;
   } else {
       median = right - 1;
   }

  swap(arr[left],arr[median]);
}

int qs::partition(vector<int> &arr, int left, int right){

    comparisons += right - left - 1;

    int i = left + 1;

    for (int j = left +1; j < right; j++) {
      if (arr[j] < arr[left]) swap(arr[i++], arr[j]);
    }

    swap(arr[left], arr[i-1]);

    return i - 1;
}

//
void qs::quickSort(vector<int> &arr, int left, int right, int partitionType) {

  if (left == right) return;

  int pivotIndex;

  switch(partitionType) {
    //pivot = first element
    case 1: pivotIndex = partition(arr, left, right); break;
    //pivot = last element
    case 2: swap(arr[left], arr[right-1]); pivotIndex = partition(arr, left, right); break;
    // median
    case 3: swapMedianOfThree(arr,left,right);pivotIndex = partition(arr, left, right); break;
  }

  quickSort(arr, left, pivotIndex, partitionType);
  quickSort(arr, pivotIndex + 1, right, partitionType);




}

//test cases to check quickSort
int main() {

  vector<int> arr1 {11,18,5,20,8,10,3,2,17,4,13,7,12,9,6,16,19,15,1,14};

  vector<int> arr2 = arr1;
  vector<int> arr3 = arr1;

  qs test;
  // comparisons =73
  test.quickSort(arr1, 0, arr1.size(), 1);
  cout << "Pivot - First Element - Comparisons = " << test.comparisons << endl;
  //test.printVector(arr1);

  test.clearComparisons();
  //comparisons =73
  test.quickSort(arr2, 0, arr2.size(), 2);
  cout << "Pivot - Last Element - Comparisons = " << test.comparisons << endl;

  //test.printVector(arr2);

  test.clearComparisons();
  // comparisons = 56
  test.quickSort(arr3, 0, arr3.size(), 3);
  cout << "Pivot - MedianOfThree - Comparisons = " << test.comparisons << endl;

  //test.printVector(arr3);

  arr1.clear();
  arr2.clear();
  arr3.clear();

  test.clearComparisons();


  cout << "Test Case - data/QuickSort.txt" << endl;

  ifstream myfile("data/QuickSort.txt");

	if (myfile.is_open()){
		int temp;
		while (myfile >> temp) arr1.push_back(temp);

	} else {
		cout<<"cant open the file" << endl;
	}

  arr2 = arr1;
  arr3 = arr1;

  test.quickSort(arr1, 0, arr1.size(), 1);
  cout << "Pivot - First Element - Comparisons = " << test.comparisons << endl;

  test.clearComparisons();

  test.quickSort(arr2, 0, arr2.size(), 2);
  cout << "Pivot - Last Element - Comparisons = " << test.comparisons << endl;


  test.clearComparisons();

  test.quickSort(arr3, 0, arr3.size(), 3);
  cout << "Pivot - MedianOfThree - Comparisons = " << test.comparisons << endl;



  return 0;
}
