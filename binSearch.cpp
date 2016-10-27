/*PROBLEM:
The binary search algorithm given in this chapter is nonrecursive. Write and implement
a recursive version of the sequential search algorithm.
*/
#include<iostream>

using namespace std;

template <class elemType>
int binarySearch(const elemType list[],int low, int high,
	const elemType& item)
{
	int mid = (high + low) / 2;

	if (low > high)
		return -1;

	if (list[mid] == item)
		return mid;

	else if (list[mid] > item)
		binarySearch(list, low, mid - 1, item);

	else
		binarySearch(list, mid + 1, high, item);
	
} //end binarySearch

int main() {

	int arr[] = { 11,15,19,20,22,25,29,40,45 };
	
	cout << "Item is at location " << binarySearch(arr, 0, 9, 11) << endl;

	system("pause");
	return 0;
}