class String{
private:
    char* str;
    int size;
    void setSize(int);
public:
    String();
    String(char* str);
    String(char* str, int size);
    ~String();

    void setStr(char*);
    char* getStr();
    int getSize();
    char* subStr(int index1, int index2);
    void append(char* temp);
    int findSubStr(char* temp);
    bool strCmp(char* temp);
};