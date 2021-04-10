#include <iostream>
#include <string>
using namespace std;

bool isValidInput(string input, int& index);
int main() {
	string input;
	int n, i;
	int index = 0;
	int numbersIndex = 0;
	size_t idx=0;
	cin >> n;
	cin >> i;
	if (n < 0||i>n) {
		cout << "wrong input";
		exit(0);
	}
	double* numbers;
	numbers = new double[n];

	for (int j = 0; j < n; j++) {
		cin >> input;
		index = 0;
		if (isValidInput(input,index)) {
			numbers[numbersIndex] = stod(input, &idx);
			numbersIndex++;
		}
		else {
			cout << "wrong input" << endl;
		}
	}
	delete[] numbers;
	
}

bool isValidInput(string input,int& index) {
	int inputLen = input.length();
	int countAfterPoint = 0;
	while (input[index] != '.') {
		
		if (inputLen==index) {
		
			break;
		}
		index++;
	}
	if (input[index] == '.' && inputLen-1 == index)
	{
		return false;
	}
	while (index != inputLen-1) {
		countAfterPoint++;
		if (countAfterPoint>= 5) {
			return false;
		}
		
		index++;
	}
	return true;
}