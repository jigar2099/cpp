#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
	char operation;
	float number1, number2;

	cout << "Select operation(+,-,*,/) : ";
	cin >> operation;

	cout << "Enter number 1:";
	cin >> number1;
	cout << "Enter number 2:";
	cin >> number2;

	switch (operation) {
		case '+':cout << number1 << " + " << number2 << " = " << number1 + number2;break;
		case '-':cout << number1 << " - " << number2 << " = " << number1 - number2; break;
		case '*':cout << number1 << " * " << number2 << " = " << number1 * number2; break;
		case '/':cout << number1 << " / " << number2 << " = " << number1 / number2; break;
		// If the operator is other than +, -, * or /, error message is shown
		default:cout << "Error! operator is not correct"; break;
	}





	return 0;
}