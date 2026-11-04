// STARA WERSJA LABA, pomyliłem się

#include <iostream>
#include <stdlib.h>
using namespace std;

float FtoC(float F) { return (F - 32.0) * 5.0 / 9.0; }
float FtoK(float F) { return (F + 459.67) * 5.0 / 9.0; }
float CtoF(float C) { return C * 9.0 / 5.0 + 32.0; }
float CtoK(float C) { return C + 273.15; }
float KtoC(float K) { return K - 273.15; }
float KtoF(float K) { return K * (9.0 / 5.0) - 459.67; }
void Kalkulator_temperaturowy(bool &ret);
void pokaz_menu();
bool check(float A, char B);

int main() {
  bool ret = true;
  while (ret) {
    Kalkulator_temperaturowy(ret);
  }
}
void Kalkulator_temperaturowy(bool &ret) {
  pokaz_menu();

  cout << "Wybór: " << endl;
  int wybor;
  cin >> wybor;

  float liczba;
  cout << "Podaj liczbę: ";
  cin >> liczba;

  switch (wybor) {
  case 1:
    cout << "Celsjusz: " << FtoC(liczba) << endl;
    break;
  case 2:
    cout << "Kelwin: " << FtoK(liczba) << endl;
    break;
  case 3:
    cout << "Fahrenheit: " << CtoF(liczba) << endl;
    break;
  case 4:
    cout << "Kelwin: " << CtoK(liczba) << endl;
    break;
  case 5:
    cout << "Celsjusz: " << KtoC(liczba) << endl;
    break;
  case 6:
    cout << "Fahrenheit: " << KtoF(liczba) << endl;
    break;
  default:
    ret = false;
    break;
  }
}
void pokaz_menu() {
  cout << "Z jakiej funkcji chcesz skorzystać?" << endl;
  cout << "1 - przelicz Fahr -> Celsius" << endl;
  cout << "2 - przelicz Fahr -> Kelwin" << endl;
  cout << "3 - przelicz Celsius -> Fahr" << endl;
  cout << "4 - przelicz Celsius -> Kelwin" << endl;
  cout << "5 - przelicz Kelwin -> Celsius" << endl;
  cout << "6 - przelicz Kelwin -> Fahr" << endl;
  cout << "7 - zakończ działanie programu" << endl;
}
bool check(float A, char B) {
  bool TF;
  switch (B) {
  case 'C':
    TF = A > -273.15 ? true : false;
    break;
  case 'F':
    TF = A > -459.67 ? true : false;
    break;
  case 'K':
    TF = A > 0 ? true : false;
    break;
  }
  return TF;
}
