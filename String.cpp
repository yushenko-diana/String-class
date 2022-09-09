#include "String.h"

int String::strSize(const char* str) {
	int size = 0;
	int pos = 0;
	while (str[pos] != '\0') {
		++size;
		++pos;
	}
	return size;
}

String::String(const char* str) {

	size_ = strSize(str);
	str_ = new char[size_];
	for (int i = 0; i < size_; ++i) {
		str_[i] = str[i];
	}


}

String::String(const char* str, int size) {
	size_ = size;
	str_ = new char[size];
	for (int i = 0; i < size_; ++i) {
		str_[i] = str[i];
	}
}

String::String() : String("") {} //делигирование конструктора

String::String(const String& obj) { //ссылка на константу для того, тчобы я могла передавать константные объекты
	this->size_ = obj.size_; 
	//delete[] this->str_; 
	//str_ = NULL;
	this->str_ = new char[this->size_];

	for (int i = 0; i < this->size_; ++i) {
		this->str_[i] = obj.str_[i];
	}
}

String::~String() {
	//std::cout << size_ << std::endl;
	//for (int i = 0; i < size_; ++i) {
	//	std::cout << str_[i];
	//}
	std::cout << std::endl;
	//std::cout << &str_ <<std::endl;
	delete[] str_;

}

/*String& String::operator=(String& obj) {

	this->size_ = obj.size_;
	delete[] this->str_;
	this->str_ = new char[this->size_];

	for (int i = 0; i < this->size_; ++i) {
		this->str_[i] = obj.str_[i];
	}
	return *this;
}*/

String& String::operator=(const String obj) {

	this->size_ = obj.size_;
	delete[] this->str_;
	this->str_ = new char[this->size_];

	for (int i = 0; i < this->size_; ++i) {
		this->str_[i] = obj.str_[i];
	}
	return *this;
}

String String::operator+(const String& obj) {

	int newSize = this->size_ + obj.size_;
	char* newStr = new char[newSize];
	for (int i = 0; i < this->size_; ++i) {
		newStr[i] = this->str_[i];
	}
	for (int i = 0, j = this->size_; i < obj.size_, j < obj.size_ + this->size_; ++i, ++j) {
		newStr[j] = obj.str_[i];
	}

	String newObj = String(newStr, newSize);
	delete[] newStr;
	return newObj;
}


String String::operator+=(const String& obj) {
	const int newSize = this->size_ + obj.size_;
	char* newStr = new char[newSize];
	for (int i = 0; i < this->size_; ++i) {
		newStr[i] = this->str_[i];
	}
	for (int i = 0, j = this->size_; i < obj.size_, j < obj.size_ + this->size_; ++i, ++j) {
		newStr[j] = obj.str_[i];
	}

	String newObj = String(newStr, newSize);
	delete[] newStr;
	return newObj;
} //проверь условие в цикле 

bool String::operator==(const String& obj) {
	if (this->size_ != obj.size_) return false;
	for (int i = 0; i < obj.size_; i++) {
		if (this->str_[i] != obj.str_[i]) return false;
	}
	return true;
}

bool String::operator!=(const String& obj) {
	if (this->size_ != obj.size_) return true;
	for (int i = 0; i < obj.size_; i++) {
		if (this->str_[i] != obj.str_[i]) return true;
	}
	return false;
}

char String::operator[](int i) const {
	if (i > size_) throw "1"; //??????????????????????????????????????? можно ли так делать? и где отлавливать это исключение???? разобраться
	return str_[i];
}


int String::length() const {
	return size_;
}

void String::resize(int newSize) {
	char* newStr = new char[newSize];
	if (newSize == 0) {
		delete[] str_;
		size_ = newSize;
		str_ = new char;
	}
	if (newSize < size_) {
		for (int i = 0; i < newSize; i++) {
			newStr[i] = str_[i];
		}
	}
	else {
		for (int i = 0; i < size_; i++) {
			newStr[i] = str_[i];
		}
		for (int i = size_; i < newSize; i++) {
			newStr[i] = '0';
		}
	}
	size_ = newSize;
	delete[] str_;
	str_ = newStr;
}



void String::clear() {
	this->resize(1);
	str_[0] = '\0';
}

bool String::empty() const {
	if (size_ == 0) return true;
	return false;
}

void String::push_back(const char character) {
	this->resize(size_ + 1);
	str_[size_] = character;
}

void String::append(int num, const char character) {
	int tempSize = size_;
	this->resize(size_ + num);
	for (int i = tempSize; i < size_; ++i) {
		str_[i] = character;
	}
}


void String::append(const char* str) {
	int size = strSize(str);
	int tempSize = size_;
	this->resize(size_ + size);
	for (int i = tempSize, j = 0; i < size_, j < size; ++i, ++j) {
		str_[i] = str[j];
	}
}
void String::append(const String& obj) {
	this->append(obj.str_);
}


void String::append(const char* str, int pos, int count) {
	int size = count - pos;
	int tempSize = size_;
	this->resize(size_ + size);
	for (int i = tempSize, j = 0; i < size_, j < size; ++i, ++j) {
		str_[i] = str[j];
	}
}

bool String::isletter(char c) const {
	if (((int)c > 64 && (int)c < 91) || ((int)c > 96 && (int)c < 123)) return true;
	return false;
}

int String::stoi() const {
	int number = 0;
	for (int i = 0; i < this->size_; ++i) {
		if (this->isletter(this->str_[i])) throw 2;
		number += ((int)(this->str_[i]) - 48) * (int)(pow(10, size_ - 1 - i)); //-48 потому что в таблице аски кода 0 имеет значение 48
	}
	return number;
}

void String::toLower() {
	for (int i = 0; i < this->size_; ++i) {
		if (!this->isletter(this->str_[i])) throw 3;
		if ((int)str_[i] > 96 && (int)str_[i] < 123) continue;
		str_[i] = (char)(str_[i] + 32);
	}
}

void String::toUpper() {
	for (int i = 0; i < this->size_; ++i) {
		if (!this->isletter(this->str_[i])) throw 3;
		if ((int)str_[i] > 64 && (int)str_[i] < 91) continue;
		str_[i] = (char)(str_[i] - 32);
	}
}

std::ostream& operator<<(std::ostream& out, const String& obj) {
	char* temp = new char[obj.size_];
	for (int i = 0; i < obj.size_; i++) {
		temp[i] = obj.str_[i];
	}
	out << temp;
	delete[] temp;
	return out;
}
std::istream& operator>>(std::istream& in, const String& obj) {
	in.get(obj.str_, STREAMLIMIT);
	return in;
}