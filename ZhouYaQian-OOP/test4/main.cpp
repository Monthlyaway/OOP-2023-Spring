#include "Goods.h"
using namespace std;


int main()
{
    Stock s;
    s.purchase(Good("pen", 100));
    s.purchase(Good("mouse", 50));
    s.purchase(Good("notepad", 200));
    s.purchase(Good("pen", 50));
    cout << "Using member function: print" << endl;
    s.print();
    cout << endl;

    cout << "Using cout << s << endl" << endl;
    cout << s << endl;

    try{
        s.sell(Good("mouse", 50));
    }
    catch (domain_error e) {
        cout << e.what() << endl;
    }
    try{
        s.sell(Good("pen", 210));
    }
    catch (domain_error e) 
    {
        cout << e.what() << endl;
    }
    catch (invalid_argument i)
    {
        cout << i.what() << endl;
    }

    try {
        s.sell(Good("wine", 210));
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }
    catch (invalid_argument i)
    {
        cout << i.what() << endl;
    }

    cout << s << endl;
    return 0;
}

