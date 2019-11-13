#ifndef PROJECT_EX1_H
#define PROJECT_EX1_H

using namespace std;


class BinaryOperator: public Expression {

protected:
Expression *right, *left;

public:
    virtual double calculate() = 0;
    ~BinaryOperator(){};
};

class UnaryOperator: public Expression {

protected:
Expression *expression;

public:
    virtual double calculate() = 0;
    ~UnaryOperator(){};
};

class Plus: public BinaryOperator {
    public:
    double calculate() {};
    
};

class Minus: public BinaryOperator {
    public:
    double calculate() {};
    
};

class Mul: public BinaryOperator {
    public:
    double calculate() {};
    
};

class Div: public BinaryOperator {
    public:
    double calculate() {};
    
};

class UPlus: public UnaryOperator {
    public:
    double calculate() {};
    
};

class UMinus: public UnaryOperator {
    public:
    double calculate() {};
    
};

class Variable: public Expression {
    private:
    string name;
    double value;

    Variable& operator++(){};
    Variable& operator--(){};
    Variable& operator+=(double val){};
    Variable& operator-=(double val){};
    Variable& operator++(int num){};
    Variable& operator--(int num){};
};

class Value: public Expression {
    private:
    const double val;
};

#endif 
