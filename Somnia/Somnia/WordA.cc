#include "WordA.h"

std::string WordA::generateID() {
	return "id:" + generate_uuid();
}

void WordA::chPosition() {
	text_text.setPosition(x, y);
}

std::string WordA::defaultFontfilename = "files/fonts/PixelFont 1.ttf";
sf::Color WordA::defaultColor = sf::Color(0, 0, 0);


void WordA::create(const std::string& str, sf::Color color_) {
	create(str, sf::Vector2f(x, y), font_size, color_);
}

void WordA::create(const std::string& str) {
	create(str, sf::Vector2f(x, y), font_size, defaultColor);
}
void  WordA::create(const std::string& str, float x_, float y_) {
	create(str, sf::Vector2f(x_, y_), font_size, defaultColor);
}
void  WordA::create(const std::string& str, sf::Vector2f pos_) {
	create(str, pos_, font_size, defaultColor);
}
void  WordA::create(const std::string& str, const unsigned int& font_size_) {
	create(str, sf::Vector2f(x, y), font_size_, defaultColor);
}
void  WordA::create(const std::string& str, sf::Color color_, const unsigned int& font_size_) {
	create(str, sf::Vector2f(x, y), font_size_, color_);
}
void  WordA::create(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_) {
	create(str, pos_, font_size_, defaultColor);
}
void  WordA::create(const std::string& str, sf::Vector2f pos_, sf::Color color_) {
	create(str, pos_, font_size, color_);
}
void  WordA::create(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_, sf::Color color_) {
	bool isOk = 1;

	isOk = isOk && setFont(defaultFontfilename);
	setFontSize(font_size_);
	setString(str);
	setColor(color_);
	setPosition(pos_);

	m.chClassName("TextA");
	if (isOk) m.message("text success create");
	else m.message("text does not create");
}




std::string WordA::getID() {
	return id;
}

void WordA::setFontSize() {
	text_text.setCharacterSize(font_size);
}

void WordA::setFontSize(const unsigned int& size_) {
	font_size = size_;
	text_text.setCharacterSize(font_size);
}
unsigned int WordA::getFontSize() {
	return font_size;
}

void WordA::setColor() {
	text_text.setColor(defaultColor);
}

void WordA::setColor(sf::Color color_) {
	color = color_;
	text_text.setColor(color);
}

sf::Color WordA::getColor() {
	return color;
}

bool WordA::setFont(const std::string& filename_) {
	if (font.loadFromFile(filename_)) {
		text_text.setFont(font);
		return true;
	}
	m.message("Error to load font for element with id:", m.with_quotes(id));
	return false;
}

void WordA::setString(const std::string& str) {
	text_str = str;
	text_text.setString(text_str);
}

std::string WordA::getString() {
	return text_str;
}

void WordA::setText(const sf::Text& text_) {
	text_text = text_;
	font_size = text_text.getCharacterSize();
	text_str = text_text.getString();
	color = text_text.getColor();
	x = text_text.getPosition().x;
	y = text_text.getPosition().y;
}

sf::Text WordA::getText() {
	return text_text;
}


void WordA::setPosition(sf::Vector2f pos_) {
	x = pos_.x;
	y = pos_.y;
	chPosition();
}

void WordA::setPosition(float x_, float y_) {
	x = x_;
	y = y_;
	chPosition();
}


void WordA::draw(sf::RenderWindow &window) {
	window.draw(text_text);
}

void WordA::draw(WindowA *w) {
	w->window.draw(text_text);
}