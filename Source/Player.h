#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include <SFML/Window/Keyboard.hpp>
#include <string>
using namespace std;
using namespace sf;

class Player : public Object {
public:
	Player(string p_sp);
	void Disappear();
	void Reappear();
	void Update();
	void SetSpeed(int i);
private:
	Keyboard::Key m_up, m_down, m_right, m_left;
	Color real_color;
	bool debuff=false;
	float sp=6;
};

#endif

