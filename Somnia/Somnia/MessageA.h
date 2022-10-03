#pragma once
#ifndef MESSAGEA_H
#define MESSAGEA_H

#include <iostream>

class MessageA {
private:
	std::string className = "Message";
public:
	MessageA() {}
	MessageA(const std::string& name) {
		chClassName(name);
	}
	~MessageA() {}

	std::string with_quotes(const std::string& str);

	void chClassName(const std::string& name);
	void message(const std::string& str);
	void message(const std::string& str1, const std::string& str2);
	void message(const std::string& str1, const std::string& str2, const std::string& str3);
	void message(const std::string& str1, const std::string& str2, const std::string& str3, const std::string& str4);
	void message(const std::string& str1, const std::string& str2, const std::string& str3, const std::string& str4, const std::string& str5);
};

#endif //!MESSAGEA_H
