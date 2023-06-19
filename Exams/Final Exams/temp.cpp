#include <iostream>
using namespace std;
class Item {
public:
	int cnt;
	Item() :cnt(0) {}
};
class Store {
public:
	Store() {  
		itm = new Item();
		cout << "itm = new Item() " << endl;
		cnt++;
		cout << "cnt: " << cnt << endl;
	}
	Store(const Store& p) {
		itm = new Item();
		cout << "itm = new Item() " << endl;
		itm->cnt = p.itm->cnt++;
		cnt++;
		cout << "cnt: " << cnt << endl;
	}
	Store& operator=(const Store& rhs) {

		if (this != &rhs) {
			delete itm;
			itm = new Item();
			cout << "itm = new Item() " << endl;
			itm->cnt = rhs.itm->cnt++;
		}

		return *this;
	}
	int getItem() {

		return itm->cnt;
	}
	static int getcnt() {

		return cnt;
	}
	~Store() {
		cnt--;
		cout << "cnt: " << cnt << endl;

		delete itm;
	}
private:
	Item* itm;
	static int cnt;
};
int Store::cnt = 0;
int main()
{
	Store p1, p2;
	p2 = p1;
	Store p3 = p2;
	cout << p1.getItem() + p2.getItem()
		+ p1.getcnt() + p2.getcnt() << endl;
	cout << "p1 item: " << p1.getItem() << endl;
	cout << "p2 item: " << p2.getItem() << endl;
	cout << "p1 count: " << p1.getcnt() << endl;
	cout << "p2 count: " << p2.getcnt() << endl;


	return 0;
}