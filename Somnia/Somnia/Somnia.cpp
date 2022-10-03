#include "WindowA.h"
#include "MenuA.h"

int main() {

	WindowA* window = new WindowA;

	MenuA* menu = new MenuA(window);

	menu->menuGo();

	delete menu;
	menu = NULL;
	delete window; 
	window = NULL;

	return 0;
}