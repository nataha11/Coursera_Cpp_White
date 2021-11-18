#include <vector>
#include <algorithm>

class FunctionPart {
public:
  FunctionPart(char new_operation, double new_value) {
    operation = new_operation;
    value = new_value;
  }
  double Apply(double src_val) const {
    if (operation == '+')
      return src_val + value;
    else if(operation == '-')
      return src_val - value;
    else if(operation == '*')
      return src_val * value;
    else if(operation == '/')
      return src_val / value;
    return src_val;
  }
  void Invert() {
    if (operation == '+')
      operation = '-';
    else if(operation == '-')
      operation = '+';
    else if(operation == '*')
      operation = '/';
    else if(operation == '/')
      operation = '*';
  }
private:
  char operation;
  double value;
};

class Function {
public:
  void AddPart(char operation, double value) {
    parts.push_back({operation, value});
  }
  double Apply(double value) const{
    for (const FunctionPart& part : parts) {
      value = part.Apply(value);
    }
    return value;
  }
  void Invert() {
    for(FunctionPart& part : parts) {
      part.Invert();
    }
    reverse(begin(parts), end(parts));
  }
private:
  vector<FunctionPart> parts;
};
