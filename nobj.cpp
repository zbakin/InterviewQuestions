// Implement a class with a member function 'int nobjs()' which returns the number of object
// of that class currently in existence. What assumptions have you made?

#include <iostream>

using std::cout;
using std::endl;

// Here, we assume that the class is instantiated only using MyClass() constructor
// and destroyed only in destructor.
// If the user would like to create an object via different means, e.g. copy contructor,
// then the user needs to update number_objs as well.
class MyClass
{
public:
    MyClass() {
        ++number_objs;
    }
    ~MyClass() {
        --number_objs;
    }

    static int nobjs() {
        return number_objs;
    }
private:
    static int number_objs;
};

// need to define static variable outside the class
int MyClass::number_objs = 0;

int main() {
    MyClass *obj1 = new MyClass();
    MyClass *obj2 = new MyClass();

    cout << "number of objects: " << obj1->nobjs() << endl;

    // delete objects
    delete obj2;

    cout << "number of objects after delete: " << obj1->nobjs() << endl;

    MyClass *obj3 = new MyClass();

    cout << "number of objects: " << obj3->nobjs() << endl;
    return 0;
}
