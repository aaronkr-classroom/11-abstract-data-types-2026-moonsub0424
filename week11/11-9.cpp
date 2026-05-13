// 11-9.cpp
#include <iostream>
#include <ctime>
#include "vec.h"

using namespace std;

int main(void) {

	const Vec<int>::size_type count = 100000;

	Vec<int> v1, v2;

	// 메모리 확보하는 시간을 세다.
	double begin = clock();

	for (Vec<int>::size_type i = 0; i < count; ++i) {
		v1.push_back(i);
	}

	double end = clock();

	cout << "메모리에서 " << count
		<< "개의 정수를 확보하는 시간은 : "
		<< (end - begin) / CLOCKS_PER_SEC
		<< "초" << endl;

	// 하나씩 세다
	begin = clock();
	for (Vec<int>::size_type i = 0; i < count; ++i) {
		v2.push_back_grow_once(i);
	}

	end = clock();
	cout << "한 개씩의 메모리에서 " << count
		<< "개의 정수를 확보하는 시간은 : "
		<< (end - begin) / CLOCKS_PER_SEC
		<< "초" << endl;

	return 0;
}
