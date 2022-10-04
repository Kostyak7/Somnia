#include "MenuA.h"
#include "WordA.h"

void MenuA::create(WindowA* w_) {
	m.chClassName("MenuA");
	w = w_;
	isMenu = 1;
	m.message("menu success create");
}

void MenuA::menuGo() {
	WordA::setDefaultColor(sf::Color(255, 255, 255));
	WordA word("Pizza", 100, 100, 56);

	while (isMenu) {
		w->firstlyA(isMenu);

		w->preUpdateA();
		w->upadateA();
		
		word.draw(w->window);

		w->postUpdate();
	}
}