#include <iostream>
using namespace std;
void min(int *tab);
void max(int *tab);
int avg(int *tab);
void less_than(int *tab, int a);
int main() {
  int tab[10];
  min(tab);
  max(tab);
  int i = (int)avg(tab);
  cout << "Średnia liczb w tablicy to: " << i << endl;
  less_than(tab, i);
}
void min(int *tab) {
  int min = tab[0];
  for (int i = 1; i < 10; i++) {
    if (tab[i] < min)
      min = tab[i];
  }
  cout << "Minimalna wartość: " << min << endl;
}
void max(int *tab) {
  int max = tab[0];
  for (int i = 1; i < 10; i++) {
    if (tab[i] > max)
      max = tab[i];
  }
  cout << "Minimalna wartość: " << max << endl;
}
int avg(int *tab) {
  float avg = 0;
  for (int i = 0; i < 10; i++) {
    avg += tab[i];
  }
  return avg / 10.0;
}
void less_than(int *tab, int a) {
  int ile = 0;
  cout << "Liczby mniejsze od " << a << " to: ";
  for (int i = 0; i < 10; i++) {
    if (tab[i] < a)
      cout << tab[i] << " ";
    ile++;
  }
  cout << endl;
  cout << "Liczb mniejszych od " << a << " jest " << ile << endl;
}
