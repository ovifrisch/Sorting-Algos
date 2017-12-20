#include <iostream>
#include <vector>
using namespace std;

template<class T>
void merge(vector<T>& list, int leftStart, int leftEnd, int rightStart, int rightEnd) {
	int length = rightEnd - leftStart + 1;
	vector<T> temp;
	int left = leftStart;
	int right = rightStart;
	for (int i = 0; i < length; i++) {
		if (left > leftEnd) {
			temp.push_back(list[right++]);
		}
		else if (right > rightEnd) {
			temp.push_back(list[left++]);
		}
		else if (list[left] <= list[right]) {
			temp.push_back(list[left++]);
		}
		else {
			temp.push_back(list[right++]);
		}
	}

	for (int i = 0; i < length; i++) {
		list[leftStart++] = temp[i];
	}
}

template <class T>
void mergesort(vector<T>& list, int start, int end) {
	if (start >= end) return;
	int middle = (start + end) / 2;
	mergesort(list, start, middle);
	mergesort(list, middle + 1, end);
	merge(list, start, middle, middle + 1, end);
}

template <class T>
void printList(vector<T> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	vector<int> list = {5, 4, 3, 7, 9, 1, 2};
	vector<int> res;
	mergesort(list, 0, list.size());
	printList(list);
}
