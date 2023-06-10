#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int foo(vector<string>& tokens)
{
	stack<float> st;

	for (int ix = 0; ix < tokens.size(); ix++)
	{
		if (tokens[ix] == "+" || tokens[ix] == "-" ||
			tokens[ix] == "*" || tokens[ix] == "/")
		{
			float right_operand = st.top();
			st.pop();
			float left_operand = st.top();
			st.pop();
			float result;

			if (tokens[ix] == "+")
				result = left_operand + right_operand;
			else if (tokens[ix] == "-")
				result = left_operand - right_operand;
			else if (tokens[ix] == "*")
				result = left_operand * right_operand;
			else if (tokens[ix] == "/")
				result = left_operand / right_operand;
			else
			{
				cerr << "Operator not recognized" << endl;
				exit(EXIT_FAILURE);
			}

			st.push(result);
		}
		else
		{
			cout << tokens[ix] << endl;
			st.push(stof(tokens[ix]));
		}
	}
	return st.top();

}

std::vector<string> split(const std::string& s)
{
	vector<string> tokens;
	char delimeter = ' ';
	string  stp;
	int ix = 0;
	while (ix < s.size()) {
		if (s.at(ix) == delimeter) {
			if (!stp.empty())
				tokens.push_back(stp);
			stp.clear();
		}
		else {
			stp.append(1, s.at(ix));
		}
		ix++;
	}
	tokens.push_back(stp);

	return tokens;
}


int main(void)
{
	string input = "35.0 24.0 + 12.0 11.0 + *";
	vector<string>tokens = split(input);
	cout << "Result is " << foo(tokens) << endl;

	return 0;
}

