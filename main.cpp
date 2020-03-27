//#include "Victim.hpp"
#include "Linear.hpp"
//#include <cstdio>
//#include <windows.h>
//using namespace Gameplay;
#include <iostream>

using namespace std;

// ��������������� �����
class Object
{
  public:
    Object() { cout << "Object::ctor()" << endl; }
   ~Object() { cout << "Object::dtor()" << endl; }
};

// ������� �����
class Base
{
  public:
    Base() { cout << "Base::ctor()" << endl; }
     virtual ~Base() { cout << "Base::dtor()" << endl; }
        void print() {}

};

// ����������� �����
class Derived: public Base
{
  public:
    Derived() { cout << "Derived::ctor()" << endl; }
   ~Derived() { cout << "Derived::dtor()" << endl; }
    Object  obj;
};

int main ()
{
    Derived *d = new Derived;
    Base *dp = d;
    delete dp;
    return 0;
}

