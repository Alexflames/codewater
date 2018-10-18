#include "ShopQueue.h"

void ShopQueue::push(Guest * x)
{
	peopleCount++;	// Увеличиваем количество людей в очереди
	qnode * r = new qnode;
	r->inf = x;
	r->prev = NULL;
	if (!head) {
		head = r;
	}
	if (tail) {
		tail->prev = r;
	}
	tail = r;
}

Guest * ShopQueue::pop()
{
	if (peopleCount == 0)
		return NULL;
	Guest* toReturn = head->inf;
	qnode* temp = head->prev;
	head = temp;
	peopleCount--; // Уменьшаем количество людей в очереди
	return toReturn;
}


//void ShopQueue::deleteThisNode(qnode * x)
//{
//	if (x == NULL)
//		return;
//	if (x == head) {
//		head = x->next;
//		head->prev = NULL;
//	}
//	else if (x == tail) {
//		tail = x->prev;
//		tail->next = NULL;
//	}
//	else {
//		x->prev->next = x->next;
//		x->next->prev = x->prev;
//	}
//	delete x;
//}

Guest * ShopQueue::front()
{
	return head->inf;
}

bool ShopQueue::isAnyHead()
{
	return head;
}

int ShopQueue::getCount()
{
	return peopleCount;
}

