/*
 * 大一寫的 ><  可i
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x[4];
	double y[4];
	while (cin >> x[0] >> y[0])
	{
		for (int i = 1; i < 4; ++i)
			cin >> x[i] >> y[i];
		if (x[0] == x[2] && y[0] == y[2])
			cout << fixed << setprecision(3) << x[1] + x[3] - x[0] << " " << y[1] + y[3] - y[0] << endl;
		else if (x[0] == x[3] && y[0] == y[3])
			cout << fixed << setprecision(3) << x[1] + x[2] - x[0] << " " << y[1] + y[2] - y[0] << endl;
		else if (x[1] == x[2] && y[1] == y[2])
			cout << fixed << setprecision(3) << x[0] + x[3] - x[1] << " " << y[0] + y[3] - y[1] << endl;
		else
			cout << fixed << setprecision(3) << x[0] + x[2] - x[1] << " " << y[0] + y[2] - y[1] << endl;
	}
	// system("pause");     VS 可愛殘留物
}
