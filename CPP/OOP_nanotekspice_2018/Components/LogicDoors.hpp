/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** LogicDoors
*/

#ifndef LOGICDOORS_HPP_
#define LOGICDOORS_HPP_

class LogicDoors {
public:
    LogicDoors() {}
    virtual bool    compute(bool a, bool b) = 0;

protected:
private:
};

class AND : public LogicDoors {
public:
    AND() : LogicDoors() {}
    bool    compute(bool a, bool b);
};

class NAND : public LogicDoors {
public:
    NAND() : LogicDoors() {}
    bool    compute(bool a, bool b);
};

class NOR : public LogicDoors {
public:
    NOR() : LogicDoors() {}
    bool    compute(bool a, bool b);
};

class OR : public LogicDoors {
public:
    OR() : LogicDoors() {}
    bool    compute(bool a, bool b);
};

class XOR : public LogicDoors {
public:
    XOR() : LogicDoors() {}
    bool    compute(bool a, bool b);
};

#endif /* !LOGICDOORS_HPP_ */
