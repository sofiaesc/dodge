#include "Help.h"
#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>

Help::Help() {}

void Help::Update (Game &game) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu());
}

void Help::Draw (RenderWindow & window) {
	Texture hg_bg;
	hg_bg.loadFromFile("bg_help.png");
	Sprite s_bg;
	s_bg.setTexture(hg_bg);
	window.draw(s_bg);
	window.display();
}

