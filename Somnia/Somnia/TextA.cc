#include "TextA.h"
#include <string>

void TextA::parse(bool alone_space) {
	bool is_sp = 0;
	int i_s = 0, i = 0;
	while (!text_str.empty() && i < text_str.size() && text_str[i] == ' ') {
		++i;
	}
	for (; i < text_str.size(); ++i) {

	}
	if (!text_str.empty() && text.empty()) {
		text.push_back(text_str);
	}
}

void TextA::create(const std::string& str, bool alone_space) {
	text_str = str;
	parse(alone_space);
}


void TextA::addText(const std::string& str) {

}


std::string TextA::getString() {
	return text_str;
}


void TextA::setPosition(float x_, float y_) {

}
void TextA::setPosition(sf::Vector2f pos_) {

}
