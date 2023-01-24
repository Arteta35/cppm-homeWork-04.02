#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


class Adresses
{
public:

	void in_city(string city) {
		this->city = city;
	}

	void in_street(string street) {
		this->street = street;
	}

	void in_num_house(int num_house) {
		this->num_house = num_house;
	}

	void in_num_kv(int num_kv) {
		this->num_kv = num_kv;
	}

	string get_output() {
		return city + ", " + street + ", " + to_string(num_house) + ", " + to_string(num_kv);
	}



private:

	string city = "Неизвестно";
	string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;

};

string city2(Adresses* arr, int i) {

	string a = arr[i].get_output();
	auto del = a.find(",");
	int del1 = static_cast<int>(del);

	string city1 = a.substr(0, del1);

	return city1;

};

void sort(Adresses* arr, int N)
{
	bool flag = false;
	do
	{
		
		flag = false;

		for (int i = 0; i < N - 1; i++) {

			string a = city2(arr, i);
			string b = city2(arr, i + 1);

			auto len1 = a.length();
			auto len2 = b.length();

			int len11 = static_cast<int>(len1);
			int len22 = static_cast<int>(len2);

			if (a[0] > b[0]) {
				Adresses buf = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buf;
				flag = true;

			}
			if (a[0] == b[0]) {

				if (len11 >= len22) {

					for (int j = 0; j < len11 - 1; j++) {
						if (a[j] > b[j])
						{
							Adresses buf = arr[i];
							arr[i] = arr[i + 1];
							arr[i + 1] = buf;
							break;
						}
					}

				}
				else {
					for (int j = 0; j < len22 - 1; j++) {
						if (a[j] > b[j])
						{
							Adresses buf = arr[i];
							arr[i] = arr[i + 1];
							arr[i + 1] = buf;
							break;
						}
					}

				}

			}

		}
	} while (flag);
};




int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	string city = "Неизвестно";
	string street = "Неизвестно";
	int num_house = 0;
	int num_kv;

	ifstream fin("in.txt");
	ofstream fout("out.txt");

	if (fin.is_open() && fout.is_open()) {

		fin >> N;
		if (N > 0) {
			N = N;
		}
		else {
			cout << "Размерность некоректна!";
			return -1;

		}
		fout << N << std::endl;
		Adresses* arr = new Adresses[N]();

		for (int i = 0; i < N; i++)
		{
			fin >> city;
			arr[i].in_city(city);
			fin >> street;
			arr[i].in_street(street);
			fin >> num_house;
			arr[i].in_num_house(num_house);
			fin >> num_kv;
			arr[i].in_num_kv(num_kv);

		}
		
		sort(arr, N);

		for (int j = 0; j < N; j++) { fout << arr[j].get_output() << std::endl; }

		delete[] arr;

	}

	fin.close();
	fout.close();

	return 0;

}