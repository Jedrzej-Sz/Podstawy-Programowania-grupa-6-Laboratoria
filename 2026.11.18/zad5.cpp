#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
  srand(time(0));
  int tab[10];
  for (int i = 0; i < 10; i++) {
    tab[i] = rand() % 11;
  }
  int fun = rand() % 11;
  int ile = 0;
  for (int i = 0; i < 10; i++) {
    if (tab[i] == fun)
      ile++;
  }
  cout << "Tyle liczb szczęśliwych wylosowano: " << ile << endl;
}
