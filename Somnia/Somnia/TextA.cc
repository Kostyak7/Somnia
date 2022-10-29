#include "TextA.h"
#include <string>

void TextA::start() {
	font_const = getFontSize() / 100.;
	pixel_len = get_pixel_len(getFontSize(), getString());
}

void TextA::cropping_by_width(const float& width_) {
	isWidth = 1;
	width = width_;
	std::string str_ = getString();
	float cur_len = 0;
	for (int i = 0; i < str_.size(); ++i) {
		if (str_[i] == '\n') {
			cur_len = 0;
			continue;
		}
		cur_len += ceil(dict_symbols[str_[i]].x * font_const);
		if (cur_len > width) {
			if (str_[i] != ' ') {
				int j = i;
				while (j != 0 && str_[j] != ' ' && str_[j] != '-' && str_[j] != '\n') {
					--j;
				}
				if (j == 0 || str_[j] == '-' || str_[j] == '\n') {
					if (str_[j] != '-') str_.insert(str_.begin() + i - 1, '-');
					str_.insert(str_.begin() + i, '\n');
					if (str_[j] != '-') ++i;
					++i;
				}
				else if (str_[j] == ' ') {
					str_[j] = '\n';
				}
			}
			else {
				str_[i] = '\n';
			}
			cur_len = 0;
		}
	}

	setString(str_);
}

void TextA::remove_cropping() {
	isWidth = 0;
	setString(start_str);
}

float TextA::get_pixel_len(const unsigned int& font_size_, const std::string& str_) {
	float len_ = 0;
	for (const char& c : str_) {
		len_ += ceil(dict_symbols[c].x * font_size_ /100.);
	}
	return len_;
}

//void TextA::parse(bool alone_space) {
//	bool is_sp = 0;
//	int i_s = 0, i = 0;
//	while (!text_str.empty() && i < text_str.size() && text_str[i] == ' ') {
//		++i;
//	}
//	for (; i < text_str.size(); ++i) {
//
//	}
//	if (!text_str.empty() && text.empty()) {
//		text.push_back(text_str);
//	}
//}
//
//void TextA::create(const std::string& str, bool alone_space) {
//	text_str = str;
//	parse(alone_space);
//}
//
//
//void TextA::addText(const std::string& str) {
//
//}
//
//
//std::string TextA::getString() {
//	return text_str;
//}
//
//
//void TextA::setPosition(float x_, float y_) {
//
//}
//void TextA::setPosition(sf::Vector2f pos_) {
//
//}
