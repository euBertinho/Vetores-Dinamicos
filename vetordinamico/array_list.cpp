#include "array_list.hpp"
#include <iostream>
using namespace std;

int main() {
  array_list lista;
  int x;
  for (int i = 0; i < 8; i++) {
    cin >> x;
    lista.push_back(x);
  }
  cout << lista.front() << "\n";
  cout << lista.back() << "\n";
  cout << lista.sum() << "\n";
  cout << lista.count(6) << "\n";
  cout << lista.find(5) << "\n";
  lista.push_front(9);

  for (int i = 0; i < 9; i++) {
    cout << lista.get_at(i) << "  ";
  }

  return 0;
}