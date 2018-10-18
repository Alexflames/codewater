#include "ClassList.h"

void MyList::push(Prey * x)
{
	node * r = new node;
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
	cout << endl << "(Т) - травоядная, (П) - плотоядная, (Г) - глубоководная" << endl;
	node *r = head;
	int cnt = 0;
	while (r != NULL) {
		Prey * obj = r->inf;
		cout << cnt << ": " << obj->getName() << ", "
			<< obj->getFoodType() << " размера " << obj->getSize();
		if (obj->getFoodType() == "fish") {
			cout << ". Настроение рыбы: " << obj->getCondition() << ". Голод: " << obj->getHungerLevel();
		}
		cout << endl;
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
		head->prev = NULL;
	}
	else if (x == tail) {
		tail = x->prev;
		tail->next = NULL;
	}
	else {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}
	delete x;
}
void MyList::clean()
{
	cout << endl;
	node *r = head;
	while (r != NULL) {
		Prey * obj = r->inf;
		if (obj->ifEaten()) {
			deleteThisNode(r);
			break;
		}
		r = r->next;
	}
}
Prey * MyList::front()
{
	return head->inf;
}

node * MyList::operator [](int i)
{
	node * r = head;
	try
	{
		int saveNum = i;
		while (i >= 1) {
			r = r->next;
			if (r == NULL)
				throw Noobj(saveNum);
			i--;
		}
	}
	catch (Err& e)
	{
		e.print();

	}
	return r;
}

