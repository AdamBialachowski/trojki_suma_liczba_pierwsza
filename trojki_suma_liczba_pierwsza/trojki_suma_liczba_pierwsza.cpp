//Adam Białachowski

#include <iostream>
using namespace std;

/////deklaracje zmiennych i stałych globalnych
#define number 20	//ile liczb ma sprawdzić
int tab[1000][3];

/////deklaracje funkcji

void display_arrow(int t[][3], int s);
void three_numbers(int& size, int tab[][3]);
bool check_to_nuber_exist(int a, int b, int c, int s);
int prime_number(int how_meny);
void save_prime_number(int number_of_prime_numbers, int* all_prime_numb);
bool it_is_prime_number(int l);


int main()
{
	int size = 0; 


	cout << "Trojki z ktorych po dodaniu otrzymamy liczby pierwsze." << endl;
	
	three_numbers(size, tab);
	display_arrow(tab, size);	
}

//wyświetla głwną tablicę
void display_arrow(int t[][3], int s) {
	for (int i = 0; i< s; i++)
		cout <<"( "<<t[i][0] <<" , "<< t[i][1] << " , " << t[i][2] << " )" << "\n";
}
// szuka trojek liczb których suma jest liczbą pierwszą
void three_numbers(int &size, int tab[][3]) {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			for (int k = 0; k < number; k++) {
				if (it_is_prime_number(i + j + k)) {
					int l = i + j + k;
					//cout << "warunetk to " << check_to_nuber_exist(l, size)<<"\n";
					if (check_to_nuber_exist(i, j, k, size)) {
						tab[size][0] = i;
						tab[size][1] = j;
						tab[size][2] = k;
						size++;
					}

				}	
			}
		}
	}
}
//sprawdza czy nr jest w tablicy
bool check_to_nuber_exist(int a,int b, int c, int s) {
	for (int i = 0; i < s+1; i++) {
		if (a == tab[i][0] || b == tab[i][1] || c == tab[i][2]) {
			return false;
		}	
	}
	return true;
}
//sprawdza ilość liczb pierwszych
int prime_number(int how_meny) {
	int number_of_prime_numbers = 0;
	for (int i = 0; i < how_meny; i++) {
		if (it_is_prime_number(i))
			number_of_prime_numbers++;
	}
	return number_of_prime_numbers;
}
// zapisuje liczby pierwsze do tablicy
void save_prime_number(int number_of_prime_numbers, int* all_prime_numb) {
	int j = 0;
	for (int i = 0; i <= number_of_prime_numbers; i++) {
		cout << "i = " << i << '\n';
		if (it_is_prime_number(i)) {
			all_prime_numb[j] = i;
			cout << " pokazuje dla i = " << j << "  arr = " << all_prime_numb[j] << "\n";
			j++;
		}
	}
}
//sprawdza czy liczba jest pierwsza
bool it_is_prime_number(int l) {
	if (l <= 2)
		return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą
	else {
		for (int i = 2; i * i <= l; i++)
			if (l % i == 0)
				return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
		return true;
	}	
}



