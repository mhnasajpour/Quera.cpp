#include <iostream>
using namespace std;

class HierarchicalTest{
public:
    string name;
    int rollNo;
};

class HierarchicalTest1 : public HierarchicalTest{
public:
    int rank_med;
};

class HierarchicalTest2 : public HierarchicalTest{
public:
    int rank_engg;
};

class HierarchicalTest3 : public HierarchicalTest{
public:
    int rank_biotech;
};