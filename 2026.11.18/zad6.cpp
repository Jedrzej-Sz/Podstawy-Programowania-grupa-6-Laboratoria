#include <iostream>
using namespace std;

void sumator_tablic(int (*tab1)[2], int (*tab2)[2], int (*tabres)[2]);

void tab_print(int *tab1);

int main() {
  int tab1[2][2] = {1, 2, 3, 4};
  int tab2[2][2] = {5, 6, 7, 8};
  int tabres[2][2];
  sumator_tablic(tab1, tab2, tabres);
  tab_print(&tabres[0][0]);
}
void sumator_tablic(int (*tab1)[2], int (*tab2)[2], int (*tabres)[2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tabres[i][j] = tab1[i][j] + tab2[i][j];
    }
  }
}
void tab_print(int *tab1) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << *(tab1 + i * 2 + j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}
