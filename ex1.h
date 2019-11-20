#ifndef PROJECT_EX1_H
#define PROJECT_EX1_H

#include "Expression.h"
#include <queue>
#include <stack>

using namespace std;


class BinaryOperator: public Expression {

protected:
Expression *right, *left;

public:
    BinaryOperator(Expression *right, Expression *left);
    virtual double calculate() = 0;
};

class UnaryOperator: public Expression {

protected:
Expression *exp;

public:
    UnaryOperator(Expression *exp);
    virtual double calculate() = 0;
};

class Plus: public BinaryOperator {
    public:
    Plus(Expression* exp1, Expression* exp2);
    double calculate();
    ~Plus();
    
};

class Minus: public BinaryOperator {
    public:
    Minus(Expression* exp1, Expression* exp2);
    double calculate();
    ~Minus();
};

class Mul: public BinaryOperator {
    public:
    Mul(Expression* exp1, Expression* exp2);
    double calculate();
    ~Mul();
};

class Div: public BinaryOperator {
    public:
    Div(Expression* exp1, Expression* exp2);
    double calculate();
    ~Div();
};

class UPlus: public UnaryOperator {
    public:
    UPlus(Expression* exp1);
    double calculate();
    ~UPlus();
};

class UMinus: public UnaryOperator {
    public:
    UMinus(Expression* exp1);
    double calculate();
    ~UMinus();
};

class Variable: public Expression {
    private:
    string name;
    double value;

    public:
    Variable(string name, double value);
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double val);
    Variable& operator-=(double val);
    Variable& operator++(int num);
    Variable& operator--(int num);
    double calculate();
};

class Value: public Expression {
    private:
    const double val;

    public:
    Value(double value) : val(value) {};
    double calculate();
};

class Interpreter {
    private:
        queue<double> numbers;
        stack<char> operators;

    public:
        Expression* interpret(string tokens);
        void setVariables(string vars);
};

#endif 
