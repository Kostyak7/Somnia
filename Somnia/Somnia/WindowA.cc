#include "WindowA.h"

void WindowA::create(const std::string& window_title) {
	if (!isCreate) {
		title = window_title;
		m.chClassName("WindowA");
		window.create(sf::VideoMode(scrW, scrH, desktop.bitsPerPixel), title, sf::Style::Default);
		isCreate = 1;
		m.message("window:", m.with_quotes(title), "success create");
	}
	else {
		m.message("window already create");
	}
}



void WindowA::chWindowSizes(const int& W_, const int& H_) {
	scrW = desktop.width;
	scrH = desktop.height;
}

void WindowA::chSmoothness(const unsigned int& smoothness_) {
	smoothness = smoothness_;
}

void WindowA::chTitle(const std::string& title_) {
	title = title_;
	window.setTitle(title);
}

void WindowA::chIcon(const std::string& filename_) {
	sf::Image imageIcon;
	if (imageIcon.loadFromFile(filename_)) {
		window.setIcon(imageIcon.getSize().x, imageIcon.getSize().y, imageIcon.getPixelsPtr());
		m.message("success loading icon of app ->", std::to_string(imageIcon.getSize().x), std::to_string(imageIcon.getSize().y));
	}
	else {
		m.message("Error to load icon of app");
	}
}

void WindowA::chFramerateLimit(const unsigned int& limit_) {
	window.setFramerateLimit(limit_);
}

void WindowA::chCursor(const std::string& filename_) {
	sf::Texture cursor_tx;
	if (!cursor_tx.loadFromFile(filename_)) {
		m.message("Error to load image of cursor");
	}
	else {
		cursor_sp.setTexture(cursor_tx);
		window.setMouseCursorVisible(0);
		isOtherCursor = 1;
	}
}

void WindowA::undoCursor() {
	window.setMouseCursorVisible(1);
	isOtherCursor = 0;
}

void WindowA::chDefaultBackColor(sf::Color RGBA) {
	defaultBackRGBA = RGBA;
}


////////////// Window methods ////////////////
bool WindowA::checkEvent() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) { window.close(); return 0; }
		if (event.type == sf::Event::Resized) { window.setSize(sf::Vector2u(scrW, scrH)); }
	}
	return 1;
}

void WindowA::firstlyA(bool& isWindow) {
	isWindow = checkEvent();

	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / smoothness;
}

void WindowA::updateCursor() {
	sf::Vector2f pos_cr = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	if (isOtherCursor) {
		cursor_sp.setPosition(pos_cr.x, pos_cr.y);
	}
}

void WindowA::preUpdateA() {
	updateCursor();

	window.clear(defaultBackRGBA);
}

void WindowA::preUpdateA(sf::Color RGBA) {
	updateCursor();

	window.clear(RGBA);
}

void WindowA::upadateA() {
	if (isOtherCursor) window.draw(cursor_sp);
}

void WindowA::postUpdate() {
	window.display();
}