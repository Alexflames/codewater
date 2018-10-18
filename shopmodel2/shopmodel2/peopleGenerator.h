#pragma once

std::pair<bool,int> isGenerated(int current, int timeNeed) {
	if (current != timeNeed)
		return std::make_pair(false, timeNeed);
	else
		return std::make_pair(true, std::rand() % 7 + 1);
}

// —лучайное число от 0 до chance
int randomNumber(int chance) {
	return std::rand() % chance;
}

// ¬ызывает функцию рандома, возврающую количество времени, которое должно
// пройти до срабатывани€ событи€. ¬озвращает количество сработавших событий
// и оставшеес€ врем€, которого не хватило дл€ следующего событи€
std::pair <int, int> howMuchTimesOccured(int chance, int time, int minimum) {
	int counter = 0;
	int tillNextEvent = randomNumber(chance) + minimum;
	while (time > 0) {
		time -= tillNextEvent;
		counter++;
		tillNextEvent = randomNumber(chance);
	}
	// ¬ результате time либо 0, либо отрицательное число,
	//  оторое будет вычтено при следующем запуске срабатываний рандома
	return std::make_pair(counter, time * -1);
}