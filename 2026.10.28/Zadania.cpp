#include <iostream>
using namespace std;
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

  // Zad 5 Pętla pokazana na ekranie będzie nieskończona gdyż nie ma warunku
  // stop nieskończona while to while(1), while(true), de facto wsztstko co nie
  // jest false albo 0
  /*
  while(1){ cout<<"BOEING BOEING"<<endl} //Przykłąd irytującej pętli
  */
}
