#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Adresses
{
public:

	std::string read_to_file(int N, std::ifstream& fin)
	{

		fin >> Adresses::city;
		fin >> Adresses::street;
		fin >> Adresses::num_house;
		fin >> Adresses::num_kv;

		string num_house1 = to_string(num_house);
		string num_kv1 = to_string(num_kv);

		string adres = city + ", " + street + ", " + num_house1 + ", " + num_kv1;

		return adres;
	}

	void write_to_file(int N, std::ofstream& fout, string arr)
	{

		for (int j = N - 1; j >= 0; j--) {

			fout << arr[j] << std::endl;
		}


	}

	string* create_array(int rows) {

		string* arr = new string [rows]();

		return arr;
	}

	void sort(string arr)
	{
		

		for (int i = 0; i < arr.length(); i++)
			for (int j = i; j < arr.length(); j++)
				if (arr[i] > arr[j])
				{
					auto buf = arr[i];
					arr[i] = arr[j];
					arr[j] = buf;
				}
		
	};

	int setter(int N) {

		if (N > 0) {
			this -> N = N;
			return N;

		}
		else {
			std::cout << "Размерность некоректна!";
			return -1;

		}

	}


private:

	int N = 0;
	std::string city = "Неизвестно";
	std::string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;

};


int main()
{
	Adresses adres;

	int N;

	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");

	if (fin.is_open() && fout.is_open()) {

		fin >> N;
		fout << N << std::endl;
		std::string adress;
		N = adres.setter(N);

		string* arr = adres.create_array(N);
		
		

		for (int i = 0; i < N; i++)
		{
			adress = adres.read_to_file(N, fin);
			arr[i] = adress;

		}

		adres.sort(*arr);

		//adres.write_to_file(N, fout, *arr);

		for (int j = N - 1; j >= 0; j--) { fout << arr[j] << std::endl; }

		delete[] arr;

	}

	fin.close();
	fout.close();

	return 0;

}