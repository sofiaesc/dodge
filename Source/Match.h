#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Obstacle.h"
#include "Player.h"
#include "Scene.h"
#include <string>
#include "PointBall.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Lives.h"
#include "PowerUp.h"
using namespace std;
using namespace sf;

class Match : public Scene {
public:
	Match(string p_sp);
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	Obstacle ob_1, ob_2, ob_3, ob_4;
	int lives_count=3, x=9;
	bool life_lost=false, collisions_enabled=true, game_over=false, recovering=false;
	Clock clock_1, clock_2, clock_3, clock_4, clock_5, clock_6;
	PowerUp pwp;
	Lives lv_1,lv_2,lv_3;
	Player m_pl;
	PointBall m_pt;
	Text m_txt;
	Font m_fnt;
	Sprite go_spr, cn_spr, rs_spr, sn_spr;
	Texture go_txt, cn_txt, rs_txt, sn_txt;
	Sound p_sound, l_sound;
	SoundBuffer p_buffer, l_buffer;
};

#endif
