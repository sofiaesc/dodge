#ifndef HIGHSCORES_H
#define HIGHSCORES_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
using namespace std;

class Highscores : public Scene {
public:
	Highscores();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	Font h_font;
	Text h_t1, h_t2, h_t3, h_t4, h_t5;
	Text h_p1, h_p2, h_p3, h_p4, h_p5;
};

#endif
