#include "ClassList.h"

void MyList::push(Seller * x)
{
	node * r = new node;
	r->inf = x;
	r->next = NULL;

	if (!head && !tail)
	{
		r->prev = NULL;
		head = r;
	}
	else
	{
		tail->next = r;
		r->prev = tail;
	}
	tail = r;
}

Seller * MyList::front()
{
	return head->inf;
}

// Функция возвращает кассу / продавца в списке (первого), который наименее занят.
// Применима только к списку продавцов!
Seller * MyList::chooseLeastBusy()
{
	node* r = head;
	int minCnt = 3000; // Случайно выбранная величина, заведомо больше максимальной

	Seller * ans;
	while (r != NULL) {
		Seller * thisSeller = r->inf;
		ShopQueue * thisQueue = thisSeller->getQueue();
		int thisNumberOfPeople = thisQueue->getCount();
		if (thisNumberOfPeople < minCnt) {
			minCnt = thisNumberOfPeople;
			ans = thisSeller;
		}
		r = r->next;
	}
	return ans;
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

