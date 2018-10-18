#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct binNode {	// Реализация используя информацию о родителе
	int value;
	binNode * left = NULL;
	binNode * right = NULL;
	binNode * parent = NULL;
};

void binInsert(binNode * x, binNode * toIns) {
	auto root = x;
	while (root != NULL) {
		if (toIns->value >= root->value) {
			if (root->right != NULL) {
				root = root->right;
			}
			else {
				toIns->parent = root;
				root->right = toIns;
				break;
			}
		}
		else {
			if (root->left != NULL) {
				root = root->left;
			}
			else {
				toIns->parent = root;
				root->left = toIns;
				break;
			}
		}
	}
}

void print(binNode * x) {
	cout << x->value << " ";
}

// Обход узлов в отсортированном порядке
void inorderTraversal(binNode * x, void (*f) (binNode *)){
	if (x != NULL) {
		inorderTraversal(x->left, f);
		f(x);
		inorderTraversal(x->right, f);
	}
}

// Обход узлов с приоритетом: вершина -> левое поддерево -> правое поддерево
void preorderTraversal(binNode * x, void(*f) (binNode *)) {
	if (x != NULL) {
		f(x);
		preorderTraversal(x->left, f);
		preorderTraversal(x->right, f);
	}
}

// Обход узлов с приоритетом: левое поддерево -> правое поддерево -> вершина  
void postorderTraversal(binNode * x, void(*f) (binNode *)) {
	if (x != NULL) {
		postorderTraversal(x->left, f);
		postorderTraversal(x->right, f);
		f(x);
	}
}

binNode * search(binNode * x, int value) {
	if (x == NULL || value == x->value) {
		return x;
	}
	if (value < x->value)
		return search(x->left, value);
	else
		return search(x->right, value);
}

// Вспомогательная функция для функции поиска следующего элемента
binNode * minimum(binNode * x) {
	if (x->left == NULL)
		return x;
	return minimum(x->left);
}

// Вспомогательная функция для функции удаления элемента - поиск следующего
binNode * next(binNode * node) {
	auto x = node;
	if (x->right != NULL)
		return minimum(x->right);
	auto y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

void deleteNode(binNode * t , binNode * toDel) {                 // t — дерево, toDel — удаляемый элемент
	auto par = toDel->parent;                                  // предок удаляемого элемента
	if (toDel->left == NULL && toDel->right == NULL) {         // первый случай: удаляемый элемент - лист
		if (par->left == toDel)
			par->left = NULL;
		if (par->right == toDel)
			par->right = NULL;
	}
	else if (toDel->left == NULL || toDel->right == NULL) {     // второй случай: удаляемый элемент имеет одного потомка
		if (toDel->left == NULL) {
			if (par->left == toDel)
				par->left = toDel->right;
			else
				par->right = toDel->right;
			toDel->right->parent = par;
		}
		else {
			if (par->left == toDel)
				par->left = toDel->left;
			else
				par->right = toDel->left;
			toDel->left->parent = par;
		}
	}
	else {                                          // третий случай: удаляемый элемент имеет двух потомков
		auto successor = next(toDel);					// преемник
		toDel->value = successor->value;
		if (successor->parent->left == successor) {
			successor->parent->left = successor->right;
			if (successor->right != NULL)
				successor->right->parent = successor->parent;
		}
		else {
			successor->parent->right = successor->right;
			if (successor->right != NULL)
				successor->right->parent = successor->parent;
		}
	}
}

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
			int input_number = rand() % 20;
			input.push_back(input_number);
		}
		break;
	}
	
#pragma endregion

	//int startAlg = clock();	// Начало

	//int endAlg = clock();	// Конец
	//out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;

	cout << endl << "Исходный массив: " << endl;
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << " ";
	}

	binNode * root = new binNode; 
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			root->value = input[i];
		}
		else {
			binNode * node = new binNode; 
			node->value = input[i];
			binInsert(root, node);
		}
	}
	cout << endl << "Обход дерева в отсортированном порядке: " << endl;
	inorderTraversal(root, print);
	cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
	preorderTraversal(root, print);
	cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
	postorderTraversal(root, print);

	cout << endl << "Введите число для вставки в дерево: ";
	int numToEnter; cin >> numToEnter; 
	auto nodeToInsert = new binNode; nodeToInsert->value = numToEnter;
	binInsert(root, nodeToInsert);

	cout << endl << "Обход дерева в отсортированном порядке: " << endl;
	inorderTraversal(root, print);
	cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
	preorderTraversal(root, print);
	cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
	postorderTraversal(root, print);

	cout << endl << "Введите число для удаления из дерева (сначала найдём узел с данным ключом, потом удалим): ";
	int numToDelete; cin >> numToDelete;
	auto nodeToDelete = search(root, numToDelete);
	deleteNode(root, nodeToDelete);

	cout << endl << "Обход дерева в отсортированном порядке: " << endl;
	inorderTraversal(root, print);
	cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
	preorderTraversal(root, print);
	cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
	postorderTraversal(root, print);

	system("pause");
	return 0;
}