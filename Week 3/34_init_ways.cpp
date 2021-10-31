//#include <iostream>
#include <vector>

//using namespace std;

// class Incognizable {
// public:
//     Incognizable() {}
//     Incognizable(const vector<int>& n) {
//         numbers = n;
//     }
// private:
//     vector<int> numbers;
// };

typedef vector<int> Incognizable; //lol it worked

struct Incognizable {
  int x = 0;
  int y = 0;
}; //but that's the answer

// int main() {
//     Incognizable a;
//     Incognizable b = {};
//     Incognizable c = {0};
//     Incognizable d = {0, 1};
//     return 0;
// }