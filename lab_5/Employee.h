#pragma once
#include <string>
#include "Date.h"

class Employee {
private:
  string lastName;
  string firstName;
  string position;
  double      salary;
  Date        hireDate;
  Date        fireDate;
  const int   employeeID;

  static int instanceCount;

public:
  Employee(const string& lastName,
    const string& firstName,
    const string& position,
    double salary,
    const Date& hireDate,
    const Date& fireDate = Date());

  Employee(const Employee&) = delete;
  Employee& operator=(const Employee&) = delete;

  virtual ~Employee();

  // Геттеры
  string getLastName()   const;
  string getFirstName()  const;
  string getPosition()   const;
  double      getSalary()     const;
  Date        getHireDate()   const;
  Date        getFireDate()   const;
  int         getEmployeeID() const;

  static int getInstanceCount();

  // Сеттеры
  void setLastName(const string& v);
  void setFirstName(const string& v);
  void setPosition(const string& v);
  void setSalary(double v);
  void setHireDate(const Date& d);
  void setFireDate(const Date& d);

  virtual void print() const;
};
