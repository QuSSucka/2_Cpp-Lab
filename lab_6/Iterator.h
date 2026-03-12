#pragma once

class Iterator {
public:
  virtual double GetElem() const = 0;
  virtual bool   IsNext()  const = 0;
  virtual void   Next() = 0;
  virtual ~Iterator() = default;
};
