vector <funValue> CalcNewton(vector <funValue> * inputVector) {
	vector <funValue> result_middleInter;
	vector <funValue> input = *inputVector;

	// инициализация массива разделенных разностей
	vector <vector <double>> divDiff;

	for (int i = 0; i < input.size(); i++) {
		vector <double> temp;
		divDiff.push_back(temp);
	}

	// разделенные разности нулевого порядка
	for (int i = 0; i < input.size(); i++) {
		divDiff[0].push_back(input[i].f);
	}

	// разделенные разности других порядков
	for (int i = 1; i < input.size(); i++) {
		for (int j = 0; j < input.size() - i; j++) {
			double calcThisDiv = (divDiff[i - 1][j + 1] - divDiff[i - 1][j]) / (input[j + i].x - input[j].x);
			divDiff[i].push_back(calcThisDiv);
		}
	}

	// Нахождение значение функции в срединных точках
	for (int i = 0; i < input.size() - 1; i++) {
		funValue newPoint; newPoint.x = (input[i + 1].x + input[i].x) / 2;

		// нахождение множителей вида (x - x0), (x - x1), ...
		vector <double> xdifx;
		xdifx.push_back(newPoint.x - input[0].x);

		for (int j = 1; j < input.size() - 1; j++) {
			xdifx.push_back(xdifx[j - 1] * (newPoint.x - input[j].x));
		}

		// подсчет значения функции в данной неузловой точке
		newPoint.f = 0;
		newPoint.f += divDiff[0][0];
		for (int j = 1; j < input.size(); j++) {
			newPoint.f += divDiff[j][0] * xdifx[j - 1];
		}
		result_middleInter.push_back(newPoint);
	}
	
	return result_middleInter;
}

void startInterpolation() {
    // все 'x' и 'f' из дано “”“
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