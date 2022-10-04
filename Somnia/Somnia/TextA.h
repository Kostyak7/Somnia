#pragma once
#ifndef TEXTA_H
#define TEXTA_H

#include <SFML/Graphics.hpp>
#include "MessageA.h"
#include "WordA.h"

class TextA {
private:
	std::vector<WordA> text;

	std::string text_str;

	void parse(bool alone_space);
public:

	TextA(const std::string& str){
		create(str);
	}

	void create(const std::string& str, bool alone_space = 0);

	void addText(const std::string& str);

	std::string getString();

	void setPosition(float x_, float y_);
	void setPosition(sf::Vector2f pos_);

	~TextA(){}
};

#endif //!TEXTA_H