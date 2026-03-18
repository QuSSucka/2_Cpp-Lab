#include <iostream>
#include "Vector.h"
#include "Stack.h"
#include "Tree.h"
#include "utils.h"

int main() {
  // ===== Vector =====
  std::cout << "========== Vector ==========\n";
  Vector vec;
  vec.Add(3.5); vec.Add(1.1); vec.Add(4.2); vec.Add(1.5); vec.Add(9.0);
  std::cout << "Elements     : " << vec.begin() << std::endl;
  std::cout << "Find(4.2): " << (vec.Find(4.2) ? "yes" : "no") << "\n";
  std::cout << "Find(7.0): " << (vec.Find(7.0) ? "yes" : "no") << "\n";
  vec.Delete(4.2);
  std::cout << "Delete(4.2)  : " << vec.begin() << std::endl;
  vec.DeleteAll();
  std::cout << "DeleteAll    : " << vec.begin() << std::endl;

  // ===== Stack =====
  std::cout << "\n========== Stack ==========\n";
  Stack stk;
  stk.Add(10.0); stk.Add(20.0); stk.Add(30.0); stk.Add(40.0);
  std::cout << "Elements     : " << stk.begin() << std::endl;
  std::cout << "Find(20.0): " << (stk.Find(20.0) ? "yes" : "no") << "\n";
  stk.Delete(20.0);
  std::cout << "Delete(20.0) : " << stk.begin() << std::endl;
  stk.DeleteAll();
  std::cout << "DeleteAll    : " << stk.begin() << std::endl;

  // ===== Tree =====
  std::cout << "\n========== Tree ==========\n";
  Tree tree;
  tree.Add(5.0); tree.Add(3.0); tree.Add(7.0);
  tree.Add(1.0); tree.Add(4.0); tree.Add(6.0); tree.Add(8.0);

  std::cout << "DFS in-order : " << tree.beginDFS() << std::endl;
  std::cout << "BFS level    : " << tree.beginBFS() << std::endl;
  std::cout << "Find(4.0): " << (tree.Find(4.0) ? "yes" : "no") << "\n";
  std::cout << "Find(9.0): " << (tree.Find(9.0) ? "yes" : "no") << "\n";
  tree.Delete(3.0);
  std::cout << "Del(3) DFS   : " << tree.beginDFS() << std::endl;
  std::cout << "Del(3) BFS   : " << tree.beginBFS() << std::endl;
  tree.DeleteAll();
  std::cout << "DeleteAll DFS: " << tree.beginDFS() << std::endl;

  return 0;
}
