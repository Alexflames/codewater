#include "Seller.h"

ShopQueue * Seller::getQueue()
{
	return guestsQueue;
}

Seller::Seller() : Person()
{
	guestsQueue = new ShopQueue();
}

Seller::~Seller()
{
}
