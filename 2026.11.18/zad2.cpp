#include <iostream>
using namespace std;
void fibonnacizator(int *tab, int lvl);
void wypisz_tabele(int *tab, int ile);
int main() {
  int input;
  int *tab;
  cout << "Ile liczb ciągu Fibonnaciego chcesz otrzymać po 0 i 1? : ";
  cin >> input;
  if (input < 0) {
    return -1;
  }
  if (input == 0) {
    return 0;
  }
  tab = new int[input + 2];
  tab[0] = 0;
  tab[1] = 1;
  fibonnacizator(tab, input);
  wypisz_tabele(tab, input + 2);
}
void fibonnacizator(int *tab, int lvl) {
  for (int i = 0; i < lvl; i++) {
    tab[i + 2] = tab[i] + tab[i + 1];
  }
}
void wypisz_tabele(int *tab, int ile) {
  for (int i = 0; i < ile; i++) {
    cout << tab[i] << " ";
  }
  cout << endl;
}
