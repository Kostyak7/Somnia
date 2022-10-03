#pragma once
#ifndef WINDOWA_H
#define WINDOWA_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "MessageA.h"

class WindowA {
private:
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Color defaultBackRGBA = sf::Color(0, 0, 0);
	sf::Sprite cursor_sp;
	MessageA m;
	bool isOtherCursor = 0;
	bool isCreate = 0;
	unsigned int smoothness = 800;
	std::string title = "ArkEngine";

	void updateCursor();

public:
	int scrW = desktop.width, scrH = desktop.height;
	float time = 0;
	sf::RenderWindow window;
	sf::Clock clock;

	WindowA(const std::string& window_title = "ArkEngine") {
		create(window_title);
	}

	void create(const std::string& window_title);

	void chWindowSizes(const int& W_, const int& H_);
	void chSmoothness(const unsigned int& smoothness_);
	void chTitle(const std::string& title_);
	void chIcon(const std::string& filename_);
	void chFramerateLimit(const unsigned int& limit_);
	void chCursor(const std::string& filename_);
	void undoCursor();
	void chDefaultBackColor(sf::Color RGBA);
	
	bool checkEvent();
	void firstlyA(bool& isWindow);
	void preUpdateA();
	void preUpdateA(sf::Color RGBA);
	void upadateA();
	void postUpdate();

	~WindowA(){}
};

#endif //!WINDOWA_H