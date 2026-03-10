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
    printIter("Elements    ", vd.begin());
    std::cout << "Find(4.2): " << (vd.Find(4.2) ? "yes" : "no") << "\n";
    vd.Delete(4.2);
    printIter("Delete(4.2) ", vd.begin());
    vd.DeleteAll();
    printIter("DeleteAll   ", vd.begin());

    // ===== Vector<std::string> =====
    std::cout << "\n===== Vector<string> =====\n";
    Vector<std::string> vs;
    vs.Add("banana"); vs.Add("apple"); vs.Add("cherry");
    printIter("Elements     ", vs.begin());
    std::cout << "Find(apple): " << (vs.Find("apple") ? "yes" : "no") << "\n";
    vs.Delete("apple");
    printIter("Delete(apple)", vs.begin());

    // ===== Stack<int> =====
    std::cout << "\n===== Stack<int> =====\n";
    Stack<int> si;
    si.Add(10); si.Add(20); si.Add(30); si.Add(40);
    printIter("Elements   ", si.begin());
    std::cout << "Find(20): " << (si.Find(20) ? "yes" : "no") << "\n";
    si.Delete(20);
    printIter("Delete(20) ", si.begin());
    si.DeleteAll();
    printIter("DeleteAll  ", si.begin());

    // ===== Tree<double> =====
    std::cout << "\n===== Tree<double> =====\n";
    //        5
    //       / \
    //      3   7
    //     / \ / \
    //    1  4 6  8
    Tree<double> td;
    td.Add(5.0); td.Add(3.0); td.Add(7.0);
    td.Add(1.0); td.Add(4.0); td.Add(6.0); td.Add(8.0);
    printIter("DFS in-order", td.beginDFS());   // 1 3 4 5 6 7 8
    printIter("BFS level   ", td.beginBFS());   // 5 3 7 1 4 6 8
    td.Delete(3.0);
    printIter("Delete(3.0) ", td.beginDFS());
    td.DeleteAll();
    printIter("DeleteAll   ", td.beginDFS());

    // ===== Tree<std::string> =====
    std::cout << "\n===== Tree<string> =====\n";
    Tree<std::string> ts;
    ts.Add("mango"); ts.Add("apple"); ts.Add("pear");
    ts.Add("banana"); ts.Add("orange");
    printIter("DFS in-order ", ts.beginDFS());  // алфавитный порядок
    printIter("BFS level    ", ts.beginBFS());
    std::cout << "Find(pear):  " << (ts.Find("pear")  ? "yes" : "no") << "\n";
    std::cout << "Find(grape): " << (ts.Find("grape") ? "yes" : "no") << "\n";

    return 0;
}
