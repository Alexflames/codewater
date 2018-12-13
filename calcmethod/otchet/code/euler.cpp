// Функция задана вручную
void methodEuler(double from, double to, double step, int V) {
    int n = (int)((to - from) / step);
    // Значения x
    double * x = new double[n];
    double * yt = new double[n];
    double * ym = new double[n];
    double * e = new double[n];
    for (int i = 0; from < to + step / 2; from += step) {
        x[i] = from;
        if (i == 0) {
            yt[0] = ym[0] = x[0] * x[0] * x[0] + x[0] + 1;
            e[0] = 0;
            i++;
            continue;
        }
        yt[i] = V * x[i] * x[i] * x[i] + V * x[i] + V;
        ym[i] = V + step * (3 * V * x[i] * x[i] + V - V * x[i] * x[i] * x[i] - V - V * x[i]) + ym[i - 1];
        e[i] = abs(yt[i] - ym[i]);
        i++;
    }

    cout << "x = ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << i;
    }
    cout << endl << "y_t ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << yt[i];
    }
    cout << endl << "y_m ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << ym[i];
    }

    cout << endl << "e:  ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << e[i];
    }
}

methodEuler(1, 11, 1, 1);
