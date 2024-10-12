#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree() {}

const ptr RedBlackTree::getRoot() const
{
	return root;
}

ptr RedBlackTree::insert(int data)
{
	ptr newnodePtr = new node(data);
	if (!root)
	{
		root = newnodePtr;
		root->color = 0; // set root color as black
		return newnodePtr;
	}
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
	// choose direction
	if (newnodePtr == nullptr)
		return;
	else
	{
		newnodePtr->color = 1;// set color to red
		if (start->left == nullptr && start->right == nullptr)
		{
			if (newnodePtr->data > start->data)
			{
				start->right = newnodePtr;
			}
			else
			{
				start->left = newnodePtr;
			}
		}
		else if (start->right == nullptr)
		{
			if (newnodePtr->data > start->data)
			{
				start->right = newnodePtr;
			}
			else
				insert(start->left, newnodePtr);
		}
		else if (start->left == nullptr)
		{
			if (newnodePtr->data < start->data)
			{
				start->left = newnodePtr;
			}
			else
				insert(start->right, newnodePtr);
		}
		else
		{
			if (newnodePtr->data > start->data)
			{
				start->right = newnodePtr;
			}
			else
			{
				start->left = newnodePtr;
			}
		}
	}
	// recurse down the tree
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string &prefix, bool isLeftChild) const
{
	if (!start)
		return;

	std::cout << prefix;
	std::cout << (isLeftChild ? "|--" : "|__");
	// print the value of the node
	std::cout << start->data << "(" << start->color << ")" << std::endl;
	// enter the next tree level - left and right branch
	printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
	printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr loc)
{
	if (loc->right == nullptr)
	{
		ptr par = loc->parent;
		loc->right = loc->parent;
		par->parent = loc;
	}
	else
	{
		ptr par = loc->parent;
		par->left = loc->right;
		loc->right = par;
		par->parent = loc;
	}
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{
	if (loc->left == nullptr)
	{
		ptr par = loc->parent;
		loc->left = loc->parent;
		par->parent = loc;
	}
	else
	{
		ptr par = loc->parent;
		par->right = loc->left;
		loc->left = par;
		par->parent = loc;
	}
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{

	if((loc->parent)->color == 0) return;
	else if(((loc->parent)->parent)->right == loc->parent){
		if((((loc->parent)->parent)->left)->color == 1){
			(loc->parent)->color = 0;
			(((loc->parent)->parent)->color) = 1;
			(((loc->parent)->parent)->left)->color = 0;
			if((((loc->parent)->parent)->parent)->color == 0) return;
			else{
				if(((loc->parent)->parent)->parent == nullptr) ((loc->parent)->parent)->color = 0;
				else ((loc->parent)->parent);
			}
		}
		else{
			if((loc->parent)->left == loc){
				ptr main = (loc->parent)->parent;
				rightrotate(loc);
				main->right = loc;
				fixup(loc->right);
			}
			else{
				if(((loc->parent)->parent)->parent == nullptr){
					leftrotate(loc->parent);
					(loc->parent)->color = 0;
				}
				else{
					bool left;
					ptr main = ((loc->parent)->parent)->parent;
					if(main->left == (loc->parent)->parent ) left = true;
					leftrotate(loc->parent);
					(loc->parent)->color = 0;
					if(left) main->left = loc->parent;
					else main->right = loc->parent;
				}

			}
		}
	}
	else if(((loc->parent)->parent)->left == loc->parent){
		if((((loc->parent)->parent)->right)->color == 1){
			(loc->parent)->color = 0;
			(((loc->parent)->parent)->color) = 1;
			(((loc->parent)->parent)->right)->color = 0;
			if((((loc->parent)->parent)->parent)->color == 0) return;
			else{
				if(((loc->parent)->parent)->parent == nullptr) ((loc->parent)->parent)->color = 0;
				else ((loc->parent)->parent);
			}
		}
		else{
			if((loc->parent)->right == loc){
				ptr main = (loc->parent)->parent;
				leftrotate(loc);
				main->left = loc;
				fixup(loc->left);
			}
			else{
				if(((loc->parent)->parent)->parent == nullptr){
					rightrotate(loc->parent);
					(loc->parent)->color = 0;
				}
				else{
					bool right;
					ptr main = ((loc->parent)->parent)->parent;
					if(main->right == (loc->parent)->parent ) right = true;
					rightrotate(loc->parent);
					(loc->parent)->color = 0;
					if(right) main->right = loc->parent;
					else main->left = loc->parent;
				}

			}
		}
	}
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
	if (!start)
		return;

	inorder(start->left);
	std::cout << start->data << " ";
	inorder(start->right);
}

// driver code
int main()
{
	int n;
	std ::cin >> n;
	assert(n < 10000 && n >= 0);
	int a[10000];
	RedBlackTree tree;

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];

		// allocating memory to the node and initializing:
		// 1. color as red
		// 2. parent, left and right pointers as NULL
		// 3. data as i-th value in the array

		// calling function that performs rbt insertion of
		// this newly created node
		auto newnodePtr = tree.insert(a[i]);

		// calling function to preserve properties of rb
		// tree
		tree.fixup(newnodePtr);
	}
	tree.printRBT(tree.getRoot());

	return 0;
}
