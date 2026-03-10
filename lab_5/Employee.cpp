#include "Employee.h"
#include <iostream>
#include <stdexcept>

int Employee::instanceCount = 0;

Employee::Employee(const string& lastName,
  const string& firstName,
  const string& position,
  double salary,
  const Date& hireDate,
  const Date& fireDate)
  : lastName(lastName),
  firstName(firstName),
  position(position),
  salary(salary),
  hireDate(hireDate),
  fireDate(fireDate),
  employeeID(++instanceCount)
{
}

Employee::~Employee() { --instanceCount; }

string Employee::getLastName()   const { return lastName; }
string Employee::getFirstName()  const { return firstName; }
string Employee::getPosition()   const { return position; }
double Employee::getSalary()     const { return salary; }
Date   Employee::getHireDate()   const { return hireDate; }
Date   Employee::getFireDate()   const { return fireDate; }
int    Employee::getEmployeeID() const { return employeeID; }

int Employee::getInstanceCount() { return instanceCount; }

void Employee::setLastName(const string& v) { lastName = v; }
void Employee::setFirstName(const string& v) { firstName = v; }
void Employee::setPosition(const string& v) { position = v; }

void Employee::setSalary(double v) {
  if (v < 0) throw invalid_argument("Зарплата не может быть отрицательной");
  salary = v;
}

void Employee::setHireDate(const Date& d) { hireDate = d; }
void Employee::setFireDate(const Date& d) { fireDate = d; }

void Employee::print() const {
  cout << "=============================\n";
  cout << "Табельный №: " << employeeID << "\n";
  cout << "ФИО:         " << lastName << " " << firstName << "\n";
  cout << "Должность:   " << position << "\n";
  cout << "Зарплата:    " << salary << " руб.\n";
  cout << "Принят:      " << hireDate.toString() << "\n";
  cout << "Уволен:      " << fireDate.toString() << "\n";
}
