#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

class BST
{
	struct Node
	{
		int data;
		Node* left;
		Node* right;
		int height;
	};

	Node* root;

	void makeEmpty(Node* t)
	{
		if (t == NULL)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	Node* insert(int x, Node* t)
	{
		if (t == NULL)
		{
			t = new Node;
			t->data = x;
			t->height = 0;
			t->left = t->right = NULL;
		}
		else if (x < t->data)
		{
			t->left = insert(x, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (x < t->left->data)
					t = singleRightRotate(t);
				else
					t = doubleRightRotate(t);
			}
		}
		else if (x > t->data)
		{
			t->right = insert(x, t->right);
			if (height(t->right) - height(t->left) == 2)
			{
				if (x > t->right->data)
					t = singleLeftRotate(t);
				else
					t = doubleLeftRotate(t);
			}
		}

		t->height = max(height(t->left), height(t->right)) + 1;
		return t;
	}

	Node* singleRightRotate(Node* &t)
	{
		cout << endl << "Doing SRR at: " << t->data << endl;
		Node* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(u->left), t->height) + 1;
		return u;
	}

	Node* singleLeftRotate(Node* &t)
	{
		cout << endl << "Doing SLR ot: " << t->data << endl;
		Node* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(t->right), t->height) + 1;
		return u;
	}

	Node* doubleLeftRotate(Node* &t)
	{
		cout << endl << "Doing DLR ot: " << t->data << endl;
		t->right = singleRightRotate(t->right);
		return singleLeftRotate(t);
	}

	Node* doubleRightRotate(Node* &t)
	{
		cout << endl << "Doing DRR ot: " << t->data << endl;
		t->left = singleLeftRotate(t->left);
		return singleRightRotate(t);
	}

	Node* findMin(Node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	Node* findMax(Node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	Node* remove(int x, Node* t)
	{
		Node* temp;

		// Element not found
		if (t == NULL)
			return NULL;

		// Searching for element
		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);

		// Element found
		// With 2 children
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		// With one or zero child
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}
		if (t == NULL)
			return t;

		t->height = max(height(t->left), height(t->right)) + 1;

		// If Node is unbalanced
		// If left Node is deleted, right case
		if (height(t->right) - height(t->left) == 2)
		{
			// right right case
			if (height(t->right->right) - height(t->right->left) == 1)
				return singleLeftRotate(t);
			// right left case
			else
				return doubleLeftRotate(t);
		}
		// If right Node is deleted, left case
		else if (height(t->left) - height(t->right) == 2)
		{
			// left left case
			if (height(t->left->left) - height(t->left->right) == 1)
				return singleRightRotate(t);
			// left right case
			else
				return doubleRightRotate(t);
		}
		return t;
	}

	int height(Node* t)
	{
		return (t == NULL ? -1 : t->height);
	}

	int getBalance(Node* t)
	{
		if (t == NULL)
			return 0;
		else
			return height(t->left) - height(t->right);
	}

	// Обход узлов в отсортированном порядке
	void inorderTraversal(Node * x) {
		if (x != NULL) {
			inorderTraversal(x->left);
			cout << x->data << " ";
			inorderTraversal(x->right);
		}
	}

	// Обход узлов с приоритетом: вершина -> левое поддерево -> правое поддерево
	void preorderTraversal(Node * x) {
		if (x != NULL) {
			cout << x->data << " ";
			preorderTraversal(x->left);
			preorderTraversal(x->right);
		}
	}

	// Обход узлов с приоритетом: левое поддерево -> правое поддерево -> вершина  
	void postorderTraversal(Node * x) {
		if (x != NULL) {
			postorderTraversal(x->left);
			postorderTraversal(x->right);
			cout << x->data << " ";
		}
	}



public:
	BST()
	{
		root = NULL;
	}

	void insert(int x)
	{
		root = insert(x, root);
	}

	void remove(int x)
	{
		root = remove(x, root);
	}

	void print(Node * x) {
		cout << x->data << " ";
	}

	void display()
	{
		cout << endl << "Обход дерева в отсортированном порядке: " << endl;
		inorderTraversal(root);
		cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
		preorderTraversal(root);
		cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
		postorderTraversal(root);
		cout << endl;

	}

};

int main() {
	setlocale(LC_ALL, "russian");
	ofstream out("output.txt");
	time_t thistime = time(NULL);
	srand(time(&thistime));

#pragma region инициализация исходного массива
	int n;
	int switch_num;
	cout << "Enter 1 to input array manually (Default = 0 = auto)" << endl;
	cin >> switch_num;
	vector <int> input;
	cout << "Enter the number of elements in the tree" << endl;
	cin >> n;
	switch (switch_num)
	{
	case 1:
		cout << "Enter the array" << endl;
		for (int i = 0; i < n; i++) {
			int input_number;
			cin >> input_number;
			input.push_back(input_number);
		}
		break;
	default:
		for (int i = 0; i < n; i++) {
			int input_number = rand() % 100;
			input.push_back(input_number);
		}
		break;
	}
	
#pragma endregion

	//int startAlg = clock();	// Начало

	//int endAlg = clock();	// Конец
	//out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;

	BST * avlTree = new BST();
	cout << endl << "Исходный массив: " << endl;
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << " ";
		avlTree->insert(input[i]);
	}

	avlTree->display();

	cout << endl << "Введите число для вставки в дерево: ";
	int numToEnter; cin >> numToEnter; 
	avlTree->insert(numToEnter);

	avlTree->display();

	cout << endl << "Введите число для удаления из дерева (сначала найдём узел с данным ключом, потом удалим): ";
	int numToDelete; cin >> numToDelete;
	avlTree->remove(numToDelete);

	avlTree->display();

	system("pause");
	return 0;
}