/*
The sequential search algorithm given in this chapter is nonrecursive. Write and
implement a recursive version of the sequential search algorithm
*/

#include<iostream>
#include<string>
using namespace std;

template <class elemType>
int seqSearch(const elemType list[], int length,
	const elemType& item)
{
	length = length - 1;
	if (length < 0)
		return -1;

	else if (item == list[length])
		return length;

	else {
		seqSearch(list, length, item);
	}
} //end seqSearch

int main() {
	int arr[] = { 10,5,8,21,48,27 };

	int location = seqSearch(arr, 6, 8);

	cout << "Your item is in location " << location << endl;

	system("pause");
	return 0;
}