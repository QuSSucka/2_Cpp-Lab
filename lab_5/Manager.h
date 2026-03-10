#pragma once
#include <vector>
#include "Employee.h"

struct Task {
  Employee* employee;
  string     description;
  Date       deadline;
  Date       completedDate;
  bool       isDone;

  Task(Employee* emp, const string& desc, const Date& dl);

  void complete(const Date& date);
  bool completedOnTime() const;
  void print() const;
};

class Manager : public Employee {
private:
  vector<Task> tasks;
  double       bonus;

public:
  Manager(const string& lastName,
    const string& firstName,
    const string& position,
    double salary,
    const Date& hireDate);

  void   assignTask(Employee* emp, const string& description, const Date& deadline);
  void   completeTask(int index, const Date& completionDate);

  bool   allTasksOnTime() const;
  void   addBonus(double amount);
  double getBonus() const;

  const vector<Task>& getTasks() const;

  void print() const override;
};
