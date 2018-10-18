#include "ClassList.h"

void MyList::push(MySet * x)
{
	node * r =  new node;
	r->inf = x;
	r->next = NULL;
	if (!head && !tail) {
		r->prev = NULL;
		head = r;
	}
	else {
		tail->next = r;
		r->prev = tail;
	}
	tail = r;
}

void MyList::print()
{
	node *r = head;
	int cnt = 1;
	while (r != NULL) {
		cout << "Множество № " << cnt << ": ";
		r->inf->printElements();
		r = r->next;
		cnt++;
	}
}

void MyList::deleteThisNode(node * x)
{
	if (x == NULL)
		return;
	if (x == head) {
		head = x->next;
	}
	else if (x == tail) {
		tail = x->prev;
	}
	else {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}
	delete x;
}

node * MyList::operator [](int i)
{
	node * r = head;
	while (i > 1) {
		r = r->next;
		if (r == NULL)
			return NULL;
		i--;
	}
	return r;
}

