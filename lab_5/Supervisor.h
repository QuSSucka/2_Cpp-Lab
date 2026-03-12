#pragma once
#include "Manager.h"

class Supervisor : public Manager {
public:
  Supervisor(const std::string& lastName,
    const std::string& firstName,
    double salary,
    const Date& hireDate);

  void evaluateManagers(std::vector<Manager*>& managers) const;

  void print() const override;
};
