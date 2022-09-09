#pragma once
#include <iostream> //потом обязательно это убери отсюда

#define STREAMLIMIT 1000

class String {

private:
	int size_;
	char* str_;
	int strSize(const char* str);


public:
	String(const char* str); //конструктор
	String(const char* str, int size); //конструктор
	String();//конструктор по умолчанию
	String(const String& obj); //конструктор копирования
	~String();


	//String& operator=(String& obj);
	String& operator=(const String obj);
	String operator+(const String& obj);
	String operator+=(const String& obj);
	bool operator==(const String& obj);
	bool operator!=(const String& obj);
	char operator[](int i) const;
	//void operator[](int i);
	//friend int pow(int num, int exp);
	

	int length() const;
	void resize(int newSize);
	void clear();
	bool empty() const;
	void push_back(const char character);
	void append(int num, const char character);
	void append(const char* str);
	void append(const String& obj);
	void append(const char* str, int pos, int count);
	int stoi() const;
	bool isletter(char c) const;
	void toLower();
	void toUpper();
	
	friend std::ostream& operator<<(std::ostream& out, const String& obj);
	friend std::istream& operator>>(std::istream& in, const String& obj);
	


};