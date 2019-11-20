#include <string>
#include <iostream>
#include <queue>
#include <stack>

#include "ex1.h"
#include "Expression.h"

using namespace std;

BinaryOperator::BinaryOperator(Expression *right, Expression *left) {
    this->left = left;
    this->right = right;
}

UnaryOperator::UnaryOperator(Expression *exp) {
    this->exp = exp;
}

Plus::Plus(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
double Plus::calculate() {
    return right->calculate() + left->calculate();
}
Plus::~Plus() {
    if (right != NULL)
    {
        delete(this->right);
    }
    
    if (left != NULL)
    {
        delete(this->left);
    }
}

Minus::Minus(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
    
double Minus::calculate() {
    return right->calculate() - left->calculate();
}

Minus::~Minus() {
    if (right != NULL)
    {
        delete(this->right);
    }
    
    if (left != NULL)
    {
        delete(this->left);
    }
}

Mul::Mul(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
    
double Mul::calculate() {
    return right->calculate() * left->calculate();
}

Mul::~Mul() {
    if (right != NULL)
    {
        delete(this->right);
    }
    
    if (left != NULL)
    {
        delete(this->left);
    }
}

Div::Div(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
    
double Div::calculate() {
    if (left->calculate() == 0)
    {
        throw "cannot divide by 0";    
    } else {
        return right->calculate() / left->calculate();
    }
}

Div::~Div() {
    if (right != NULL)
    {
        delete(this->right);
    }
    
    if (left != NULL)
    {
        delete(this->left);
    }
}

UPlus::UPlus(Expression* exp1) : UnaryOperator(exp) {
    this->exp = exp1;
}

double UPlus::calculate() {
    return exp->calculate();
}

UPlus::~UPlus() {
    if (exp != NULL)
    {
        delete(this->exp);
    }
}   

UMinus::UMinus(Expression* exp1) : UnaryOperator(exp) {
    this->exp = exp1;
}

double UMinus::calculate() {
    return -(exp->calculate());
}

UMinus::~UMinus() {
    if (exp != NULL)
    {
        delete(this->exp);
    }
}

Variable::Variable(string name, double value) {
    this->name = name;
    this->value = value;
}

Variable& Variable::operator++() {
    this->value = ++(this->value);
    return *this;
}

Variable& Variable::operator--() {
    this->value = --(this->value);
    return *this;
}

Variable& Variable::operator+=(double val) {
    this->value = this->value + val;
    return *this;
}

Variable& Variable::operator-=(double val) {
    this->value = this->value - val;
    return *this;
}

Variable& Variable::operator++(int num) {
    return ++*this;
}
Variable& Variable::operator--(int num) {
    return --*this;
}
double Variable::calculate() {
    return this->value;
}



double Value::calculate() {
    return this->val;
}

Expression* Interpreter::interpret(string tokens) {
    
    for (int i = 0; i < tokens.length(); i++)
    {
        if (isDigit(tokens[i]))
        {
            double num = toDouble(tokens[i]);
            double num2 = 0;

            while ((i+1) < tokens.length && isDigit(tokens[i+1]))
            {
                ++i;
                double temp = toDouble(tokens[i]);
                num = num * 10 + temp;
            }
            if (tokens[i + 1] == '.' && isDigit(tokens[i+2]))
            {
                ++i;
                int digitCounter = 0;
                while (isDigit(tokens[i+1]) && (i+1) < tokens.length)
                {
                    ++i;
                    digitCounter++;
                    double temp2 = toDouble(tokens[i]);
                    num2 = num2 * 10 + temp2;
                }
                
                for (int j = 0; j < digitCounter; j++)
                {
                    num2 /= 10;
                }
            }
            num = num + num2;
            output.push(new Value(num));
        } else if (isOperator(tokens[i]))
        {
            if ((i == 0 || tokens[i-1] == '(') && i+1 < tokens.length && isValidUnary(tokens[i], tokens[i+1]))
            {
                if (tokens[i] == '-')
                {
                    operations.push('#'); //Unary minus's sign (my choice).
                } else
                {
                    operations.push('@'); //Unary plus's sign (my choice).
                } 
            } else if (i != 0 && i+1 < tokens.length)
            {
                
            }
                 
            
        }
        
        
    }
    
}

bool isValidBinary(char prev, char op, char next) {
    if (!isOperator(prev) && !isOperator(next) && prev != '(')
    {
        if (op == '-' && (!isDigit(next) || next != '('))
        {
            return false;
        }
        
    }
    
}

bool isValidUnary(char op, char next) {
    if ((next == '(' || isDigit(next)) && (op == '-' || op == '+'))
    {
        return true;
    } else
    {
        return false;
    }
    
}

int precedenceOf(char op) {
    if (op == '-' || op == '+')
    {
        return 1;
    } else  //op == '*' or '/'
    {
        return 2;
    }
    
    
}

bool isOperator(char c) {
   if (c == '+' || c == '-' || c == '*' || c == '/')
   {
       return true;
   } else {
       return false;
   }
   
}

double toDouble(char c) {
    double d = c - '0';
    return d;
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
    
}

void Interpreter::setVariables(string vars) {

}
