class Test1{
public:
    int a;
};

class Test2{
public:
    int b;
};

class Test3{
public:
    int c;
};


class Test : public Test1, public Test2, public Test3{
public:
    int d;
};