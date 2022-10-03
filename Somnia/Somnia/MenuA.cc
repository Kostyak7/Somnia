#include "MenuA.h"

void MenuA::create(WindowA* w_) {
	w = w_;
	isMenu = 1;
}

void MenuA::menuGo() {
	while (isMenu) {
		w->firstlyA(isMenu);

		w->preUpdateA();
		w->upadateA();
		w->postUpdate();
	}
}