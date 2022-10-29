#pragma once
#ifndef TEXTA_H
#define TEXTA_H

#include <SFML/Graphics.hpp>
#include "MessageA.h"
#include "WordA.h"


class TextA : public WordA {
private:
	std::string start_str;
	bool isWidth = 0;
	float width = 50;
	float pixel_len = 0;
	float font_const = 1;

	static float get_pixel_len(const unsigned int& font_size_, const std::string& str_);

	void start();

public:
	TextA(const std::string& str = "string")
		: WordA(str), start_str(str) {
		start();
	}
	TextA(const std::string& str, sf::Color color_)
		: WordA(str, color_), start_str(str) {
		start();
	}
	TextA(const std::string& str, float x_, float y_)
		: WordA(str, x_, y_), start_str(str) {
		start();
	}
	TextA(const std::string& str, sf::Vector2f pos_)
		: WordA(str, pos_), start_str(str) {
		start();
	}
	TextA(const std::string& str, const unsigned int& font_size_)
		: WordA(str, font_size_), start_str(str) {
		start();
	}
	TextA(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_)
		: WordA(str, pos_, font_size_), start_str(str) {
		start();
	}
	TextA(const std::string& str, float x_, float y_, const unsigned int& font_size_)
		: WordA(str, sf::Vector2f(x_, y_), font_size_), start_str(str) {
		start();
	}
	TextA(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_, sf::Color color_)
		: WordA(str, pos_, font_size_, color_), start_str(str) {
		start();
	}

	void cropping_by_width(const float& width_);
	void remove_cropping();

};

 
//class TextA {
//private:
//	std::vector<WordA> text;
//
//	std::string text_str;
//
//	void parse(bool alone_space);
//public:
//
//	TextA(const std::string& str){
//		create(str);
//	}
//
//	void create(const std::string& str, bool alone_space = 0);
//
//	void addText(const std::string& str);
//
//	std::string getString();
//
//	void setPosition(float x_, float y_);
//	void setPosition(sf::Vector2f pos_);
//
//	~TextA(){}
//};

#endif //!TEXTA_H