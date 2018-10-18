#pragma once

std::pair<bool,int> isGenerated(int current, int timeNeed) {
	if (current != timeNeed)
		return std::make_pair(false, timeNeed);
	else
		return std::make_pair(true, std::rand() % 7 + 1);
}

// ��������� ����� �� 0 �� chance
int randomNumber(int chance) {
	return std::rand() % chance;
}

// �������� ������� �������, ���������� ���������� �������, ������� ������
// ������ �� ������������ �������. ���������� ���������� ����������� �������
// � ���������� �����, �������� �� ������� ��� ���������� �������
std::pair <int, int> howMuchTimesOccured(int chance, int time, int minimum) {
	int counter = 0;
	int tillNextEvent = randomNumber(chance) + minimum;
	while (time > 0) {
		time -= tillNextEvent;
		counter++;
		tillNextEvent = randomNumber(chance);
	}
	// � ���������� time ���� 0, ���� ������������� �����,
	// ������� ����� ������� ��� ��������� ������� ������������ �������
	return std::make_pair(counter, time * -1);
}