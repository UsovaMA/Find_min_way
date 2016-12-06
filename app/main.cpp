#include <iostream>
#include "FindMinWay.h"

int main() {  // проверка работоспособности logic_error
	try {
		int n = 0, m = 0;
		float** field = NULL;
		find_min_way(field, n, m);
	}
	catch (logic_error x) {
		x.what();
		system("pause");
	}
}