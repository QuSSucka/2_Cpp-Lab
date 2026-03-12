#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Employee {
private:
  std::string lastName;
  std::string firstName;
  std::string position;
  double salary;
  Date hireDate;
  Date fireDate;
  bool isFired;
  const int employeeID;

  static int instanceCount;

public:
  Employee(const std::string& lastName,
    const std::string& firstName,
    const std::string& position,
    double salary,
    const Date& hireDate);

  Employee(const Employee&) = delete;
  Employee& operator=(const Employee&) = delete;

  virtual ~Employee();

  std::string getLastName() const;
  std::string getFirstName() const;
  std::string getPosition() const;
  double getSalary() const;
  Date getHireDate() const;
  Date getFireDate() const;
  bool getIsFired() const;
  int getEmployeeID() const;

  static int getInstanceCount();

  void setLastName(const std::string& v);
  void setFirstName(const std::string& v);
  void setPosition(const std::string& v);
  void setSalary(double v);
  void setHireDate(const Date& d);

  void fire(const Date& d);

  virtual void print() const;
};
