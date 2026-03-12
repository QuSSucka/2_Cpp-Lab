#pragma once

template<typename T>
class Iterator {
public:
  virtual T    GetElem() const = 0;
  virtual bool IsNext()  const = 0;
  virtual void Next() = 0;
  virtual ~Iterator() = default;
};
