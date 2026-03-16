#include <iostream>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Supervisor.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "");

  Employee emp1("Иванов", "Алексей", "Разработчик", 80000, Date(1, 3, 2022));
  Employee emp2("Петров", "Дмитрий", "Тестировщик", 70000, Date(15, 6, 2021));
  Employee emp3("Сидоров", "Евгений", "Аналитик", 75000, Date(10, 1, 2023));
  Employee emp4("Морозов", "Кирилл", "Дизайнер", 65000, Date(3, 3, 2020));
  Employee emp5("Волкова", "Анна", "Копирайтер", 60000, Date(7, 7, 2021));

  Manager mgr1("Козлова", "Ольга", "Team Lead", 120000, Date(1, 9, 2019));
  Manager mgr2("Новиков", "Сергей", "Project Manager", 130000, Date(5, 5, 2018));

  Supervisor sup("Громов", "Виктор", 200000, Date(1, 1, 2015));

  sup.assignTask(&mgr1, "Оценить команду и сдать отчёт", Date(30, 4, 2025));
  sup.assignTask(&mgr2, "Провести ревью проектов", Date(15, 5, 2025));

  mgr1.assignTask(&emp1, "Разработать модуль авторизации", Date(30, 4, 2025));
  mgr2.assignTask(&emp4, "Разработать UI-прототип", Date(10, 5, 2025));


  sup.evaluateManagers();
  sup.print();

  cout << "\n========= printInfo через Employee* =========\n";

  Employee* ptr1 = &emp1;
  emp1.printInfo(ptr1);

  Employee* ptr2 = &mgr1;
  mgr1.printInfo(ptr2);

  Employee* ptr3 = &sup;
  sup.printInfo(ptr3);

  cout << "\nВсего объектов Employee: "
    << Employee::getInstanceCount() << "\n";

  return 0;
}
