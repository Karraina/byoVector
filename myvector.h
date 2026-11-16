#pragma once
#ifndef LAPAIRIE_VECTOR_H
#define LAPAIRIE_VECTOR_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class MyVector {
private:
	T*elem;
	std::size_t array_size;
	std::size_t space;
public:
	MyVector() {
		elem = nullptr;
		array_size = 0;
		space = 0;
	}

	~MyVector() {
		delete[] elem;
	}

	MyVector(const MyVector&) = delete;
	MyVector& operator=(const MyVector&) = delete;

	std::size_t size() const {
		return array_size;
	}

	std::size_t capacity() const {
		return space;
	}

	void reserve(std::size_t new_capacity) {
		if (new_capacity <= space) {
			return;
		}

		T* new_elem = new T[new_capacity];

		try {
			for (std::size_t i = 0; i < array_size; i++) {
				new_elem[i] = elem[i];
			}
		}
		catch (...) {
			delete[] new_elem;
			throw;
		}

		delete[] elem;
		elem = new_elem;
		space = new_capacity;
	}

	void push_back(const T& value) {
		if (array_size == space) {
			if (space == space) {
				reserve(1);
			}
			else {
				reserve(space * 2);
			}
		}

		elem[array_size] = value;
		array_size++;
	}

	T& at(std::size_t index) {
		if (index >= array_size) {
			throw std::out_of_range("Index Out Of Range");
		}
		return elem[index];
	}
};

#endif
