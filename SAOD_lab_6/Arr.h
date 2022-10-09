#ifndef _ARR_
#define _ARR_
#include<iostream>
class Arr {
private:
	int m_size;
	int* m_array;

public:
	Arr() {
		m_size = 0;
		m_array = new int[m_size] {};

	}
	int size() {
		return m_size;
	}
	void push_back(int data) {
		int* temp_arr = new int[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			temp_arr[i] = m_array[i];
		}
		temp_arr[m_size] = data;
		delete[]m_array;
		m_array = temp_arr;
		m_size++;
	}
	void insert(int index, int data) {
		int* temp_arr = new int[m_size + 1];
		for (int i = 0; i < index; i++)
		{
			temp_arr[i] = m_array[i];
		}
		temp_arr[index] = data;
		for (int i = index + 1; i < m_size + 1; i++)
		{
			temp_arr[i] = m_array[i - 1];
		}
		delete[]m_array;
		m_array = temp_arr;
		m_size++;
	}
	void remove(int index) {
		int* temp_arr = new int[m_size - 1];
		for (int i = 0; i < index; i++)
		{
			temp_arr[i] = m_array[i];
		}
		for (int i = index; i < m_size - 1; i++)
		{
			temp_arr[i] = m_array[i + 1];
		}
		delete[]m_array;
		m_array = temp_arr;
		m_size--;
	}
	void print() {
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_array[i] << " ";
		}
		std::cout << std::endl;
	}

	int& operator[](int index) {
		return m_array[index];
	}
	int find_first(int data) {
		for (int i = 0; i < m_size; i++)
		{
			if (m_array[i] == data) {
				return i;
			}
		}
		return -1;
	}
	int find_last(int data) {
		for (int i = m_size - 1; i >= 0; i--)
		{
			if (m_array[i] == data) {
				return i;
			}
		}
		return -1;
	}
	void sort() {
		for (int d = m_size / 2; d != 0; d /= 2) {
			for (int* i = m_array + d; i != m_array + m_size; i++) {
				for (int* j = i; j >= m_array + d; j -= d) {
					if ((*j) < (*(j - d))) {
						std::swap((*j), (*(j - d)));
						//this->print();
					}
				}
			}
		}
	}
	bool contains(int data) {
		for (int i = 0; i < m_size; i++)
		{
			if (m_array[i] == data) return true;
		}
		return false;
	}
	~Arr() {
		delete[]m_array;
	}
};

#endif