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
			// ��������� ��������� � �����������
			factNext++;
			factDenominator *= factNext;
			factNext++;
			factDenominator *= factNext;
			// ��������� ���������
			chisl *= chisl_start;
			chisl *= chisl_start;
			// ��������� ��������� �����
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
// ��������� ����� ���� ������� 
// ��� x �� -30 �� 30 � ����� 5
//
// ����� �������������� � ���� �������
// ���: x � ������� � ����� x
//
vector <funValue> part_sums = (*CalcSinPartSums(-30, 30, 5))
