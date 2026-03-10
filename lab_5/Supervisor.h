#pragma once
#include <vector>
#include "Manager.h"

class Supervisor : public Manager {
public:
  Supervisor(const string& lastName,
    const string& firstName,
    double salary,
    const Date& hireDate,
    const Date& fireDate = Date());

  void evaluateManagers(vector<Manager*>& managers) const;

  void print() const override;
};
