/*
for (int x = start_X; x <= end_X; x += 5) {
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

	cout << "S(" << x << ") = " << partSum << endl;
	cout << "n" << x << "= " << nslags << endl;
	cout << "diff with normal sin(x): " << partSum - sin(2 * x) << endl << endl;

	*/