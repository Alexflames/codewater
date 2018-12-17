vector <funValue> CalcSinPartSums(int start, int end, int step) {
	vector <funValue> ans;

	for (int x = start; x <= end; x += step) {
		int sign = 1;
		int factNext = 1;
		double factDenominator = 1;
		double chisl_start = 2 * x;
		double chisl = chisl_start;
		double partSum = 2 * x;

		double prevSum = 0;
		int nslags = 0;
		double diff;

		cout << "x = " << x << endl;

		while (nslags == 0 || abs(diff) > 10e-9) {
			prevSum = partSum;

			nslags++;
			// Вычисляем факториал в знаменателе
			factNext++;
			factDenominator *= factNext;
			factNext++;
			factDenominator *= factNext;
			// Вычисляем числитель
			chisl *= chisl_start;
			chisl *= chisl_start;
			// Вычисляем частичную сумму
			sign *= -1;
			partSum += sign * (chisl / factDenominator);

			diff = partSum - prevSum;
		}

		funValue thisStep; thisStep.x = x; thisStep.f = partSum;
		ans.push_back(thisStep);
	}
	return ans;
}
//
// Вычислить сумму ряда функции 
// для x от -30 до 30 с шагом 5
//
// Ответ представляется в виде массива
// пар: x и функция в точке x
//
vector <funValue> part_sums = (*CalcSinPartSums(-30, 30, 5))
