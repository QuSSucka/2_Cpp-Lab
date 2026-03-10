#include "Supervisor.h"
#include <iostream>
using namespace std;

Supervisor::Supervisor(const string& lastName,
  const string& firstName,
  double salary,
  const Date& hireDate,
  const Date& fireDate)
  : Manager(lastName, firstName, "Supervisor", salary, hireDate, fireDate)
{
}

void Supervisor::evaluateManagers(vector<Manager*>& managers) const {
  cout << "\n===== Оценка менеджеров Supervisor'ом "
    << getLastName() << " =====\n";

  for (auto* mgr : managers) {
    if (mgr->allTasksOnTime()) {
      double mgrBonus = mgr->getSalary() * 0.2;
      mgr->addBonus(mgrBonus);
      cout << "[Бонус менеджеру] " << mgr->getLastName()
        << " " << mgr->getFirstName()
        << " -> +" << mgrBonus << " руб."
        << " (все задания выполнены в срок)\n";
    }
    else {
      cout << "[Без бонуса]      " << mgr->getLastName()
        << " " << mgr->getFirstName()
        << " -- не все задания выполнены в срок\n";
    }
  }
}

void Supervisor::print() const {
  cout << "*** SUPERVISOR ***\n";
  Manager::print();
}
