#include <cmath>
#include <iostream>
using namespace std;

struct population {
  int susceptible;
  int infected;
  int recovered;
  int day;
};

void showPopulation(population Population);

int Menu();

void simulateDay(population *Population, double infectionRate,
                 double recoveryRate);

void changeParameters(double *infectionRate, double *recoveryRate);

bool checkPopulation(population *Population);

int main() {
  // Struktura z populacją
  population Population;
  Population.susceptible = 80;
  Population.day = 0;
  Population.infected = 10;
  Population.recovered = 10;

  double infectionRate = 0.2;
  double recoveryRate = 0.1;
  // Stałe początkowe

  showPopulation(Population);

  int choice;
  bool loop = 1;

  while (loop) {
    showPopulation(Population);
    choice = Menu();

    switch (choice) {
    case 1:
      simulateDay(&Population, infectionRate, recoveryRate);
      checkPopulation(&Population);
      break;
    case 2:
      changeParameters(&infectionRate, &recoveryRate);
      break;
    case 3:
      loop = 0;
    default:
      break;
    }
  }
}

void showPopulation(population Population) {
  cout << "Day: " << Population.day << endl;
  cout << "Susceptible: " << Population.susceptible << endl;
  cout << "Infected: " << Population.infected << endl;
  cout << "Recovered: " << Population.recovered << endl;
  cout << "Total: "
       << Population.susceptible + Population.infected + Population.recovered
       << endl;
}
int Menu() {
  cout << "=== Epidemic Simulator ===\n\t1. Simulate next day\n\t2. Change "
          "model parameters\n\t3. Exit\n\tYour choice:";
  int ret;
  cin >> ret;
  return ret;
}
void simulateDay(population *Population, double infectionRate,
                 double recoveryRate) {
  int total =
      Population->infected + Population->recovered + Population->susceptible;
  int newInfected = floor(Population->susceptible * infectionRate);
  int newRecovered = floor(Population->infected * recoveryRate);
  if (newInfected > Population->susceptible)
    newInfected = Population->susceptible;
  if (newRecovered > Population->infected)
    newRecovered = Population->infected;
  Population->susceptible -= newInfected;
  Population->infected += newInfected;
  Population->infected -= newRecovered;
  Population->recovered += newRecovered;
}
void changeParameters(double *infectionRate, double *recoveryRate) {
  cout << "Enter infection rate (0-1): ";
  cin >> *infectionRate;
  cout << "Enter recovery rate (0-1): ";
  cin >> *recoveryRate;
  cout << "Parameters updated." << endl;
}
bool checkPopulation(population *Population) {
  int total =
      Population->infected + Population->susceptible + Population->recovered;
  if (total == 100)
    return true;
  else
    return false;
}
