#pragma warning(disable: 4786)
#include <iostream>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
using namespace std;

int main()
{
  vector<myShape*> sh;
  sh.push_back(new myRectangle(3,4));
  sh.push_back(new myRectangle(2,5));
  sh.push_back(new myCircle(1));
  sh.push_back(new myCircle(10));
    
    for(vector<myShape*>::const_iterator it=sh.begin();it!=sh.end();it++){
        cout << **it;
        delete *it;
    }
  return 0;
}
