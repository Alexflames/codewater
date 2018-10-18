#pragma once
#include "calculations.h"
#include <math.h>

double func(double x, double y)
{
	return cos(x)*cos(x) / ((y + 2) * (y + 2) - (x + 3) * (x + 3));
}
