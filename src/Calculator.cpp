#include "Calculator.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

// determine operator precedence
static int prec(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// apply a single op to two values
static double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

void Calculator::append(char c)
{
    expr_.push_back(c);
}

void Calculator::clear()
{
    expr_.clear();
}

const std::string &Calculator::expression() const
{
    return expr_;
}

double Calculator::evaluate()
{
    std::stack<double> values;
    std::stack<char> ops;
    for (size_t i = 0; i < expr_.size(); ++i)
    {
        char ch = expr_[i];
        if (std::isspace(ch))
            continue;

        // number (possibly with decimal point)
        if (std::isdigit(ch) || ch == '.')
        {
            std::stringstream ss;
            while (i < expr_.size() && (std::isdigit(expr_[i]) || expr_[i] == '.'))
            {
                ss << expr_[i++];
            }
            double v;
            ss >> v;
            values.push(v);
            --i; // we went one char too far
        }
        // left parenthesis
        else if (ch == '(')
        {
            ops.push(ch);
        }
        // right parenthesis: resolve until matching '('
        else if (ch == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(a, b, op));
            }
            if (!ops.empty())
                ops.pop(); // pop '('
        }
        // operator
        else
        {
            while (!ops.empty() && prec(ops.top()) >= prec(ch))
            {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(ch);
        }
    }
    // finish remaining ops
    while (!ops.empty())
    {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(a, b, op));
    }
    if (values.empty())
        return 0.0;
    return values.top();
}
