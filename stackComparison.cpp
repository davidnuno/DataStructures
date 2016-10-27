/*This program runs a binary tree along with its methods
PROBLEM:
Two stacks of the same type are the same if they have the same number of 
elements and their elements at the corresponding positions are the same. Overload
the relational operator == for the class stackType that returns a true if two stacks
of the same type are the same; it return false otherwise. Also, write the definition
of the function template to overload this operate.
*/

#include<iostream>
#include<cassert>

using namespace std;

template <class Type>
class stackType {
public:
	const stackType<Type>& operator=(const stackType <Type>&);
	bool stackType<Type>::operator==(const stackType<Type>& otherStack);
	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack()const;
	void push(const Type& newItem);
	Type top()const;
	void pop();
	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	~stackType();
private:
	int maxStackSize;
	int stackTop;
	Type *list;

	void copyStack(const stackType<Type>& otherStack);
	bool isEqual(const stackType<Type>& otherStack);
};
/*-------------------------------------------------------------*/
template <class Type>
void stackType<Type>::initializeStack() {
	stackTop = 0;
}
/*-------------------------------------------------------------*/
template<class Type>
bool stackType<Type>::isEmptyStack() const {
	return (stackTop == 0);
}
/*-------------------------------------------------------------*/
template<class Type>
bool stackType<Type>::isFullStack()const {
	return(stackTop == maxStackSize);
}
/*-------------------------------------------------------------*/
template<class Type>
void stackType<Type>::push(const Type& newItem) {
	if (!isFullStack()) {
		list[stackTop] = newItem;
		stackTop++;
	}
	else
		cout << "Cannot add to a full stack.\n";
}
/*-------------------------------------------------------------*/
template<class Type>
Type stackType<Type>::top()const {
	assert(stackTop != 0);
	return list[stackTop - 1];
}
/*-------------------------------------------------------------*/
template<class Type>
void stackType<Type>::pop() {
	if (!isEmptyStack())
		stackTop--;
	else
		cout << "Cannot remove from an empty stack.\n";
}
/*-------------------------------------------------------------*/
template<class Type>
stackType<Type>::stackType(int stackSize) {
	if (stackSize <= 0) {
		cout << "Size of the array to hold the stack must be positive.\n";
		cout << "Creating an array of size 100...\n" << endl;

		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;

	stackTop = 0;
	list = new Type[maxStackSize];
}
/*-------------------------------------------------------------*/
template<class Type>
stackType<Type>::~stackType() {
	delete [] list;
}
/*-------------------------------------------------------------*/
template<class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack) {
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxStackSize];

	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
}
/*-------------------------------------------------------------*/
template<class Type>
bool stackType<Type>::isEqual(const stackType<Type>& otherStack) {
	bool bRet = false;
	if (otherStack.maxStackSize == maxStackSize && otherStack.stackTop == stackTop) {
		bRet = true;
		for (int j = 0; j < stackTop; ++j) {
			if (otherStack.list[j] != list[j]) {
				// cout << "!=( " << j << ") " << otherStack.list[j] << "!=" << list[j];
				bRet = false;
				break;
			}
		}
	}
	return bRet;
}
/*-------------------------------------------------------------*/
template<class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack) {
	if (this != &otherStack)
		copyStack(otherStack);
	return *this;
}
/*-------------------------------------------------------------*/
template<class Type>
bool stackType<Type>::operator==(const stackType<Type>& otherStack) {
	return isEqual(otherStack);
}
template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item) {
	int count = 0;
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		if (list[mid] == item)
			found = true;
		else if (list[mid] > item)
			last = mid - 1;
		else
			first = mid + 1;
		count += 2;
	}
	if (found)
	{
		count--;
		cout << "Count: " << count << endl;
		return mid;
	}
	else
	{
		cout << "Count: " << count << endl;
		return -1;
	}
} //end binarySearch

/*-------------------------------------------------------------*/
int main() {
	int num;
	int arr []= { 5, 12, 25, 32, 38, 46, 58, 62, 85, 90, 97, 105, 110 };

	cout << "Binary search beginning...\n";

	binarySearch(arr, 13,60);
	cout << endl;

	system("pause");
	return 0;
}