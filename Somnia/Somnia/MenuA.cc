#include "MenuA.h"
#include "TextA.h"
#include <ostream>

void MenuA::create(WindowA* w_) {
	m.chClassName("MenuA");
	w = w_;
	isMenu = 1;
	m.message("menu success create");
}

const std::string str_ = "\
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor \
incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud \
exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure \
dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit \
anim id est laborum\
";


void MenuA::menuGo() {
	WordA::setDefaultColor(sf::Color(255, 255, 255));

	TextA text(str_, 0, 0, 100);
	text.cropping_by_width(400);

	while (isMenu) {
		w->firstlyA(isMenu);


		w->preUpdateA();
		
		text.draw(w->window);

		w->upadateA();
		w->postUpdate();
	}
}