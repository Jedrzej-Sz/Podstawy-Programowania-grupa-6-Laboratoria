#include <iostream>
using namespace std;

void fahrenheit_celsius_converter() {
  float celsius, fahr;
  float krok, start, stop;
  cout << "Zdefiniuj początek: ";
  cin >> start;
  cout << "Zdefiniuj koniec: ";
  cin >> stop;
  cout << "Zdefiniuj krok: ";
  cin >> krok;
  for (fahr = start; fahr <= stop; fahr += krok) {
    celsius = 5 * (fahr - 32) / 9;
    cout << fahr << '\t' << celsius << endl;
  }
}
int main() {
  cout << "Zad1 baza" << endl << endl;
  // Zad 1 baza
  for (int i = 0; i < 10; i++) {
    cout << i << endl;
  } // Kod któ©y otrzymaliśmy oryginalnie
  // Zad 1a : Jeżeli i<10 zamienimy na i<=10 to wyświetli się 11 wartości od 0
  // do 10 włącznie Zad 1b wersja [5;7]
  cout << "Zad1a" << endl << endl;
  for (int i = 5; i <= 7; i++) {
    cout << i << endl;
  }
  // Zad 1b wersja [5;7)
  cout << "Zad1b wer 1" << endl << endl;
  for (int i = 5; i < 7; i++) {
    cout << i << endl;
  }
  // Zad 1c
  cout << "Zad1b wer 2" << endl << endl;
  for (int i = 0; i < 10; i += 2) {
    cout << i << endl;
  }
  // Zad 1d od 10 do 0
  cout << "Zad1c" << endl << endl;
  for (int i = 10; i > 0; i--) {
    cout << i << endl;
  }
  // Zad 2
  cout << "Zad2" << endl << endl;
  int fahr, celsius;
  int start, limit, krok;

  start = 0;
  limit = 200;
  krok = 20;
  fahr = start;
  while (fahr <= limit) {
    celsius = 5 * (fahr - 32) / 9;
    cout << fahr << '\t' << celsius << endl;
    fahr += krok;
  }
  /* Ten kod dokonuje konwersji stopni fahrenheita na celsjusza zgodnie ze
   * wzorem C = (5/9) * (f - 32) Następnie kod iteruje według parametróe takich
   * jak start określającym liczbę początkową stopni fahrenheita, koniec czyli
   * do jakiego stopnia włącznie ma iterować a także wielkość kroku pomiędzy
   * poszczególnymi iteracjami Z racji operacji na intach a nie na floatach
   * dokładność jest co do liczb całkowitych
   *
   * */

  // Zad 3 Po zamianie pętli while na for operacja na kroku deklarowana jest w
  // tej samej linii co reszta arguemtów pętli zgodnie z
  // formatem(start;stop;krok)

  // Zad 5 Po zamianie na ułamek (5/9) z racji że nie jest to liczba całkowita
  // kompilator skróci ją do wartości 0. A więc nieważne jak się zmieni iterator
  // wynikiem byłoby 0. Aby nie skrócił tego musiałby być zapis(5.0/9.0), wtedy
  // kompilator zauważy że to float.
  cout << "Zad6" << endl << endl;
  fahrenheit_celsius_converter();
  cout << "Zad7" << endl << endl;
  float input;
  for (int i = 0; i < 10; i++) {
    cout << "Podaj liczbę: ";
    cin >> input;
    if (input >= 0)
      cout << input;
    cout << endl;
  }
  cout << "Zad8" << endl << endl;
  for (int i = 0; i <= 100; i++) {
    if (i % 2 == 0)
      cout << i << " ";
  }
  cout << endl;

  cout << "Zad9" << endl << endl;
  int in_dec;
  cout << "Podaj liczbę do modulo: ";
  cin >> in_dec;
  for (int i = 0; i <= 100; i++) {
    if (i % in_dec == 0)
      cout << i << " ";
  }
  cout << endl;
}
