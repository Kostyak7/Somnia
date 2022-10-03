#include "MessageA.h"

void MessageA::chClassName(const std::string& name) {
	className = name;
}


std::string MessageA::with_quotes(const std::string& str) {
	return "\"" + str + "\"";
}


void MessageA::message(const std::string& str) {
	std::cout << className << ": " << str << std::endl;
}
void MessageA::message(const std::string& str1, const std::string& str2) {
	std::cout << className << ": " << str1 << " " << str2 << std::endl;
}
void MessageA::message(const std::string& str1, const std::string& str2, const std::string& str3) {
	std::cout << className << ": " << str1 << " " << str2 << " " << str3 << std::endl;
}
void MessageA::message(const std::string& str1, const std::string& str2, const std::string& str3, const std::string& str4) {
	std::cout << className << ": " << str1 << " " << str2 << " " << str3 << " " << str4 << std::endl;
}
void MessageA::message(const std::string& str1, const std::string& str2, const std::string& str3, const std::string& str4, const std::string& str5) {
	std::cout << className << ": " << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << std::endl;
}