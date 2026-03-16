#include "Supervisor.h"
using namespace std;

Supervisor::Supervisor(const string& lastName,
  const string& firstName,
  double salary,
  const Date& hireDate)
  : Manager(lastName, firstName, "Supervisor", salary, hireDate) {
}

void Supervisor::evaluateManagers() const {
  cout << "\n===== Оценка менеджеров Supervisor'ом "
    << getLastName() << " =====\n";

  for (const auto& t : tasks) {
    Manager* mgr = dynamic_cast<Manager*>(t.employee);
    if (!mgr) continue;

    if (mgr->allTasksOnTime()) {
      double mgrBonus = mgr->getSalary() * 0.2;
      mgr->addBonus(mgrBonus);
      cout << "[Бонус] " << mgr->getLastName()
        << " " << mgr->getFirstName()
        << " -> +" << mgrBonus << " руб."
        << " (все задания выполнены в срок)\n";
    }
    else {
      cout << "[Без бонуса] " << mgr->getLastName()
        << " " << mgr->getFirstName()
        << " -- не все задания выполнены в срок\n";
    }
  }
}

void Supervisor::print() const {
  cout << "*** SUPERVISOR ***\n";
  Employee::print();
  cout << "Бонус: " << getBonus() << " руб.\n";

  cout << "--- Делегированные задачи (" << tasks.size() << ") ---\n";
  for (size_t i = 0; i < tasks.size(); ++i) {
    cout << "Задача #" << (i + 1)
      << " -> менеджер: " << tasks[i].employee->getLastName() << "\n";
    cout << "  " << tasks[i].description
      << " | дедлайн: " << tasks[i].deadline << "\n";
  }
}

void Supervisor::printInfo(Employee* emp) const {
  cout << "\n[Supervisor::printInfo]\n";
  Supervisor* sup = dynamic_cast<Supervisor*>(emp);
  if (sup) {
    cout << "*** Информация о Supervisor ***\n";
    sup->print();
  }
  else {
    Manager::printInfo(emp);
  }
}
