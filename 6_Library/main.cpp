#include "Library.h"
#include <string.h>

int main(){
    Library lib("lib1", "kaveh ave", 8, 18, 1395, 10);
    cout << lib.isOpen(11) << endl;
    cout << lib.isOpen(20) << endl;
    Book *a = new Book("Boostan", 1390, Author("Ali Rezaei", true, "Ali@gmail.com"));
    Book *b = new Book("Fenjan dagh", 1396, Author("Shayan Hashemi", true, "Shayan@gmail.com"), 5);
    Book *c = new Book("Derakht", 1399, Author("Zahra Hatami", false, "Zahra@gmail.com"), 2);
    lib.addBook(a);
    lib.addBook(b);
    lib.addBook(c);
    cout << lib.isExistBook("Boostan") << endl;
    lib.printBooks();
    cout << lib.lendBook("Boostan") << endl;
    cout << lib.isExistBook("Boostan") << endl;
    cout << lib.returnBook("Boostan") << endl;
    cout << lib.isExistBook("Boostan") << endl;
}