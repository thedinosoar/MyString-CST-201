//Written by Keegan McGonigle
#include <string>
#include <iostream>
#pragma once

class Streng
{
private:
	char* arr;
	int curr_Length;
	int capacity;

	//runtime analysis: n steps
	void ensureCapacity() {
		char* temp = new char[capacity *= 2];

		for (int i = 0; i < curr_Length; i++) {
			temp[i] = arr[i];
		}

		delete arr;
		arr = temp;
	}

	bool isFull() {
		if (curr_Length == capacity) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void set(int i, int c) {
			arr[i] = char(c);
	}

public:
	
	//runtime analysis: 3 steps
	Streng() {
		arr = NULL;
		curr_Length = 0;
		capacity = 0;
	}

	//runtime analysis: 3 steps
	Streng(int size) {
		arr = new char[size];
		curr_Length = size;
		capacity = size;
	}

	//runtime analysis: 3+n steps
	Streng(std::string input) {
		curr_Length = input.size();
		capacity = curr_Length * 2;
		arr = new char[capacity];

		for (int i = 0; i < curr_Length; i++) {
			arr[i] = input[i];
		}
	}

	//runtime analysis: 3+n steps
	Streng(Streng *input) {
		curr_Length = input->curr_Length;
		capacity = curr_Length * 2;
		arr = new char[capacity];

		for (int i = 0; i < curr_Length; i++) {
			arr[i] = input->arr[i];
		}
	}

	//runtime analysis: 1+2n
	Streng concat(std::string input) {
		Streng output = new Streng(this);
		output.add(input);
		return output;
	}

	//runtime analysis: 1+2n
	Streng concat(Streng input) {
		Streng output = new Streng(this);
		output.add(input);
		return output;
	}

	//runtime analysis: 3+n steps
	void setStreng(std::string input) {
		curr_Length = input.size();
		capacity = curr_Length * 2;
		arr = new char[capacity];

		for (int i = 0; i < curr_Length; i++) {
			arr[i] = input[i];
		}
	}

	//runtime analysis: 2n steps
	void add(std::string input) {

		//checks to see if it needs to expand the array
		while ((curr_Length + input.size()) > capacity) {
			ensureCapacity();
		}

		//adds the new text to the end of the array
		for (int i = curr_Length; i < (curr_Length + input.size()); i++) {
			arr[i] = input[i-curr_Length];
		}

		curr_Length += input.size();
	}

	//runtime analysis: 2n steps
	void add(Streng input) {

		//checks to see if it needs to expand the array
		while ((curr_Length + input.getLength()) > capacity) {
			ensureCapacity();
		}

		//the new text array
		char *newArr = input.getArr();

		//adds the new text to the end of the array
		for (int i = curr_Length; i < (curr_Length + input.getLength()); i++) {
			arr[i] = newArr[i - curr_Length];
		}

		curr_Length += input.getLength();
	}

	//runtime analysis: n steps
	void print() {
		for (int i = 0; i < curr_Length; i++) {
			std::cout << arr[i];
		}
	}

	//runtime analysis: n steps
	friend std::ostream& operator<<(std::ostream& os, const Streng& st) {
		//os << st.arr;

		for (int i = 0; i < st.curr_Length; i++) {
			os << st.arr[i];
		}

		return os;
	}

	//runtime analysis: 1 step
	char *getArr() {
		return arr;
	}

	//runtime analysis: 1 step
	int getCapacity() {
		return capacity;
	}

	//runtime analysis: 1 step
	int getLength() {
		return curr_Length;
	}

	//runtime analysis: 1 step
	char get(int i) {
		try {
			return arr[i];
		} 
		catch (std::exception) {
			return NULL;
			//return arr[i%capacity];
		}
	}

	//runtime analysis: n steps (worst case), 1 step best case
	bool operator==(Streng compare) {
		if (compare.getLength() != curr_Length) {
			return false;
		}
		else {
			for (int i = 0; i < curr_Length; i++) {
				if (compare.get(i) != arr[i]) {
					return false;
				}
			}
			return true;
		}
		
	}

	//runtime analysis: n steps (worst case), 1 step best case
	bool operator!=(Streng compare) {
		if (compare.getLength() != curr_Length) {
			return true;
		}
		else {
			for (int i = 0; i < curr_Length; i++) {
				if (compare.get(i) != arr[i]) {
					return true;
				}
			}
			return false;
		}

	}

	//runtime analysis: 1 step
	bool operator>(Streng compare) {
		if (arr[0] > compare.get(0)) {
			return true;
		}
		else {
			return false;
		}
	}

	//runtime analysis: 1 step
	bool operator<(Streng compare) {		
		if (arr[0] < compare.get(0)) {
			return true;
		}
		else {
			return false;
		}
	}

	//runtime analysis: n steps worst case
	Streng toUpper() {
		Streng upperStreng(this);
		for (int i = 0; i < curr_Length; i++) {

			if ((arr[i] > 96) && (arr[i] < 123)) {
				upperStreng.set(i, (upperStreng.get(i) - 32));
			}
		}
		return upperStreng;
	}

	//runtime analysis: n steps worst case
	Streng toLower() {
		Streng lowerStreng(this);
		for (int i = 0; i < curr_Length; i++) {

			if ((arr[i] > 64) && (arr[i] < 91)) {
				lowerStreng.set(i, (lowerStreng.get(i) + 32));
			}
		}
		return lowerStreng;
	}

	//runtime analysis: length(n)-m steps
	Streng subString(int m) {
		if (m > curr_Length) {
			return new Streng();
		}
		Streng sub(curr_Length-m);

		for (int i = m; i < curr_Length; i++) {
			sub.set(i - m, arr[i]);
		}

		return sub;
	}

	//runtime analysis: last index(n)-m steps
	Streng subString(int m, int n) {
		if (n > curr_Length) {
			n = curr_Length;
		}
		if (m > curr_Length) {
			return new Streng();
		}
		Streng sub((n-m));

		for (int i = m; i < (n); i++) {
			sub.set(i - m, arr[i]);
		}

		return sub;
	}

	//runtime analysis: n steps(worst case)
	int indexOf(char j) {
		for (int i = 0; i < curr_Length; i++) {
			if (arr[i] == j) {
				return i;
			}
		}
		return -1;
	}

	//runtime analysis: n steps (worst case)
	int lastIndexOf(char j) {
		for (int i = curr_Length-1; i > -1; i--) {
			if (arr[i] == j) {
				return i;
			}
		}
		return -1;
	}

};

