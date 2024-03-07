#include "Select.h"
#include "Game.h"
#include "Match.h"
#include "Menu.h"
using namespace std;
using namespace sf;

Select::Select(){}

void Select::Update (Game &game) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu());
	
	/// pasa el string con el nombre del archivo al constructor de match, 
	/// que tiene un player que es object. el constructor de object hace 
	/// el sprite y le setea la textura.
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
		game.SetScene(new Match("corredor1.png"));
	if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
		game.SetScene(new Match("corredor2.png"));
	if (Keyboard::isKeyPressed(Keyboard::Key::Num3))
		game.SetScene(new Match("corredor3.png"));
	if (Keyboard::isKeyPressed(Keyboard::Key::Num4))
		game.SetScene(new Match("corredor4.png"));
	if (Keyboard::isKeyPressed(Keyboard::Key::Num5))
		game.SetScene(new Match("corredor5.png"));
	if (Keyboard::isKeyPressed(Keyboard::Key::Num6))
		game.SetScene(new Match("corredor6.png"));

}

void Select::Draw (RenderWindow & window) {
	Texture sc_bg;
	sc_bg.loadFromFile("cs_menu.png");
	Sprite s_bg;
	s_bg.setTexture(sc_bg);
	window.draw(s_bg);
	window.display();
}
