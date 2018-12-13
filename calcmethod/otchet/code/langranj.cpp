vector <funValue> CalcLangranj(vector <funValue> * inputVector) {
	vector <funValue> result_middleInter;
	vector <funValue> input = *inputVector;

	// инициализация двумерного вектора - знаментали
	vector <vector <double> > denom_val;
	for (int i = 0; i < input.size(); i++)
	{
		vector <double> temp(input.size());
		denom_val.push_back(temp);
	}

	// подсчитываем все возможные скобки знаменателя
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (i == j) continue;
			denom_val[i][j] = input[i].x - input[j].x;
		}
	}

	// цикл по всем значениям желаемым 'x'
	for (int i = 0; i < input.size() - 1; i++)
	{
		// точка, которую собираемся вычислить
		funValue newPoint;
		newPoint.x = (input[i + 1].x + input[i].x) / 2;
		newPoint.f = 0;

		// подсчитываем всевозможные скобки числителя
		vector <double> num_val;
		for (int j = 0; j < input.size(); j++)
		{
			double temp = newPoint.x - input[j].x;
			num_val.push_back(temp);
		}

		// Суммируем слагаемые, из которых составляются интерполируемые точки
		for (int j = 0; j < input.size(); j++)
		{
			double num = 1;
			double denom = 1;
			for (int k = 0; k < input.size(); k++)
			{
				if (j == k) continue;
				num *= num_val[k];
				denom *= denom_val[j][k];
			}
			newPoint.f += input[j].f * num / denom;
		}
		result_middleInter.push_back(input[i]);
		result_middleInter.push_back(newPoint);
	}
	result_middleInter.push_back(input[input.size() - 1]);

	return result_middleInter;
}

void startInterpolation() {
    // все 'x' и 'f' из дано ТУТ
    vector <funValue> power3;
    funValue temp = { 1, 1 };
    power3.push_back(temp);
    temp = { 2, 8 };
    power3.push_back(temp);
    temp = { 3, 27 };
    power3.push_back(temp);
    temp = { 4, 64 };
    power3.push_back(temp);

    vector <funValue> result_middleInter = CalcLangranj(&power3);

    for (int i = 0; i < result_middleInter.size(); i++) {
        cout << "| " << setw(6) << setprecision(4) << result_middleInter[i].x << " ";
    }
    cout << endl;
    for (int i = 0; i < result_middleInter.size() * 9; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < result_middleInter.size(); i++) {
        cout << "| " << setw(6) << setprecision(4) << result_middleInter[i].f << " ";
    }
    cout << endl;
}