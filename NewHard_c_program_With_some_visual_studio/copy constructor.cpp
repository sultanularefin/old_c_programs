//listing 7
/* Copy constructor invoked when passing an object
   to a function. */

#include <iostream>
using namespace std;

class MyClass {
  int val;
  int copynumber;
public:
  // Normal constructor.
  MyClass(int i) {
    val = i;
    copynumber = 0;
    cout << "Inside normal constructor\n";
  }

  // Copy constructor
  MyClass(const MyClass &o) {
    val = o.val;
    copynumber = o.copynumber + 1;
    cout << "Inside copy constructor.\n";
  }

  ~MyClass() {
     if(copynumber == 0)
       cout << "Destructing original.\n";
     else
       cout << "Destructing copy " <<
                copynumber << "\n";
  }

  int getval() { return val; }
};

MyClass display(MyClass ob)
{
  cout << ob.getval() << '\n';
  return ob;
}
/*
MyClass mycl_return(MyClass ob)
{
    return ob;
}
*/
int main()
{
  MyClass a(10);

  display(a);

  //mycl_return(a);

  return 0;
}
