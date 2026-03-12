#include "Manager.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Task::Task(Employee* emp, const string& desc, const Date& dl)
  : employee(emp), description(desc), deadline(dl), isDone(false)
{
}

void Task::complete(const Date& date) {
  completedDate = date;
  isDone = true;
}

bool Task::completedOnTime() const {
  return isDone && (completedDate <= deadline);
}

void Task::print() const {
  cout << "  [Сотрудник] " << employee->getLastName()
    << " " << employee->getFirstName() << "\n";
  cout << "  [Задача]    " << description << "\n";
  cout << "  [Дедлайн]   " << deadline << "\n";
  if (isDone) {
    cout << "  [Выполнено] " << completedDate
      << (completedOnTime() ? "  (в срок)" : "  (просрочено)")
      << "\n";
  }
  else {
    cout << "  [Статус]    Не выполнено\n";
  }
}

Manager::Manager(const string& lastName,
  const string& firstName,
  const string& position,
  double salary,
  const Date& hireDate)
  : Employee(lastName, firstName, position, salary, hireDate),
  bonus(0.0)
{
}

void Manager::assignTask(Employee* emp,
  const string& description,
  const Date& deadline)
{
  tasks.emplace_back(emp, description, deadline);
}

void Manager::completeTask(int index, const Date& completionDate) {
  if (index < 0 || index >= static_cast<int>(tasks.size()))
    throw out_of_range("Неверный индекс задания");
  tasks[index].complete(completionDate);
  if (tasks[index].completedOnTime()) {
    double empBonus = tasks[index].employee->getSalary() * 0.1;
    cout << "[Бонус] " << tasks[index].employee->getLastName()
      << " получает бонус: " << empBonus << " руб.\n";
  }
}

bool Manager::allTasksOnTime() const {
  if (tasks.empty()) return false;
  for (const auto& t : tasks)
    if (!t.completedOnTime()) return false;
  return true;
}

void   Manager::addBonus(double amount) { bonus += amount; }
double Manager::getBonus()        const { return bonus; }

const vector<Task>& Manager::getTasks() const { return tasks; }

void Manager::print() const {
  Employee::print();
  cout << "Бонус менеджера: " << bonus << " руб.\n";
  cout << "--- Задания подчинённых (" << tasks.size() << ") ---\n";
  for (size_t i = 0; i < tasks.size(); ++i) {
    cout << "Задание #" << (i + 1) << ":\n";
    tasks[i].print();
  }
}
