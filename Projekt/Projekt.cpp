#include <cmath>
#include <iostream>
using namespace std;

#define MAX_DAYS 100

struct population {
  int susceptible;
  int infected;
  int recovered;
  int day;
};

struct population_history {
  int susceptible[MAX_DAYS + 1];
  int infected[MAX_DAYS + 1];
  int recovered[MAX_DAYS + 1];
  int days[MAX_DAYS + 1];
};

struct infection_progress {
  int peopleRecovered[MAX_DAYS];
  int peopleInfected[MAX_DAYS];
};

void showPopulation(population *Population);

int Menu();

void simulateDay(population *Population, double infectionRate,
                 double recoveryRate);

void changeParameters(double *infectionRate, double *recoveryRate);

bool checkPopulation(population *Population);

population_history PopulationHistory;

int day = 0;

infection_progress InfectionProgress;

void update_infection_progress();
void add_to_history(population *Population);

int main() {
  // Struktura z populacją
  population Population;
  Population.susceptible = 80;
  Population.day = 0;
  Population.infected = 10;
  Population.recovered = 10;

  add_to_history(&Population);

  double infectionRate = 0.2;
  double recoveryRate = 0.1;
  // Stałe początkowe

  showPopulation(&Population);

  int choice;
  bool loop = 1;

  while (loop) {
    showPopulation(&Population);
    choice = Menu();

    switch (choice) {
    case 1:
      simulateDay(&Population, infectionRate, recoveryRate);
      day++;
      add_to_history(&Population);
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

void showPopulation(population *Population) {
  cout << "Day: " << Population->day << endl;
  cout << "Susceptible: " << Population->susceptible << endl;
  cout << "Infected: " << Population->infected << endl;
  cout << "Recovered: " << Population->recovered << endl;
  cout << "Total: "
       << Population->susceptible + Population->infected + Population->recovered
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

void add_to_history(population *Population) {
  int day = Population->day;
  PopulationHistory.days[day] = Population->day;
  PopulationHistory.infected[day] = Population->infected;
  PopulationHistory.recovered[day] = Population->recovered;
  PopulationHistory.susceptible[day] = Population->susceptible;
}
void update_infection_progress();
{
}
