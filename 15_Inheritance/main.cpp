#include <iostream>
#include "Multiple Inheritances.h"
#include "Hybrid Inheritance.h"
#include "Hierarchical Inheritance.h"
using namespace std;

int main(){
    Test obj;
    obj.a = 1;
    obj.b = 2;
    /////////////////
    HybridTest1 s;
    s.Game_name = "G1";
    s.city = "Esfahan";
    /////////////////
    HierarchicalTest1 p;
    p.name = "fname";
    p.rollNo = 1;
    p.rank_med = 8;
}