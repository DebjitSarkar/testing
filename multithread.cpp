#include <iostream>
#include <thread>

using namespace std;


void intense_math(double number, double number2) {
	cout << "INPUT: " << number << endl;
	while(number < 1000)
		number = number * number2;

	cout << "GOT A NUMBER: " << number << endl;
}

int main() {
	// cout << std::thread::hardware_concurrency() << endl; // 8 on CAEN

	thread t1(intense_math, 5, 2);
	thread t2(intense_math, 100, 3);

	cout << "Thread t1 running" << endl;

	t1.join();

	cout << "Done running t1" << endl;

	t2.join();
}
