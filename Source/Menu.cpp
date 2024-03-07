#include "Menu.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Select.h"
#include "Highscores.h"
#include "Help.h"
using namespace std;
using namespace sf;

Menu::Menu() {
	m_font.loadFromFile("ARCADECLASSIC.ttf");
	m_t1.setFont(m_font);
	
	m_t1.setString("p r e s i o n a       E N T E R       p a r a       j u g a r");
	m_t1.setFillColor({255,255,255});
	m_t1.setPosition(215,410);
	m_t1.setCharacterSize(34);
}

void Menu::Update (Game &game) {
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Return))
		game.SetScene(new Select());
	
	if (Keyboard::isKeyPressed(Keyboard::Key::H))
		game.SetScene(new Highscores());
	
	if (Keyboard::isKeyPressed(Keyboard::Key::G))
		game.SetScene(new Help());
}

void Menu::Draw (RenderWindow & window) {
	Texture t_bg;
	t_bg.loadFromFile("bg_menu.png");
	Sprite s_bg;
	s_bg.setTexture(t_bg);
	window.draw(s_bg);
	window.draw(m_t1);
	window.display();
}

