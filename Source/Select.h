#ifndef SELECT_H
#define SELECT_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
using namespace sf;

class Select : public Scene {
public:
	Select();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
};

#endif

