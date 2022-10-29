#include "WordA.h"

std::string WordA::generateID() {
	return "id:" + generate_uuid();
}

void WordA::chPosition() {
	text_text.setPosition(x, y - added_y);
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
inline void  WordA::create(const std::string& str, sf::Vector2f pos_, const unsigned int& font_size_, sf::Color color_) {
	bool isOk = 1;
	added_y = 33. * font_size_ / 100.;

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

sf::Vector2f WordA::getPosition() {
	return sf::Vector2f(x, y);
}


void WordA::draw(sf::RenderWindow &window) {
	window.draw(text_text);
}

void WordA::draw(WindowA *w) {
	w->window.draw(text_text);
}

namespace {
	//!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLM
	//NOPQRSTUVWXYZ[\] ^ _`abcdefghijklmnopqrstuvwxyz{|}~
	std::unordered_map<char, WH_symbols>& fill_dict_symbols() {
		static std::unordered_map<char, WH_symbols> dict_;

		dict_[' '] = WH_symbols{ 13 };
		dict_['!'] = WH_symbols{ 13 };
		dict_['"'] = WH_symbols{ 25 };
		dict_['#'] = WH_symbols{ 37 };
		dict_['$'] = WH_symbols{ 38 };
		dict_['%'] = WH_symbols{ 50 };
		dict_['&'] = WH_symbols{ 44 };
		dict_['\''] = WH_symbols{ 13 };
		dict_['('] = WH_symbols{ 25 };
		dict_[')'] = WH_symbols{ 25 };
		dict_['*'] = WH_symbols{ 38 };
		dict_['+'] = WH_symbols{ 37 };
		dict_[','] = WH_symbols{ 19 };
		dict_['-'] = WH_symbols{ 37 };
		dict_['.'] = WH_symbols{ 13 };
		dict_['/'] = WH_symbols{ 50 };
		dict_['0'] = WH_symbols{ 38 };
		dict_['1'] = WH_symbols{ 19 };
		dict_['2'] = WH_symbols{ 38 };
		dict_['3'] = WH_symbols{ 38 };
		dict_['4'] = WH_symbols{ 38 };
		dict_['5'] = WH_symbols{ 38 };
		dict_['6'] = WH_symbols{ 38 };
		dict_['7'] = WH_symbols{ 38 };
		dict_['8'] = WH_symbols{ 38 };
		dict_['9'] = WH_symbols{ 38 };
		dict_[':'] = WH_symbols{ 13 };
		dict_[';'] = WH_symbols{ 19 };
		dict_['<'] = WH_symbols{ 25 };
		dict_['='] = WH_symbols{ 37 };
		dict_['>'] = WH_symbols{ 25 };
		dict_['?'] = WH_symbols{ 38 };
		dict_['@'] = WH_symbols{ 56 };
		dict_['A'] = WH_symbols{ 38 };
		dict_['B'] = WH_symbols{ 38 };
		dict_['C'] = WH_symbols{ 38 };
		dict_['D'] = WH_symbols{ 38 };
		dict_['E'] = WH_symbols{ 38 };
		dict_['F'] = WH_symbols{ 38 };
		dict_['G'] = WH_symbols{ 38 };
		dict_['H'] = WH_symbols{ 38 };
		dict_['I'] = WH_symbols{ 13 };
		dict_['J'] = WH_symbols{ 38 };
		dict_['K'] = WH_symbols{ 38 };
		dict_['L'] = WH_symbols{ 38 };
		dict_['M'] = WH_symbols{ 51 };
		dict_['N'] = WH_symbols{ 38 };
		dict_['O'] = WH_symbols{ 38 };
		dict_['P'] = WH_symbols{ 38 };
		dict_['Q'] = WH_symbols{ 38 };
		dict_['R'] = WH_symbols{ 38 };
		dict_['S'] = WH_symbols{ 38 };
		dict_['T'] = WH_symbols{ 37 };
		dict_['U'] = WH_symbols{ 38 };
		dict_['V'] = WH_symbols{ 38 };
		dict_['W'] = WH_symbols{ 50 };
		dict_['X'] = WH_symbols{ 38 };
		dict_['Y'] = WH_symbols{ 38 };
		dict_['Z'] = WH_symbols{ 38 };
		dict_['['] = WH_symbols{ 25 };
		dict_['\\'] = WH_symbols{ 50 };
		dict_[']'] = WH_symbols{ 26 };
		dict_['^'] = WH_symbols{ 38 };
		dict_['_'] = WH_symbols{ 37 };
		dict_['`'] = WH_symbols{ 19 };
		dict_['a'] = WH_symbols{ 31 };
		dict_['b'] = WH_symbols{ 31 };
		dict_['c'] = WH_symbols{ 31 };
		dict_['d'] = WH_symbols{ 31 };
		dict_['e'] = WH_symbols{ 31 };
		dict_['f'] = WH_symbols{ 20 };
		dict_['g'] = WH_symbols{ 31 };
		dict_['h'] = WH_symbols{ 31 };
		dict_['i'] = WH_symbols{ 13 };
		dict_['j'] = WH_symbols{ 19 };
		dict_['k'] = WH_symbols{ 31 };
		dict_['l'] = WH_symbols{ 13 };
		dict_['m'] = WH_symbols{ 50 };
		dict_['n'] = WH_symbols{ 31 };
		dict_['o'] = WH_symbols{ 31 };
		dict_['p'] = WH_symbols{ 31 };
		dict_['q'] = WH_symbols{ 31 };
		dict_['r'] = WH_symbols{ 25 };
		dict_['s'] = WH_symbols{ 25 };
		dict_['t'] = WH_symbols{ 25 };
		dict_['u'] = WH_symbols{ 31 };
		dict_['v'] = WH_symbols{ 31 };
		dict_['w'] = WH_symbols{ 50 };
		dict_['x'] = WH_symbols{ 31 };
		dict_['y'] = WH_symbols{ 31 };
		dict_['z'] = WH_symbols{ 31 };
		dict_['{'] = WH_symbols{ 25 };
		dict_['|'] = WH_symbols{ 13 };
		dict_['}'] = WH_symbols{ 25 };
		dict_['~'] = WH_symbols{ 44 };
		
		return dict_;
	}
}

std::unordered_map<char, WH_symbols>& WordA::dict_symbols = fill_dict_symbols();