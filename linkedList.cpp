#include<iostream>

using namespace std;

typedef struct node {							//STRUCT TO HOLD INFO
	int info;									//HOLD INFO
	node *link;									//LINK TO NEXT NODE
}*nodePtr;

class linkedListType {
protected:
	nodePtr first;								//FIRST NODE OF LIST
	nodePtr last;								//LAST NODE OF LIST

public:											//DECLARE METHODS
	linkedListType();							
	void addNode(int newItem);
	void print();
	void printReverse();
};//END LINKED LIST TYPE CLASS

linkedListType::linkedListType() {
	first = last = NULL;
}//END CONSTRUCTOR

void linkedListType::addNode(int newItem) {
	nodePtr n;									//DECLARE NEW NODE POINTER
	n = new node;								//NEW NODE
	n->info = newItem;							//ASSIGN ITEM
	n->link = NULL;								//SET LINK TO NULL

	if (first == NULL) {						//IF LIST EMPTY 
		first = n;								//MAKE NODE 'N' FIRST
		last = n;								//MAKE NODE 'N' LAST
	}//END IF
	else {										//ELSE LIST NON EMPTY
		last->link = n;							//ADD NODE TO END OF LIST
		last = n;								//ASSIGN NEW LAST
	}//END ELSE
}//END ADD NODE METHOD

void linkedListType::print() {

	while (first != NULL) {
		cout << first->info << endl;
		first = first->link;
		print();
	}
}//END PRINT METHOD

void linkedListType::printReverse() {

	nodePtr temp1, temp2, temp3;				//PRINT THREE TEMPORARY NODE POINTERS

	temp1 = first;								//SET TEMP1 TO FIRST
	temp2 = NULL;		

	while (temp1 != NULL) {						//TRAVERSE THROUGH LIST
		temp3 = temp2;							//IN ORDER TO REVERSE LIST
		temp2 = temp1;
		temp1 = temp1->link;
		temp2->link = temp3;
	}//END WHILE

	first = temp2;
	print();									//PRINT RESULTS
}//END PRINT REVERSE METHOD

int main() {

	linkedListType dummyList;					//CREATE A DUMMY LIST FOR TESTING

	dummyList.addNode(10);						//ADD NODES
	dummyList.addNode(9);					
	dummyList.addNode(8);
	dummyList.addNode(7);

	dummyList.printReverse();					//PRINT LIST

	system("pause");
	return 0;
}//END MAIN

