#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Scene.h"
using namespace sf;

class Menu : public Scene {
public:
	Menu();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	Font m_font;
	Text m_t1;
};

#endif

