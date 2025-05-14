#pragma once
#include <string>

class Calculator {
public:
  void append(char c);               // add digit/operator to expression
  double evaluate();                 // compute & return result
  void clear();                      // reset expression
  const std::string& expression() const;  // peek current expression

private:
  std::string expr_;
};
