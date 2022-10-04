#pragma once
#ifndef MENUA_H
#define MENUA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "WindowA.h"
#include "MessageA.h"

class MenuA {
private:
	MessageA m;
	WindowA *w;
public:
	bool isMenu = 0;
	MenuA(WindowA *w_){
		create(w_);
	}

	void create(WindowA* w_);

	void menuGo();

	~MenuA(){}
};

#endif //!MENUA_H