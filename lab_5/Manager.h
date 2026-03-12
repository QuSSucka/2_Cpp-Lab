#pragma once
#include <vector>
#include "Employee.h"

struct Task {
  Employee* employee;
  std::string description;
  Date deadline;
  Date completedDate;
  bool isDone;

  Task(Employee* emp, const std::string& desc, const Date& dl);

  void complete(const Date& date);
  bool completedOnTime() const;
  void print() const;
};

class Manager : public Employee {
private:
  std::vector<Task> tasks;
  double bonus;

public:
  Manager(const std::string& lastName,
    const std::string& firstName,
    const std::string& position,
    double salary,
    const Date& hireDate);

  void assignTask(Employee* emp, const std::string& description, const Date& deadline);
  void completeTask(int index, const Date& completionDate);

  bool allTasksOnTime() const;
  void addBonus(double amount);
  double getBonus() const;

  const std::vector<Task>& getTasks() const;

  void print() const override;
};
