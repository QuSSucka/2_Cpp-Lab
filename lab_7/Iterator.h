#pragma once

template<typename T>
class Iterator {
public:
    virtual T    GetElem() const = 0;   // текущий элемент
    virtual bool IsNext()  const = 0;   // true — позиция валидна
    virtual void Next()          = 0;   // переход к следующему
    virtual ~Iterator() = default;
};
