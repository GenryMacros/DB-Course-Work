#pragma once

template <class T>
class list {

	class node {
	public:
		node() = default;
		node* next = nullptr;
		T data;
	};
public:
	list() {
		first = nullptr;
		last = nullptr;
		length = 0;
	}

	~list() = default;
	void add(T newElem) {
		if (!first) {
			first = new node;
			first->data = newElem;
			first->next = new node;
			last = first->next;
			length++;
			return;
		}
		last->data = newElem;
		last->next = new node;
		last = last->next;
		length++;

	}
	int getLength() {
		return length;
	}
	void deleteByValue(T value) {
		if (!length) {
			return;
		}
		node* pointer = first;
		node* pointerBack = nullptr;
		while (pointer) {
			if (pointer->data == value) {
				if (!pointerBack) {
					first = pointer->next;
					delete pointer;
					length--;
					return;
				}
				pointerBack->next = pointer->next;
				delete pointer;
				length--;
				return;
			}
			pointerBack = pointer;
			pointer = pointer->next;
		}
		std::cout << "ERROR:There is no such element" << std::endl;
	}
	void deleteByIndex(const int index) {
		int counter = 0;
		node* pointer = first;
		node* pointerBack = nullptr;
		while (pointer && counter < length) {
			if (counter == index) {
				if (!pointerBack) {
					first = pointer->next;
					delete pointer;
					length--;
					return;
				}
				pointerBack->next = pointer->next;
				if (!pointer->next)
					last = pointerBack;
				delete pointer;
				length--;
				return;

			}
			counter++;
			pointerBack = pointer;
			pointer = pointer->next;
		}
		throw "OUT OF RANGE";
	}
	void deleteByIndexPointerData(const int index) {
		int counter = 0;
		node* pointer = first;
		node* pointerBack = nullptr;
		while (pointer && counter < length) {
			if (counter == index) {
				if (!pointerBack) {
					first = pointer->next;
					delete pointer->data;
					delete pointer;
					length--;
					return;
				}
				pointerBack->next = pointer->next;
				if (!pointer->next)
					last = pointerBack;
				delete pointer->data;
				delete pointer;
				length--;
				return;

			}
			counter++;
			pointerBack = pointer;
			pointer = pointer->next;
		}
		throw "OUT OF RANGE";
	}
	void clear() {
	    while(length!=0) {
			deleteByIndexPointerData(length - 1);
		}
	}
	T& operator[](const int index) {
		int counter = 0;
		node* pointer = first;
		while (pointer && counter < length) {
			if (counter == index) return pointer->data;
			counter++;
			pointer = pointer->next;
		}
		throw "OUT OF RANGE";
	}
private:
	int length;
	node* first;
	node* last;
};