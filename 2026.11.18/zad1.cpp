#include <iostream>
using namespace std;
int main() {
  int tab[10];
  cout << "Podawaj liczby: ";
  for (int i = 0; i < 10; i++) {
    cin >> tab[i];
  }
  for (int i = 9; i >= 0; i--) {
    cout << "Liczba" << i + 1 << " : " << tab[i] << endl;
  }
  return 0;
}
