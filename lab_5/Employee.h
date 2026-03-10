#pragma once
#include <string>
#include "Date.h"

class Employee {
private:
  string     lastName;
  string     firstName;
  string     position;
  double     salary;
  Date       hireDate;
  Date       fireDate;
  bool       isFired;       // флаг: уволен ли сотрудник
  const int  employeeID;

  static int instanceCount;

public:
  Employee(const string& lastName,
    const string& firstName,
    const string& position,
    double salary,
    const Date& hireDate);

  Employee(const Employee&) = delete;
  Employee& operator=(const Employee&) = delete;

  virtual ~Employee();

  // Геттеры
  string getLastName()   const;
  string getFirstName()  const;
  string getPosition()   const;
  double getSalary()     const;
  Date   getHireDate()   const;
  Date   getFireDate()   const;
  bool   getIsFired()    const;
  int    getEmployeeID() const;

  static int getInstanceCount();

  // Сеттеры
  void setLastName(const string& v);
  void setFirstName(const string& v);
  void setPosition(const string& v);
  void setSalary(double v);
  void setHireDate(const Date& d);

  // Уволить сотрудника
  void fire(const Date& d);

  virtual void print() const;
};
