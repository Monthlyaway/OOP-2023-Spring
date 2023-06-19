#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//template<typename iterator>
//void Rotate(iterator begin, iterator mid, iterator end) {
//	size_t len = mid - begin;
//	for (auto out = mid; out < end; out++) {
//		for (auto in = out - len; in < out; in++) {
//			auto temp = *in;
//			*in = *out;
//			*out = temp;
//		}
//	}
//}

template<typename iterator>
void Rotate(iterator begin, iterator mid, iterator end) {
	using valueType = typename std::iterator_traits<iterator>::value_type;
	vector<valueType> vtemp(mid, end);
	for (auto iter = begin; iter < mid; iter++) {
		vtemp.push_back(*iter);
	}
	for (auto iter = begin; iter < end; iter++) {
		*iter = vtemp.at(iter - begin);
	}

}

struct candidate
{
	string _id;
	int _score;
};

class candidates {
public:
	void readinfo(istream& is) {
		string id;
		int score;
		while (is >> id >> score) {
			candidate* input = new candidate;
			input->_id = id;
			input->_score = score;
			_candidates.push_back(input);
		}
		cin.clear();
	}
	void output(ostream& os) const {
		for (int ix = 0; ix < _passPeople; ix++) {
			os << _candidates[ix]->_id << " " << _candidates[ix]->_score << endl;
		}
	}
	void sort_by_score_ID() {
		sort(_candidates.begin(), _candidates.end(), [](candidate* lhs, candidate* rhs) {
			return lhs->_id < rhs->_id;
			});
		sort(_candidates.begin(), _candidates.end(), [](candidate* lhs, candidate* rhs) {
			return lhs->_score > rhs->_score;
			});
	}
	void calculate(int numberOfRecruit) {
		_passPeople = numberOfRecruit * 1.5;
		_passScore = _candidates[_passPeople - 1]->_score;
		cout << "mps: " << _passScore << endl;
		for (int ix = _passPeople; ix < _candidates.size(); ix++) {
			if (_candidates[ix]->_score == _passScore) {
				_passPeople++;
			}
		}
		cout << "cnt: " << _passPeople << endl;

	}
	int get_mps() const {
		return _passScore;
	}
	int get_num() const {
		return _passPeople;
	}
private:
	vector<candidate*> _candidates;
	int _passScore;
	int _passPeople;
};

void testRotate(void) {
	vector<int> v;
	for (int i = 1; i < 10; ++i)
		v.push_back(i);
	Rotate(v.begin(), v.begin() + 3, v.end());
	cout << "v contains:";
	vector<int>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
}

void testCandidates(void) {
	candidates cs;
	cout << "Enter candidates' info: " << endl;
	cs.readinfo(cin);
	cs.sort_by_score_ID();
	cs.output(cout);

	cout << "Enter the number of summer camps to be recruited: ";
	int n;
	cin >> n;
	cs.calculate(n);
	cout << "The minimum passing score: " << cs.get_mps() << endl;
	cout << "Number of interviewees: " << cs.get_num() << endl;
	cout << "Info of the interviewees: " << endl;
	cs.output(cout);
}

int main() {
	//testRotate();	
	testCandidates();
	return 0;
}
