#pragma once
#ifndef WORDA_H
#define WORDA_H

#include <SFML/Graphics.hpp>
#include "MessageA.h"
#include "WindowA.h"
#include <random>
#include <unordered_map>

struct WH_symbols {
	float x = 50, y = 79;
};

class WordA {
private:
	MessageA m;
	std::string text_str;
	sf::Text text_text;
	sf::Font font;
	sf::Vector2f origin_pos = sf::Vector2f(x, y);
	sf::Color color;

	std::string id = generateID();
	void chPosition();

	std::string generateID();
	static std::string defaultFontfilename;
	static sf::Color defaultColor;

	unsigned int font_size = 10;
	float x = 0, y = 0;
	float added_y = 0;

public:

	WordA(const std::string& str = "string") {
		create(str);
	}
	WordA(const std::string& str, sf::Color color_) {
		create(str, color_);
	}
	WordA(const std::string& str, float x_, float y_) {
		create(str, x_, y_);
	}
	WordA(const std::string& str, sf::Vector2f pos_) {
		create(str, pos_);
	}
	WordA(const std::string& str, const unsigned int& font_size_) {
		create(str, font_size_);
	}
	WordA(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_) {
		create(str, pos_, font_size_);
	}
	WordA(const std::string& str, float x_, float y_, const unsigned int& font_size_) {
		create(str, sf::Vector2f(x_, y_), font_size_);
	}
	WordA(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_, sf::Color color_) {
		create(str, pos_, font_size_, color_);
	}


	void create(const std::string& str);
	void create(const std::string& str, sf::Color color_);
	void create(const std::string& str, float x_, float y_);
	void create(const std::string& str, sf::Vector2f pos_);
	void create(const std::string& str, const unsigned int& font_size_);
	void create(const std::string& str, sf::Color color_, const unsigned int& font_size_);
	void create(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_);
	void create(const std::string& str, sf::Vector2f pos_, sf::Color color_);
	inline void create(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_, sf::Color color_);


	std::string getID();

	static void setDefaultColor(sf::Color color_) {
		defaultColor = color_;
	}
	static void setDefaultFont(const std::string filename_) {
		defaultFontfilename = filename_;
	}

	void setFontSize();
	void setFontSize(const unsigned int& size_);
	unsigned int getFontSize();

	void setColor();
	void setColor(sf::Color color_);
	sf::Color getColor();

	bool setFont(const std::string& filename);

	void setString(const std::string& str);
	std::string getString();

	void setText(const sf::Text& text_);
	sf::Text getText();

	void setPosition(sf::Vector2f pos_);
	void setPosition(float x_, float y_);
	sf::Vector2f getPosition();

	void draw(sf::RenderWindow& window);
	void draw(WindowA *w);

	~WordA() {}

	static std::string generate_uuid(size_t len = 20) {
		static const char x[] = "0123456789abcdef";
		int num_hyphen = rand() % (len / 10 + 1);
		std::random_device rd;
		std::mt19937 gen(rd());

		std::unordered_map<int, int> index_hyphens;
		int pre_i = 4;
		for (int num = 0; num < num_hyphen; ++num) {
			pre_i = rand() % (len - pre_i - 4) + pre_i + 4;
			if (pre_i < 0 || pre_i > len - 4 - 1)  break;
			index_hyphens[pre_i] = 1;
		}

		std::uniform_int_distribution < > dis(0, sizeof(x) - 2);
		std::string uuid(len, '\0');
		int i = 0;
		for (auto& c : uuid) {
			if (index_hyphens[i]) c = '-';
			else c = x[dis(gen)];
			++i;
		}

		return uuid;
	}

	static std::unordered_map<char, WH_symbols>& dict_symbols;
};

#endif //!WORDA_H