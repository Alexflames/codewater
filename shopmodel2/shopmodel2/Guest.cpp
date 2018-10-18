#include "Guest.h"

Guest::Guest(int fromMoney, int toMoney) : Person()
{
	Guest::setRandomStartingMoney(fromMoney, toMoney);
	Guest::setConsultNeed();
}

int Guest::getMoney()
{
	return money;
}

bool Guest::isConsulted()
{
	return consulted;
}

void Guest::justConsulted()
{
	consulted = true;
}

Guest::~Guest()
{
}

void Guest::setConsultNeed()
{
	if (rand() % 2 == 0)
		consulted = true;
	else
		consulted = false;
}

// ������������� ��������� ������� (�� 30 �� 9000 ����������)
void Guest::setRandomStartingMoney(int fromMoney, int toMoney)
{
	money = std::rand() % (toMoney - fromMoney) + fromMoney;
}
