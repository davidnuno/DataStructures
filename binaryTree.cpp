/*PROBLEM:
Write the definition of the function nodeCount, that returns the number of
nodes in the binary tree. Add this function to the class binaryTreeType and create
a program to test this function.*/

#include<iostream>

using namespace std;

template<class elemType>
struct node {														//STRUCT TO STORE NODE INFO
	elemType info;													//NODE INFO
	node *lLink;													//NODE LEFT LINK
	node *rLink;													//NODE RIGHT LINK
};

template<class elemType>
class binaryTreeType {
public:
	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	//Copy constructor
	binaryTreeType();
	//Default constructor
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
	//Overload the assignment operator.
	bool isEmpty() const;
	//Function to determine whether the binary tree is empty.
	//Postcondition: Returns true if the binary tree is empty;
	// otherwise, returns false.
	void inorderTraversal() const;
	//Function to do an inorder traversal of the binary tree.
	//Postcondition: Nodes are printed in inorder sequence.
	void preorderTraversal() const;
	//Function to do a preorder traversal of the binary tree.
	//Postcondition: Nodes are printed in preorder sequence.
	void postorderTraversal() const;
	//Function to do a postorder traversal of the binary tree.
	//Postcondition: Nodes are printed in postorder sequence.
	int treeHeight() const;
	//Function to determine the height of a binary tree.
	//Postcondition: Returns the height of the binary tree.
	int treeNodeCount() const;
	//Function to determine the number of nodes in a
	//binary tree.
	//Postcondition: Returns the number of nodes in the
	// binary tree.
	int treeLeavesCount() const;
	//Function to determine the number of leaves in a
	//binary tree.
	//Postcondition: Returns the number of leaves in the
	// binary tree.
	void destroyTree();
	//Function to destroy the binary tree.
	//Postcondition: Memory space occupied by each node
	// is deallocated.
	// root = NULL;
	virtual bool search(const elemType& searchItem) const = 0;
	//Function to determine if searchItem is in the binary
	//tree.
	//Postcondition: Returns true if searchItem is found in
	// the binary tree; otherwise, returns
	// false.
	virtual void insert(const elemType& insertItem) = 0;
	//Function to insert insertItem in the binary tree.
	//Postcondition: If there is no node in the binary tree
	// that has the same info as insertItem, a
	// node with the info insertItem is created
	// and inserted in the binary search tree.
	virtual void deleteNode(const elemType& deleteItem) = 0;
	//Function to delete deleteItem from the binary tree.
	//Postcondition: If a node with the same info as
	// deleteItem is found, it is deleted from
	// the binary tree.
	// If the binary tree is empty or
	// deleteItem is not in the binary tree,
	// an appropriate message is printed.
	~binaryTreeType();
	//Destructor
protected:
	node<elemType> *root;
private:
	int count;
	void copyTree(node<elemType>* &copiedTreeRoot,
		node<elemType>* otherTreeRoot);
	//Makes a copy of the binary tree to which
	//otherTreeRoot points.
	//Postcondition: The pointer copiedTreeRoot points to
	// the root of the copied binary tree.
	void destroy(node<elemType>* &p);
	//Function to destroy the binary tree to which p points.
	//Postcondition: Memory space occupied by each node, in
	// the binary tree to which p points, is
	// deallocated.
	// p = NULL;
	void inorder(node<elemType> *p) const;
	//Function to do an inorder traversal of the binary
	//tree to which p points.
	//Postcondition: Nodes of the binary tree, to which p
	// points, are printed in inorder sequence.
	void preorder(node<elemType> *p) const;
	//Function to do a preorder traversal of the binary
	//tree to which p points.
	//Postcondition: Nodes of the binary tree, to which p
	// points, are printed in preorder
	// sequence.
	void postorder(node<elemType> *p) const;
	//Function to do a postorder traversal of the binary
	//tree to which p points.
	//Postcondition: Nodes of the binary tree, to which p
	// points, are printed in postorder
	// sequence.
	int height(node<elemType> *p) const;
	//Function to determine the height of the binary tree
	//to which p points.
	//Postcondition: Height of the binary tree to which
	// p points is returned.
	int max(int x, int y) const;
	//Function to determine the larger of x and y.
	//Postcondition: Returns the larger of x and y.
	int nodeCount(node<elemType> *p) const;
	//Function to determine the number of nodes in
	//the binary tree to which p points.
	//Postcondition: The number of nodes in the binary
	// tree to which p points is returned.
	int leavesCount(node<elemType> *p) const;
	//Function to determine the number of leaves in
	//the binary tree to which p points.
	//Postcondition: The number of leaves in the binary
	// tree to which p points is returned.
};

template<class elemType>
bool binaryTreeType<elemType>::isEmpty()const {				//isEmpty METHOD
	return(root == NULL);
}//END IS EMPTY METHOD
template <class elemType>
binaryTreeType<elemType>::binaryTreeType() {
	root = NULL;
	count = 0;
}//END CONSTRUCTOR

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() const {	//inorderTraversal METHOD
	inorder(root);
}//END INORDER TRAVERSAL METHOD

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal()const {	//preorderTraversal METHOD
	preorder(root);
}//END PREORDER TRAVERSAL METHOD

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal()const {	//postorderTraversal METHOD
	postorder(root);
}//END POSTORDER TRAVERSAL METHOD

template<class elemType>
int binaryTreeType<elemType>::treeHeight()const {			//treeHeight METHOD
	height(root);
}//END TREE HEIGHT METHOD

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount()const {		//treeNodeCount METHOD
	return nodeCount(root);
}//END TREE NODE COUNT

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount()const {		//treeLeavesCount METHOD
	return leavesCount(root);
}//END TREE LEAVES COUNT

template <class elemType>
void binaryTreeType<elemType>::inorder(node<elemType> *p) const{//INORDER METHOD

	if (p != NULL) {											//IF TREE NONEMPTY
		inorder(p->lLink);										//PRINT IN INORDER
		cout << p->info << " ";
		inorder(p->rLink);
	}//END IF
}//END INORDER METHOD

template <class elemType>
void binaryTreeType<elemType>::preorder(node<elemType> *p) const{ //PREORDER METHOD

	if (p != NULL) {											//IF TREE NONEMPTY
		cout << p->info << " ";									//PRINT IN PREORDER
		preorder(p->lLink);
		preorder(p->rLink);
	}//END IF
}//END PREORDER METHOD
template <class elemType>
void binaryTreeType<elemType>::postorder(node<elemType> *p) const{//POSTORDER METHOD
	if (p != NULL) {											//IF TREE NONEMPTY
		postorder(p->lLink);									//PRINT IN POSTORDER
		postorder(p->rLink);
		cout << p->info << " ";
	}//END IF
}//END POSTORDER METHOD
template<class elemType>
int binaryTreeType<elemType>::height(node<elemType> *p) const	//HEIGHT METHOD
{
	if (p == NULL)												//IF TREE EMPTY
		return 0;												//RETURN 0
	else
		return 1 + max(height(p->lLink), height(p->rLink));		//RETURN HEIGHT OF TREE
}//END HEIGHT METHOD
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const{			//MAX METHOD

	if (x >= y)
		return x;
	else
		return y;
}
template <class elemType>
void binaryTreeType<elemType>::copyTree(node<elemType>* &copiedTreeRoot,node<elemType>* otherTreeRoot)	//copyTree METHOD
{
	if (otherTreeRoot == NULL)								//IF TREE ROOT EMPTY
		copiedTreeRoot = NULL;
	else {
		copiedTreeRoot = new node<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}//END ELSE
} //END COPY TREE METHOD
template <class elemType>
void binaryTreeType<elemType>::destroy(node<elemType>* &p){ //DESTROY METHOD
	if (p != NULL) {										//IF ROOT NONEMPTY
		destroy(p->lLink);									//DESTROY RIGHT LINK
		destroy(p->rLink);									//DESTROY LEFT LINK
		delete p;											//DELETE NODE
		p = NULL;				
	}//END IF
}//END DESTORY METHOD
template <class elemType>
void binaryTreeType<elemType>::destroyTree()				//DESTROY TREE METHOD
{
	destroy(root);
}
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree)	//binaryTreeType METHOD
{
	if (otherTree.root == NULL)								//IF otherTree IS EMPTY
		root = NULL;
	else
		copyTree(root, otherTree.root);						//ELSE COPY TREE
}//END CONSTRUCTOR

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType() {				//DESTRUCTOR METHOD
	destroy(root);
}//END DESTRUCTOR

template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree) {
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL)					//IF THE BINARY TREE IS NONEMPTY
			destroy(root);					//DESTROY THE BINARY TREE
			
			if (otherTree.root == NULL)		//IF otherTree IS EMPTY
				root = NULL;
			else
				copyTree(root, otherTree.root);
	}//END ELSE
	return *this;
}//END OPERATOR '=' OVERLOAD

template<class elemType>
int binaryTreeType<elemType>::nodeCount(node<elemType> *p) const {
	if (root == NULL)						//IF ROOT NULL
		return 0;							//THE TREE IS EMPTY AND CONTAINS NO NODES
	else {
		int count = 1;						//COUNT THE ROOT NODE
		count += nodeCount(root->lLink);	//ADD ALL LEFT NODES
		count += nodeCount(root->rLink);	//ADD ALL RIGHT NODES

		return count;						//RETURN TOTAL
	}//END ELSE
}//END NODE COUNT METHOD

template<class elemType>
int binaryTreeType<elemType>::leavesCount(node<elemType> *p) const {
	nodeCount(root);
}//END LEAF COUNT
void recFun(int x) {						//RECURSIVE FUNCTION
	if (x > 0) {
		cout << x % 10 << “ ” << recFun(x / 10);
	}//END IF
	else if (x != 0)
		cout << x << endl;

}//END RECRURSIVE FUNCTION

int main() {

	recFun(1234);							//TEST INPUT

	system("pause");
	return 0;
}//END MAIN