#include <iostream>
#include <math.h>
using namespace std;

void kalkulator();
void czy_zlozona(int a);
void Temperatura(int a);

int main() {
  // Zad 1
  int a, b;
  cout << "Podaj wartości a i b: ";
  cin >> a;
  cin >> b;
  if (a == b)
    cout << "a = b";
  else {
    if (a > b)
      cout << "a>b";
    else
      cout << "a<b";
  }
  cout << endl;

  // Zad 2
  // A już domyślnie tak zrobiłem

  // Zad 3
  float r;
  cout << "Podaj współczynnik korelacji r: ";
  cin >> r;

  if (0.7 <= r && r <= 1)
    cout << "Bardzo silna korelacja dodatnia";
  else if (r >= 0.5)
    cout << "Korelacja silnie dodatnia";
  else if (r >= 0.3)
    cout << "Umiarkowana korelacja dodatnia";
  else if (r >= 0.2)
    cout << "Słaba korelacja dodatnia";
  else if (r >= 0.0)
    cout << "Brak korelacji";
  cout << endl;

  // Zad 4
  kalkulator();

  // Zad 5 Pętla pokazana na ekranie będzie nieskończona gdyż nie ma warunku
  // stop nieskończona while to while(1), while(true), de facto wsztstko co nie
  // jest false albo 0
  /*
  while(1){ cout<<"BOEING BOEING"<<endl} //Przykłąd irytującej pętli
  */

  // Zad 6
  bool czy_chce = 1;
  char buff;
  while (czy_chce) {
    kalkulator();
    cout << "Kontynuować? (Y/N)";
    cin >> buff;
    if (buff != 'Y')
      czy_chce = 0;
  }

  // Zad 7
  int i = 0;
  int liczba;
  while (1) {
    i++;
    if (i == 200)
      break;
    cout << "Podaj liczbę: ";
    cin >> liczba;
    if (liczba % 2 == 0)
      continue;
    cout << "Liczba to: " << liczba;
  }

  // Zad 8
  cout << "Podaj liczbę";
  cin >> liczba;
  czy_zlozona(liczba);

  // Zad 9
  cout << "Podaj temperaturę: ";
  cin >> liczba;
  Temperatura(liczba);
}
void czy_zlozona(int a) {
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) {
      cout << "Liczba pierwszą nie jest, oto jej dzielnik: " << i << endl;
      break;
    }
  }
}
void Temperatura(int a) {
  if (a < 0)
    cout << "Mróz";
  else if (a < 10)
    cout << "Zimno";
  else if (a < 20)
    cout << "Umiarkowanie";
  else if (a < 30)
    cout << "Ciepło";
  else
    cout << "Gorąco";
  cout << endl;
}
void kalkulator() {
  float pierwsza, druga;
  char znak;
  cout << "Podaj pierwszą liczbę: ";
  cin >> pierwsza;
  cout << "Podaj drugą liczbę: ";
  cin >> druga;
  cout << "Podaj znak operacji, dozwolone znaki (/ + - *):";
  cin >> znak;
  switch (znak) {
  case '+':
    cout << pierwsza << " + " << druga << " = " << pierwsza + druga;
    break;
  case '-':
    cout << pierwsza << " - " << druga << " = " << pierwsza - druga;
    break;
  case '*':
    cout << pierwsza << " * " << druga << " = " << pierwsza * druga;
    break;
  case '/':
    if (druga == 0) {
      cout << "Nie można dzielić przez 0!";
      break;
    }
    cout << pierwsza << " / " << druga << " = " << pierwsza / druga;
    break;
  }
  cout << endl;
}
