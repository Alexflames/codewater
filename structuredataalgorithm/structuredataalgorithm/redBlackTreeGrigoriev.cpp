#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

enum NodeColor	// цвет узла (Черный, красный)
{
	BLACK,
	RED
};

struct Node {
	Node * left;
	Node * right;
	Node * parent;
	NodeColor color = BLACK;
	int data = 0;
};

// определим как NIL листья дерева, являющиеся черными
#define NIL &sentinel
Node sentinel = { NIL, NIL, 0, BLACK, 0 };

Node * root = NIL;               /* корень дерева описан как глобальная переменная */

// функция, используемая при балансировке - поворот влево
void rotateLeft(Node *x) {

	/*************************
	*  поворот узла x влево  *
	*************************/

	Node *y = x->right;

	/* устанавливаем связь с x->right */
	x->right = y->left;
	if (y->left != NIL) y->left->parent = x;

	/* устанавливаем связь с y->parent */
	if (y != NIL) y->parent = x->parent;
	if (x->parent) {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else {
		root = y;
	}

	/* связываем x и y */
	y->left = x;
	if (x != NIL) x->parent = y;
}

// функция, используемая при балансировке - поворот вправо
void rotateRight(Node *x) {

	/*************************
	*  поворот узла x вправо *
	*************************/

	Node *y = x->left;

	/* устанавливаем связь с x->left  */
	x->left = y->right;
	if (y->right != NIL) y->right->parent = x;

	/* устанавливаем связь с y->parent  */
	if (y != NIL) y->parent = x->parent;
	if (x->parent) {
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	else {
		root = y;
	}

	/* связываем x и y */
	y->right = x;
	if (x != NIL) x->parent = y;
}

// балансировка дерева после вставки элемента
void insertFixup(Node *x) {
	/* проверка свойств Red-Black */
	while (x != root && x->parent->color == RED) {
		/* условие while выполнилось - нарушилось свойство дерева */
		if (x->parent == x->parent->parent->left) {
			Node *y = x->parent->parent->right;
			if (y->color == RED) {

				/* uncle is RED */
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else {

				/* uncle is BLACK */
				if (x == x->parent->right) {
					/* make x a left child */
					x = x->parent;
					rotateLeft(x);
				}

				/* recolor and rotate */
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				rotateRight(x->parent->parent);
			}
		}
		else {

			/* копия кода выше */
			Node *y = x->parent->parent->left;
			if (y->color == RED) {

				/* uncle is RED */
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else {

				/* uncle is BLACK */
				if (x == x->parent->left) {
					x = x->parent;
					rotateRight(x);
				}
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				rotateLeft(x->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

// вставка элемента в дерево
Node *insertNode(int data) {
	Node *current, *parent, *x = new Node;

	current = root;
	parent = 0;
	while (current != NIL) {
		if (data == current->data) return (current);
		parent = current;
		current = data < current->data ?
			current->left : current->right;
	}

	/* setup new Node */
	x->data = data;
	x->parent = parent;
	x->left = NIL;
	x->right = NIL;
	x->color = RED;

	/* insert Node in tree */
	if (parent) {
		if (data < parent->data)
			parent->left = x;
		else
			parent->right = x;
	}
	else {
		root = x;
	}

	insertFixup(x);
	return(x);
}

// балансировка дерева после удаления узла
void deleteFixup(Node *x) {

	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			Node *w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rotateLeft(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rotateRight(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rotateLeft(x->parent);
				x = root;
			}
		}
		else {
			Node *w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rotateRight(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					rotateLeft(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rotateRight(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

// удаление узла
void deleteNode(Node *z) {
	Node *x, *y;

	if (!z || z == NIL) return;


	if (z->left == NIL || z->right == NIL) {
		/* y имеет лист */
		y = z;
	}
	else {
		/* находим предка, у которого дитя - лист */
		y = z->right;
		while (y->left != NIL) y = y->left;
	}

	/* x единственный ребенок y */
	if (y->left != NIL)
		x = y->left;
	else
		x = y->right;

	/* удалим y из ветви родителя */
	x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	else
		root = x;

	if (y != z) z->data = y->data;


	if (y->color == BLACK)
		deleteFixup(x);
}

Node *findNode(int data) {

	Node *current = root;
	while (current != NIL)
		if (data == current->data)
			return (current);
		else
			current = data < current->data ?
			current->left : current->right;
	return(0);
}

void print(Node * x) {
	cout << x->data << " ";
}

// Обход узлов в отсортированном порядке
void inorderTraversal(Node * x, void (*f) (Node *)){
	if (x != NIL) {
		inorderTraversal(x->left, f);
		f(x);
		inorderTraversal(x->right, f);
	}
}

// Обход узлов с приоритетом: вершина -> левое поддерево -> правое поддерево
void preorderTraversal(Node * x, void(*f) (Node *)) {
	if (x != NIL) {
		f(x);
		preorderTraversal(x->left, f);
		preorderTraversal(x->right, f);
	}
}

// Обход узлов с приоритетом: левое поддерево -> правое поддерево -> вершина  
void postorderTraversal(Node * x, void(*f) (Node *)) {
	if (x != NIL) {
		postorderTraversal(x->left, f);
		postorderTraversal(x->right, f);
		f(x);
	}
}

/*
// Вспомогательная функция для функции поиска следующего элемента
Node * minimum(Node * x) {
	if (x->left == NULL)
		return x;
	return minimum(x->left);
}

// Вспомогательная функция для функции удаления элемента - поиск следующего
Node * next(Node * Node) {
	auto x = Node;
	if (x->right != NULL)
		return minimum(x->right);
	auto y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}


void deleteNode(Node * t , Node * toDel) {                 // t — дерево, toDel — удаляемый элемент
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
		toDel->data = successor->data;
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
*/

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

	cout << endl << "Исходный массив: " << endl;
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << " ";
		insertNode(input[i]);
	}

	cout << endl << "Обход дерева в отсортированном порядке: " << endl;
	inorderTraversal(root, print);
	cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
	preorderTraversal(root, print);
	cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
	postorderTraversal(root, print);

	cout << endl << "Введите число для вставки в дерево: ";
	int numToEnter; cin >> numToEnter; 
	insertNode(numToEnter);

	cout << endl << "Обход дерева в отсортированном порядке: " << endl;
	inorderTraversal(root, print);
	cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
	preorderTraversal(root, print);
	cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
	postorderTraversal(root, print);

	cout << endl << "Введите число для удаления из дерева (сначала найдём узел с данным ключом, потом удалим): ";
	int numToDelete; cin >> numToDelete;
	auto NodeToDelete = findNode(numToDelete);
	deleteNode(NodeToDelete);

	cout << endl << "Обход дерева в отсортированном порядке: " << endl;
	inorderTraversal(root, print);
	cout << endl << "Обход дерева узел - левое - правое поддерево: " << endl;
	preorderTraversal(root, print);
	cout << endl << "Обход дерева левое - правое поддерево - узел: " << endl;
	postorderTraversal(root, print);

	system("pause");
	return 0;
}