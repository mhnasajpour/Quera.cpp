#include <iostream>
using namespace std;

class HybridTest{
public:
    string Game_name;
};

class HybridTest1 : public HybridTest{
public:
    string city;
    string state;
    string pin;
};

class HybridTest2 : public HybridTest{
public:
    int height;
    int weight;
};

class HybridTest3 : public HybridTest2{
public:
    int rollNo;
    string name;
    string branch;
};