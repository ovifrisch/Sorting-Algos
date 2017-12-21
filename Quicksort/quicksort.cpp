#include <vector>
#include <iostream>
using namespace std;

template <class Comparable>
void quicksort(vector<Comparable>& list, int left, int right) {
	int start = left;
	if (right <= left) return;

	Comparable pivot = list[left];
	vector<Comparable> newList;

	for (int i = left + 1; i <= right; i++) {
		if (list[i] <= pivot) {
			newList.push_back(list[i]);
		}
	}

	int posPivot = left + newList.size();
	newList.push_back(pivot);

	for (int i = left + 1; i <= right; i++) {
		if (list[i] > pivot) {
			newList.push_back(list[i]);
		}
	}

	for (int i = 0; i < newList.size(); i++) {
		list[start++] = newList[i];
	}

	quicksort(list, left, posPivot - 1);
	quicksort(list, posPivot + 1, right);
}


template <class T>
void print(vector<T> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " " ;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	vector<int> list = {5, 9, 3, 7, 4, 1, 2, 13, 55};
	quicksort(list, 0, list.size() - 1);
	print(list);
}

