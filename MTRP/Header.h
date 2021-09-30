#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> data_load(string name)
{
	vector<int> data;
	ifstream file;
	int bin_cap;
	file.open(name);
	while (!file.eof())
	{
		file >> bin_cap;
		data.push_back(bin_cap);
	}
	file.close();
	return data;
}

void reduction(vector<int> data, int items, int capacity, string path, string name)
{
	vector<int> nN, N, b;
	int z = 0, iter = 0;
	for (int i = 0; i < items; i++)
	{
		b.push_back(0);
		nN.push_back(-1);
		N.push_back(i);
	}
	while (iter <= items)
	{
		int j = -1, k = 0, c;
		vector<int> F;
		for (int i = items - 1; i >= 0; i--)
		{
			F.push_back(0);
			if (N[i] != -1 && data[i] <= capacity)
				j = i;
		}
		if (j != -1)
		{
			c = data[j];
			for (int i = items - 1; i >= 0; i--)
				if (c + data[i] <= capacity && N[i] != -1 && i != j)
				{
					k++;
					c = c + data[i];
				}
			if (k == 0)
				F[j] = 1;
			else
			{
				int js;
				for (int i = items - 1; i > j; i--)
					if (data[i] + data[j] <= capacity && N[i] != -1)
						js = i;
				if (k == 1 || data[j] + data[js] == capacity)
				{
					F[j] = 1;
					F[js] = 1;
				}
				else if (k == 2)
				{
					int a, b, es = capacity, range = items;
					for (int i1 = j + 1; i1 < items; i1++)
					{
						for (int i2 = i1 + 1; i2 < items; i2++)
						{
							if (N[i1] != -1 && N[i2] != -1 && capacity - data[i1] - data[i2] >= 0 && capacity - data[i1] - data[i2] <= es)
							{
								if ((capacity - data[i1] - data[i2] == es && i2 - i1 < range) || capacity - data[i1] - data[i2] < es)
								{
									es = capacity - data[i1] - data[i2];
									a = i1;
									b = i2;
									range = i2 - i1;
								}
							}
						}
					}
					if (data[js] >= data[a] + data[b])
					{
						F[j] = 1;
						F[js] = 1;
					}
					else if (data[js] == data[a] && (b - a <= 2 || data[j] + data[b - 1] + data[b - 2] > capacity))
					{
						F[j] = 1;
						F[a] = 1;
						F[b] = 1;
					}
				}
			}
			if (*max_element(F.begin(), F.end()) == 0)
				nN[j] = j;
			else
			{
				z++;
				for (int i = 0; i < items; i++)
					if (F[i] == 1)
					{
						b[i] = z;
						N[i] = -1;
					}
			}
		}
		iter++;
	}
	string fname = path + "Results\\" + "Results " + name + ".txt";
	string new_fname = path + "New data\\" + name + "_new.BPP";
	ofstream file(fname, ios_base::out);
	ofstream new_file(new_fname, ios_base::out);
	for (int i = 0; i < items; i++)
	{
		if (b[i] != 0)
			file << data[i] << " : " << b[i] << " bin" << endl;
		else
			new_file << data[i] << endl;
	}
	file.close();
	new_file.close();
}