# Problem: Vehicle Rental System

You are tasked with designing a vehicle rental system that supports different types of vehicles such as cars, motorcycles, and bicycles. The system should allow customers to rent vehicles, calculate rental costs, and manage the inventory of available vehicles.

## Requirements:

1. Each vehicle should have the following attributes:
   1. Vehicle ID (unique identifier)
   2. Make and model
   3. Rental rate per day
   4. Each vehicle type should have its own specific attributes and behaviors:

2. Car:

   1. Number of door
   2. Fuel type (e.g., gasoline, diesel)
   3. Calculate rental cost based on the number of days rented

3. Motorcycle:

   1. Engine displacement (in cc)
   2. Calculate rental cost based on the number of days rented

4. Bicycle:

   1. Number of gears
   1. Calculate rental cost based on the number of hours rented

5. The system should provide the following functionality:

   1. Add a vehicle to the inventory

   1. Remove a vehicle from the inventory

   1. Rent a vehicle to a customer

   1. Calculate the rental cost for a specific vehicle and duration

   1. Display the list of available vehicles

   1. Display the list of rented vehicles

   1. Display the total revenue generated from rentals

## Design Considerations:

1. Use inheritance to create a base class called Vehicle and derived classes Car, Motorcycle, and Bicycle to represent the different vehicle types.

2. Include virtual functions in the base class for common operations such as calculating rental cost and displaying vehicle information. These functions should be overridden in the derived classes to provide specific implementations.

3. Use polymorphism to handle vehicle objects uniformly, regardless of their specific types. This allows for easier management and manipulation of vehicles in the system.

4. Use appropriate data structures (e.g., vectors, maps) to store the inventory of available vehicles and the list of rented vehicles.


Your task is to implement the classes and functions required to fulfill the given requirements. Consider how the classes can be structured, how to handle rentals and availability, and how to calculate rental costs based on the vehicle type and duration.

## Notes

1. When writing the print function, do not write `os << print() << endl` so frequently. It could raise error.

   ```c++
   ostream& print(ostream& os = cout) const  override {
       Vehicle::print(os);
       os << "Number of doors: " << _doors << endl;
       os << "Fuel type: " << _fuel << endl;
       return os;
   }
   ```

   `override ` should be the last specifier, after the `const`, so that the two function will be considered as inheritance. 

2. ```c++
   Vehicle(const string& model, const ID id, double rental_per_day) :
   _model(model), _id(id), _rental_per_day(rental_per_day), _days(0) {}
   
   Car(const string& model, const ID id, double rental_per_day, int doors, const string& fuel) : Vehicle(model, id, rental_per_day), _doors(doors), _fuel(fuel) {}
   ```

   The `Car` constructor inherit all of the `Vehicle` constructor, and adds something of its own. Remember to call the base class constructor.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

class Students;
class Rational;

void ex1(void) {
	/*仓库结算
某仓库共有ABCDE五种货物，每天需要补货的数量不同，每种货物的单价不同，如下所示。由键盘输入五种货物需要补货的数量，请计算出当日仓库需支付多少货款。
货物名称 货物单价
A 10
B 5
C 3
D 20
E 13
*/
	map<string, int> repo;
	string good;
	int count;
	while (cin >> good >> count) {
		repo[good] += count;
	}
	for (const pair<string, int>& pair : repo) {
		std::cout << pair.first << " " << pair.second << endl;
	}

}
void ex2(void) {
	/*编写一个评分统计程序。从键盘获取8个评委打分的百分制成绩（double类型），统计平均分时，去掉一个最高分和一个最低分其余6个分数的平均值即为最后得分。请将这个分数输出到屏幕上，格式为：平均成绩是XXX。*/
	vector<double> scores;
	double tmp;
	while (cin >> tmp) {
		scores.push_back(tmp);
	}
	sort(scores.begin(), scores.end());
	double total = 0;
	for_each(scores.begin() + 1, scores.end() - 1, [&total](double num) {
		total += num;
		});
	//total = accumulate(scores.begin() + 1, scores.end() - 1, 0.0f);
	std::cout << "Average: " << total / (scores.size() - 2) << endl;
}
void ex3(void) {
	/*Fibonacci sequence*/
	vector<int> fibo{ 1,1 };
	int size = 15;
	/*for (int ix = 3; ix <= size; ix++) {
		fibo.push_back(fibo.at(ix - 3) + fibo.at(ix - 2));
	}*/
	int a = 1, b = 1;
	for (int ix = 3, c; ix <= size; ix++) {
		c = a + b;
		fibo.push_back(c);
		a = b;
		b = c;
	}
	for_each(fibo.begin(), fibo.end(), [](int num) { std::cout << num << " "; });
}
```
```c++
void ex4() {
	/*.有10个小朋友围成一圈分糖果，老师顺次分给每人一定数量糖果（初始值为偶数）然后按照下列规则调整，所有小朋友同时把自己的糖果分一半给右边的人，糖果数变为奇数的人，向老师补要一块糖果，问经过多少次调整后，大家糖果数一样多，且每人多少块。
	建立两个函数，一个负责传递糖果，一个负责判断所有人的糖果是否相等。

版权声明：本文为CSDN博主「下饭的PP」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_50469517/article/details/111329662		*/
	vector<int> candies{ 2,4,6,5,12,5,4,8,4,2 };

	//// Open the log file in truncation mode (wipeout)
	//std::ofstream logfile("./ex-4-log.txt", std::ios::trunc);

	//// Redirect std::cout to the log file
	//// store the original buffer pointer
	//std::streambuf* std::coutBuffer = std::cout.rdbuf();
	//std::cout.rdbuf(logfile.rdbuf());

	auto pass = [](vector<int>& candies) {
		int last = candies[candies.size() - 1];
		for (int ix = 0; ix < candies.size() - 1; ix++) {
			candies[ix + 1] += candies[ix] / 2;
		}
		candies[0] += last / 2;
		transform(candies.begin(), candies.end(), candies.begin(), [](auto& num) {
			if (num % 2 != 0)
				num++;
			return num;
			});
		/* the lambda function within transform is intended to modify each element in the candies vector. However, it should return the modified value rather than performing the modification directly. The return value will be used to update the corresponding element in the destination range.*/
	};
	auto is_equal = [](const vector<int>& candies) -> bool {
		auto first = candies.at(0);
		for (const auto& u : candies) {
			if (u != first)
				return false;
		}
		return true;
	};

	int round = 0;
	while (!is_equal(candies)) {
		std::cout << "Round: " << round << endl;
		pass(candies);
		std::for_each(candies.begin(), candies.end(), [](const auto& u) {
			std::cout << u << " ";
			});
		std::cout << endl;
		round++;
	}

	//// Restore std::cout back to the standard output
	//std::cout.rdbuf(std::coutBuffer);

	//// Close the log file
	//logfile.close();
}

```

```c++
void ex5() {
	/*输入10个整数，彼此以空格分隔。重新排序以后输出(也按空格分隔)，要求: 1.先输出其中的奇数,并按从大到小排列； 2.然后输出其中的偶数,并按从小到大排列。*/
	vector<int> ivec;
	int input;
	std::cout << "Input some integers: ";
	while (cin >> input)
		ivec.push_back(input);

	vector<int> oddNumbers;
	copy_if(ivec.begin(), ivec.end(), back_inserter(oddNumbers), [](auto num) {
		return num % 2 != 0;
		});
	ivec.erase(remove_if(ivec.begin(), ivec.end(), [](auto num) {
		return num % 2 != 0;
		}), ivec.end());
	vector<int> evenNumbers(ivec);

	sort(oddNumbers.begin(), oddNumbers.end(), std::greater<int>());
	sort(evenNumbers.begin(), evenNumbers.end(), std::less<int>());

	std::cout << "Odd Numbers(descending order): ";
	for_each(oddNumbers.begin(), oddNumbers.end(), [](auto u) {std::cout << u << " "; });
	std::cout << "\nEven Numbers(ascending order): ";
	for_each(evenNumbers.begin(), evenNumbers.end(), [](auto u) {std::cout << u << " "; });

}
```

```c++
class Student {
public:
	friend bool Compare(const Student& lhs, const Student& rhs);

	Student(const string& name, const double& score) : _name(name), _score(score)
	{}
	string name(void) const { return _name; }
	double score(void) const { return _score; }
	ostream& print(ostream& os = std::cout) const {
		os << _name << ": " << _score;
		return os;
	}
	friend ostream& operator<<(ostream& os, const Student& rhs) {
		rhs.print(os);
		return os;
	}

private:
	string _name;
	double _score;
};

bool Compare(const Student& lhs, const Student& rhs) {
	return lhs._score < rhs._score;
}
```

```c++

void ex6() {
	/*有一个学生类Student，包括学生姓名、成绩，要求：

（1）设计一个友元函数Compare()，比较两个学生成绩的高低。
（2）在main()函数中定义一个对象数组用于存储输入学生的数据，并求出最高分和最低分的学生。*/

	vector<Student> stuvec;
	stuvec.push_back(Student("Lily Aldrin", 90));
	stuvec.push_back(Student("Ted Mosby", 80));
	stuvec.push_back(Student("Robin Whatever", 70));
	stuvec.push_back(Student("Marshall Eriksen", 60));
	stuvec.push_back(Student("Barney Stinson", 520));


	sort(stuvec.begin(), stuvec.end(), Compare);
	std::cout << "Highest grade: " << stuvec[stuvec.size() - 1] << endl;
	std::cout << "Lowest grade: " << stuvec[0] << endl;
}

```


```c++

class Rational {
public:
	Rational(int numerator = 0, int denominator = 1) : _numerator(numerator), _denominator(denominator) {
		if (_denominator == 0) {
			throw std::invalid_argument("Rational::Rational() denominator cannot be 0");
		}
		simplify();
	}

	int numerator(void) const {
		return _numerator;
	}
	int denominator(void) const {
		return _denominator;
	}

	Rational operator+(const Rational& rhs) const {
		Rational result;
		result._denominator = _denominator * rhs._denominator;
		result._numerator = _numerator * rhs._denominator + _denominator * rhs._numerator;
		result.simplify();
		return result;
	}
	Rational operator-(const Rational& rhs) const {
		Rational result;
		result._denominator = _denominator * rhs._denominator;
		result._numerator = _numerator * rhs._denominator - _denominator * rhs._numerator;
		result.simplify();
		return result;
	}
	Rational operator*(const Rational& rhs) const {
		Rational result;
		result._denominator = _denominator * rhs._denominator;
		result._numerator = _numerator * rhs._numerator;
		result.simplify();
		return result;
	}
	Rational operator/(const Rational& rhs) const {
		Rational result;
		result._denominator = _denominator * rhs._numerator;
		result._numerator = _numerator * rhs._denominator;
		result.simplify();
		return result;
	}

```

```c++
	ostream& print(ostream& os = std::cout) const {
		std::string numeratorStr = std::to_string(_numerator);
		std::string denominatorStr = std::to_string(_denominator);

		int lineLength = std::max(numeratorStr.length(), denominatorStr.length()) + 2;

		os << numeratorStr << std::endl;
		os << std::string(lineLength, '-') << std::endl;
		os << denominatorStr << std::endl;
		return os;
	}

	friend ostream& operator<<(ostream& os, const Rational& rhs) {
		rhs.print();
		return os;
	}
private:
	int _numerator;
	int _denominator;

	int gcd(int a, int b) const  // the greates common divisor
	{
		int max = std::max(a, b);
		int min = a + b - max;
		if (min == 0) {
			return 1;
		}
		while (max % min != 0) {
			max = max % min;
			std::swap(max, min);
		}
		std::cout << "GCD of " << a << " and " << b << " is " << min << endl;
		return min;
	}
	void simplify() {
		int subtract = gcd(_denominator, _numerator);
		_numerator = _numerator / subtract;
		_denominator = _denominator / subtract;
	}
};
```

```c++

void ex7() {
	/*设计一个Rational类，进行带分数的运算。要求：

（1）包含两个整数成员变量表示分子和分母。
（2）包含一个对所声明对象初始化的构造函数。不提供参数时，构造函数应提供默认值。分数存放成简化形式，例如分数“2/4”应在对象中存放成分子1和分母2的形式。
（3）对下列情况提供public成员函数：
a）两个Rational值相加，结果保存成简化形式。

b）两个Rational值相减，结果保存成简化形式。

c）两个Rational值相乘，结果保存成简化形式。

d）两个Rational值相除，结果保存成简化形式。

e）按a/b形式打印Rational值，其中a为分子，b为分母。

（4）编写主函数，测试Rational类。*/

	Rational a(3, 4);
	std::cout << "a:\n" << a;
	Rational b(12, 15);
	std::cout << "b:\n" << b;
	std::cout << a + b;
	std::cout << a - b;
	std::cout << a * b;
	std::cout << a / b;
}

int main(void)
{
	//ex1();
	//ex2();
	//ex3();
	ex4();
	//ex5();
	//ex6();
	//ex7();

	return 0;
}
```



