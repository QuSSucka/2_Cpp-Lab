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
  printIter("Elements     ", vec.begin());
  std::cout << "Find(4.2): " << (vec.Find(4.2) ? "yes" : "no") << "\n";
  std::cout << "Find(7.0): " << (vec.Find(7.0) ? "yes" : "no") << "\n";
  vec.Delete(4.2);
  printIter("Delete(4.2)  ", vec.begin());
  vec.DeleteAll();
  printIter("DeleteAll    ", vec.begin());

  // ===== Stack =====
  std::cout << "\n========== Stack ==========\n";
  Stack stk;
  stk.Add(10.0); stk.Add(20.0); stk.Add(30.0); stk.Add(40.0);
  printIter("Elements     ", stk.begin());
  std::cout << "Find(20.0): " << (stk.Find(20.0) ? "yes" : "no") << "\n";
  stk.Delete(20.0);
  printIter("Delete(20.0) ", stk.begin());
  stk.DeleteAll();
  printIter("DeleteAll    ", stk.begin());

  // ===== Tree =====
  std::cout << "\n========== Tree ==========\n";
  //        5
  //       / \
    //      3   7
    //     / \ / \
    //    1  4 6  8
  Tree tree;
  tree.Add(5.0); tree.Add(3.0); tree.Add(7.0);
  tree.Add(1.0); tree.Add(4.0); tree.Add(6.0); tree.Add(8.0);

  printIter("DFS in-order ", tree.beginDFS());  // 1 3 4 5 6 7 8
  printIter("BFS level    ", tree.beginBFS());  // 5 3 7 1 4 6 8
  std::cout << "Find(4.0): " << (tree.Find(4.0) ? "yes" : "no") << "\n";
  std::cout << "Find(9.0): " << (tree.Find(9.0) ? "yes" : "no") << "\n";
  tree.Delete(3.0);
  printIter("Del(3) DFS   ", tree.beginDFS());
  printIter("Del(3) BFS   ", tree.beginBFS());
  tree.DeleteAll();
  printIter("DeleteAll DFS", tree.beginDFS());

  return 0;
}
