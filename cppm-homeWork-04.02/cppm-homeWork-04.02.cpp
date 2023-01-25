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

	string out_city() {
		return city;
	}



private:

	string city = "Неизвестно";
	string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;

};

void sort(Adresses* arr, int N)
{
	bool flag = false;
	do
	{
		flag = false;

		for (int i = 0; i < N - 1; i++) {

			int res = arr[i].out_city().compare(arr[i + 1].out_city());

			if (res == 0) {
				continue;
			} if (res < 0) {
				Adresses buf = arr[i + 1];
				arr[i+1] = arr[i];
				arr[i] = buf;
				flag = true;
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
		if (N <= 0) {
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

		for (int j = N-1; j >= 0; j--) { fout << arr[j].get_output() << std::endl; }

		delete[] arr;

	}

	fin.close();
	fout.close();

	return 0;

}