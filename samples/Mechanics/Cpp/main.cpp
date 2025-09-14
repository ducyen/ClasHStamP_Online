#include <iostream>
#include <typeinfo>
#include <string>

class Context{
    int z;

    static struct Base{
        int x;
        void entry( Context* pThis ){

        }
    }base;

    static struct Derived : public Base{
        int y;
    }derived;

};

int main() {
    

    return 0;
}
