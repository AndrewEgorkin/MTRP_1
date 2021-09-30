#include "Header.h"
using namespace std;

int main()
{
	string name, path = "C:\\Tests\\bin1data\\";
	int x, y, z;
	vector<int> data;
	cout << "Enter test params:" << endl << "x - number of items (x = 1 - 50 items, x = 2 - 100 items, x = 3 - 200 items, x = 4 - 500 items)" << endl;
	do
	{
		cout << "x = ";
		cin >> x;
		if (x != 1 && x != 2 && x != 3 && x != 4)
			cout << "Please, enter number again (1, 2, 3 or 4)" << endl;
	} while (x != 1 && x != 2 && x != 3 && x != 4);
	cout << "y - bin capacity (y = 1 - 100, y = 2 - 120, y = 3 - 130)" << endl;
	do
	{
		cout << "y = ";
		cin >> y;
		if (y != 1 && y != 2 && y != 3)
			cout << "Please, enter number again (1, 2 or 3)" << endl;
	} while (y != 1 && y != 2 && y != 3);
	cout << "z - weight of item (z = 1 - [10, 100], z = 2 - [20, 100], z = 4 - [30, 100])" << endl;
	do
	{
		cout << "z = ";
		cin >> z;
		if (z != 1 && z != 2 && z != 4)
			cout << "Please, enter number again (1, 2 or 4)" << endl;
	} while (z != 1 && z != 2 && z != 4);
	name = "NxCyWz_v.BPP";
	name[1] = char(x + 48);
	name[3] = char(y + 48);
	name[5] = char(z + 48);
	int items, capacity;
	switch (x)
	{
	case(1): {items = 50; break; }
	case(2): {items = 100; break; }
	case(3): {items = 200; break; }
	case(4): {items = 500; break; }
	}
	switch (y)
	{
	case(1): {capacity = 100; break; }
	case(2): {capacity = 120; break; }
	case(3): {capacity = 130; break; }
	}
	for (int v = 65; v < 85; v++)
	{
		name[7] = char(v);
		string newname = path + name;
		data = data_load(newname);
		data.erase(data.begin());
		data.erase(data.begin());
		sort(data.begin(), data.end());
		reverse(data.begin(), data.end());
		reduction(data, items, capacity, path, name);
	}
	return 0;
}