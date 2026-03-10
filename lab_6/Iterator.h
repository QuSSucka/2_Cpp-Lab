#pragma once

class Iterator {
public:
    // Возвращает текущий элемент
    virtual double GetElem() const = 0;
    // true — текущая позиция валидна (есть что читать)
    virtual bool   IsNext()  const = 0;
    // Переход к следующему элементу
    virtual void   Next()          = 0;
    virtual ~Iterator() = default;
};
