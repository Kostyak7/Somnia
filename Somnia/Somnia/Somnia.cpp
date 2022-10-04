#include "WindowA.h"
#include "MenuA.h"
#include <time.h>

int main() {
	srand(time(NULL));

	WindowA* window = new WindowA;
	MenuA* menu = new MenuA(window);

	menu->menuGo();

	delete menu;
	menu = NULL;

	delete window; 
	window = NULL;

	return 0;
}