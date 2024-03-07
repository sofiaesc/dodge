#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Game;

class Scene {
public:
	Scene();
	virtual void Update(Game &game) = 0;
	virtual void Draw(RenderWindow &window) = 0;
private:
};

#endif
