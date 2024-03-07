#ifndef HELP_H
#define HELP_H
#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Help : public Scene {
public:
	Help();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
};

#endif

