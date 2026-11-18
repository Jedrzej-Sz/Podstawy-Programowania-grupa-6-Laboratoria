#include <iostream>
using namespace std;
void min(double *tab);
void max(double *tab);
void avg(double *tab);

int main() {
  double tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << "Ile liczb podajesz[0-10]: ";
  int ile;
  cin >> ile;
  if (ile < 0)
    return -1;
  if (ile > 10)
    ile = 10;
  for (int i = 0; i < ile; i++) {
    cin >> tab[i];
  }
  min(tab);
  max(tab);
  avg(tab);
}
void min(double *tab) {
  int min = tab[0];
  for (int i = 1; i < 10; i++) {
    if (tab[i] < min)
      min = tab[i];
  }
  cout << "Minimalna wartość: " << min << endl;
}
void max(double *tab) {
  int max = tab[0];
  for (int i = 1; i < 10; i++) {
    if (tab[i] > max)
      max = tab[i];
  }
  cout << "Minimalna wartość: " << max << endl;
}
void avg(double *tab) {
  double avg = 0;
  for (int i = 0; i < 10; i++) {
    avg += tab[i];
  }
  cout << "Średnia to: " << avg / 10.0 << endl;
}
