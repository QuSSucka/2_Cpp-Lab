#include <locale.h>
#include "Employee.h"
#include "Manager.h"
#include "Supervisor.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "");
  Employee emp1("Иванов", "Алексей", "Разработчик", 80000, Date(1, 3, 2022));
  Employee emp2("Петров", "Дмитрий", "Тестировщик", 70000, Date(15, 6, 2021));
  Employee emp3("Сидоров", "Евгений", "Аналитик", 75000, Date(10, 1, 2023));

  Manager mgr1("Козлова", "Ольга", "Team Lead", 120000, Date(1, 9, 2019));
  mgr1.assignTask(&emp1, "Разработать модуль авторизации", Date(30, 4, 2025));
  mgr1.assignTask(&emp2, "Написать автотесты для API", Date(25, 4, 2025));
  mgr1.assignTask(&emp3, "Подготовить аналитический отчёт", Date(20, 4, 2025));
  mgr1.completeTask(0, Date(28, 4, 2025)); // в срок
  mgr1.completeTask(1, Date(30, 4, 2025)); // просрочка
  mgr1.completeTask(2, Date(18, 4, 2025)); // в срок

  Employee emp4("Морозов", "Кирилл", "Дизайнер", 65000, Date(3, 3, 2020));
  Employee emp5("Волкова", "Анна", "Копирайтер", 60000, Date(7, 7, 2021));

  Manager mgr2("Новиков", "Сергей", "Project Manager", 130000, Date(5, 5, 2018));
  mgr2.assignTask(&emp4, "Разработать UI-прототип", Date(10, 5, 2025));
  mgr2.assignTask(&emp5, "Написать технические тексты", Date(12, 5, 2025));
  mgr2.completeTask(0, Date(9, 5, 2025)); // в срок
  mgr2.completeTask(1, Date(11, 5, 2025)); // в срок

  // Пример увольнения сотрудника
  emp2.fire(Date(1, 9, 2024));

  Supervisor sup("Громов", "Виктор", 200000, Date(1, 1, 2015));
  vector<Manager*> managers = { &mgr1, &mgr2 };
  sup.evaluateManagers(managers);

  cout << "\n========= ВЫВОД ДАННЫХ =========\n";
  emp1.print(); emp2.print(); emp3.print();
  mgr1.print(); mgr2.print();
  sup.print();

  cout << "\nВсего объектов Employee: "
    << Employee::getInstanceCount() << "\n";

  return 0;
}
