#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define MAX_DAYS 100
#define SCREEN_CLEAR "\033[?2J\033[0;0H"

struct population {
  int susceptible;
  int infected;
  int recovered;
  // int day;
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
void add_to_history(population *Population);

void showPopulation(population *Population);

int Menu();

void simulateDay(population *Population, double infectionRate,
                 double recoveryRate, infection_progress *InfectionProgress);

void changeParameters(double *infectionRate, double *recoveryRate);

bool checkPopulation(population *Population);

population_history PopulationHistory;

int day = 0;

infection_progress InfectionProgress;

void showHistory();

int main() {
  // Struktura z populacją
  population Population;
  Population.susceptible = 80;
  // Population.day = 0;
  Population.infected = 10;
  Population.recovered = 10;

  add_to_history(&Population);

  double infectionRate = 0.2;
  double recoveryRate = 0.1;
  // Stałe początkowe

  showPopulation(&Population);

  int choice;
  bool loop = 1;

  cout << SCREEN_CLEAR;

  while (loop) {
    cout << SCREEN_CLEAR;

    showPopulation(&Population);
    choice = Menu();

    switch (choice) {
    case 1:
      if (day >= MAX_DAYS) {
        cout << "Scope exceeded" << endl;
        cin.ignore();
        cin.get();
        break;
      }
      simulateDay(&Population, infectionRate, recoveryRate, &InfectionProgress);
      if (!checkPopulation(&Population))
        break;
      day++;
      add_to_history(&Population);
      break;
    case 2:
      changeParameters(&infectionRate, &recoveryRate);
      break;
    case 3:
      loop = 0;
      break;
    case 4:
      showHistory();
      break;
    default:
      cout << "Wrong option!";
      cin.ignore();
      cin.get();
      break;
    }
  }
}

void showPopulation(population *Population) {
  cout << "Day: " << day << endl;
  cout << "Susceptible: " << Population->susceptible << endl;
  cout << "Infected: " << Population->infected << endl;
  cout << "Recovered: " << Population->recovered << endl;
  cout << "Total: "
       << Population->susceptible + Population->infected + Population->recovered
       << endl;
}
int Menu() {
  cout
      << "=== Epidemic Simulator ===\n\t1. Simulate next day\n\t2. Change "
         "model parameters\n\t3. Exit\n\t4. Simulation History\n\tYour choice:";
  int ret;
  cin >> ret;
  return ret;
}
void simulateDay(population *Population, double infectionRate,
                 double recoveryRate, infection_progress *InfectionProgress) {
  // int total =
  //     Population->infected + Population->recovered + Population->susceptible;
  int newInfected = floor(Population->infected * infectionRate);
  int newRecovered = floor(Population->infected * recoveryRate);
  if (newInfected > Population->susceptible)
    newInfected = Population->susceptible;
  if (newRecovered > Population->infected)
    newRecovered = Population->infected;

  Population->susceptible -= newInfected;
  Population->infected += newInfected;
  Population->infected -= newRecovered;
  Population->recovered += newRecovered;
  InfectionProgress->peopleInfected[day] = newInfected;
  InfectionProgress->peopleRecovered[day] = newRecovered;
}
void changeParameters(double *infectionRate, double *recoveryRate) {
  cout << "Enter infection rate (0-1): ";
  double newInf, newRec;
  cin >> newInf;
  cout << "Enter recovery rate (0-1): ";
  cin >> newRec;
  if (newInf >= 0 && newRec >= 0 && newInf <= 1 && newRec <= 1) {
    *infectionRate = newInf;
    *recoveryRate = newRec;
    cout << "Parameters updated." << endl;
  } else {
    cout << "Invalid parameters, press Enter to continue" << endl;
  }
  cin.ignore();
  cin.get();
}
bool checkPopulation(population *Population) {
  int total =
      Population->infected + Population->susceptible + Population->recovered;
  return (total == 100 && Population->susceptible >= 0 &&
          Population->infected >= 0 && Population->recovered >= 0);
}

void add_to_history(population *Population) {
  // int day = Population->day;
  PopulationHistory.days[day] = day;
  PopulationHistory.infected[day] = Population->infected;
  PopulationHistory.recovered[day] = Population->recovered;
  PopulationHistory.susceptible[day] = Population->susceptible;
}
void showHistory() {
  cout << SCREEN_CLEAR;
  cout << setw(4) << "Lp. " << setw(13) << "susceptible" << setw(10)
       << "infected" << setw(10) << "recovered" << setw(20) << "New infected"
       << setw(20) << "New recovered" << endl;
  for (int i = 0; i <= day; i++) {
    cout << setw(4) << i << setw(10) << PopulationHistory.susceptible[i]
         << setw(10) << PopulationHistory.infected[i] << setw(10)
         << PopulationHistory.recovered[i];

    if (i == 0) {
      cout << setw(15) << "-" << setw(15) << "-" << endl;
    } else {
      cout << setw(15) << InfectionProgress.peopleInfected[i - 1] << setw(15)
           << InfectionProgress.peopleRecovered[i - 1] << endl;
    }
  }
  cout << "\nHistory displayed, press enter to return";

  cin.ignore();
  cin.get();
}
