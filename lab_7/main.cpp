#include <iostream>
#include <string>
#include "Vector.h"
#include "Stack.h"
#include "Tree.h"
#include "utils.h"

int main() {
  // ===== Vector<double> =====
  std::cout << "===== Vector<double> =====\n";
  Vector<double> vd;
  vd.Add(3.5); vd.Add(1.1); vd.Add(4.2); vd.Add(1.5); vd.Add(9.0);
  std::cout << "Elements    : " << vd.begin() << std::endl;
  std::cout << "Find(4.2): " << (vd.Find(4.2) ? "yes" : "no") << "\n";
  vd.Delete(4.2);
  std::cout << "Delete(4.2) : " << vd.begin() << std::endl;
  vd.DeleteAll();
  std::cout << "DeleteAll   : " << vd.begin() << std::endl;

  // ===== Vector<std::string> =====
  std::cout << "\n===== Vector<string> =====\n";
  Vector<std::string> vs;
  vs.Add("banana"); vs.Add("apple"); vs.Add("cherry");
  std::cout << "Elements     : " << vs.begin() << std::endl;
  std::cout << "Find(apple): " << (vs.Find("apple") ? "yes" : "no") << "\n";
  vs.Delete("apple");
  std::cout << "Delete(apple): " << vs.begin() << std::endl;

  // ===== Stack<int> =====
  std::cout << "\n===== Stack<int> =====\n";
  Stack<int> si;
  si.Add(10); si.Add(20); si.Add(30); si.Add(40);
  std::cout << "Elements   : " << si.begin() << std::endl;
  std::cout << "Find(20): " << (si.Find(20) ? "yes" : "no") << "\n";
  si.Delete(20);
  std::cout << "Delete(20) : " << si.begin() << std::endl;
  si.DeleteAll();
  std::cout << "DeleteAll  : " << si.begin() << std::endl;

  // ===== Tree<double> =====
  std::cout << "\n===== Tree<double> =====\n";

  Tree<double> td;
  td.Add(5.0); td.Add(3.0); td.Add(7.0);
  td.Add(1.0); td.Add(4.0); td.Add(6.0); td.Add(8.0);
  std::cout << "DFS in-order: " << td.beginDFS() << std::endl;
  std::cout << "BFS level   : " << td.beginBFS() << std::endl;
  td.Delete(3.0);
  std::cout << "Delete(3.0) : " << td.beginDFS() << std::endl;
  td.DeleteAll();
  std::cout << "DeleteAll   : " << td.beginDFS() << std::endl;

  // ===== Tree<std::string> =====
  std::cout << "\n===== Tree<string> =====\n";
  Tree<std::string> ts;
  ts.Add("mango"); ts.Add("apple"); ts.Add("pear");
  ts.Add("banana"); ts.Add("orange");
  std::cout << "DFS in-order : " << ts.beginDFS() << std::endl;
  std::cout << "BFS level    : " << ts.beginBFS() << std::endl;
  std::cout << "Find(pear):  " << (ts.Find("pear") ? "yes" : "no") << "\n";
  std::cout << "Find(grape): " << (ts.Find("grape") ? "yes" : "no") << "\n";

  return 0;
}
