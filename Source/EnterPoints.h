#ifndef ENTERPOINTS_H
#define ENTERPOINTS_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "InputBox.h"
#include <string>
#include <vector>
using namespace std;
using namespace sf;

struct player_hs{
	string pl_name;
	int pl_points;
};

class EnterPoints : public Scene {
public:
	EnterPoints(int pnts);
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	vector<player_hs>v;
	bool enter_hs=false;
	player_hs current_pl;
	Font p_font;
	Text c_points, t1;
	InputText text_entrada;
};

#endif
