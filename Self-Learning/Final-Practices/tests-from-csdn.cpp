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
	/*�ֿ����
ĳ�ֿ⹲��ABCDE���ֻ��ÿ����Ҫ������������ͬ��ÿ�ֻ���ĵ��۲�ͬ��������ʾ���ɼ����������ֻ�����Ҫ���������������������ղֿ���֧�����ٻ��
�������� ���ﵥ��
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
	/*��дһ������ͳ�Ƴ��򡣴Ӽ��̻�ȡ8����ί��ֵİٷ��Ƴɼ���double���ͣ���ͳ��ƽ����ʱ��ȥ��һ����߷ֺ�һ����ͷ�����6��������ƽ��ֵ��Ϊ���÷֡��뽫��������������Ļ�ϣ���ʽΪ��ƽ���ɼ���XXX��*/
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
void ex4() {
	/*.��10��С����Χ��һȦ���ǹ�����ʦ˳�ηָ�ÿ��һ�������ǹ�����ʼֵΪż����Ȼ�������й������������С����ͬʱ���Լ����ǹ���һ����ұߵ��ˣ��ǹ�����Ϊ�������ˣ�����ʦ��Ҫһ���ǹ����ʾ������ٴε����󣬴���ǹ���һ���࣬��ÿ�˶��ٿ顣
	��������������һ�����𴫵��ǹ���һ�������ж������˵��ǹ��Ƿ���ȡ�

��Ȩ����������ΪCSDN�������·���PP����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_50469517/article/details/111329662		*/
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
void ex5() {
	/*����10���������˴��Կո�ָ������������Ժ����(Ҳ���ո�ָ�)��Ҫ��: 1.��������е�����,�����Ӵ�С���У� 2.Ȼ��������е�ż��,������С�������С�*/
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

void ex6() {
	/*��һ��ѧ����Student������ѧ���������ɼ���Ҫ��

��1�����һ����Ԫ����Compare()���Ƚ�����ѧ���ɼ��ĸߵ͡�
��2����main()�����ж���һ�������������ڴ洢����ѧ�������ݣ��������߷ֺ���ͷֵ�ѧ����*/

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

void ex7() {
	/*���һ��Rational�࣬���д����������㡣Ҫ��

��1����������������Ա������ʾ���Ӻͷ�ĸ��
��2������һ���������������ʼ���Ĺ��캯�������ṩ����ʱ�����캯��Ӧ�ṩĬ��ֵ��������ųɼ���ʽ�����������2/4��Ӧ�ڶ����д�ųɷ���1�ͷ�ĸ2����ʽ��
��3������������ṩpublic��Ա������
a������Rationalֵ��ӣ��������ɼ���ʽ��

b������Rationalֵ������������ɼ���ʽ��

c������Rationalֵ��ˣ��������ɼ���ʽ��

d������Rationalֵ������������ɼ���ʽ��

e����a/b��ʽ��ӡRationalֵ������aΪ���ӣ�bΪ��ĸ��

��4����д������������Rational�ࡣ*/

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