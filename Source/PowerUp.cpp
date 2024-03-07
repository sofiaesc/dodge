#include "PowerUp.h"
#include <iostream>
using namespace std;

PowerUp::PowerUp() : Object("trsp.png") {
	m_sprite.setPosition(100,100);
	
	t_1.loadFromFile("life_heart.png");
	t_2.loadFromFile("r_star.png");
	t_3.loadFromFile("rayo.png");
	t_4.loadFromFile("coin.png");
	t_5.loadFromFile("snail.png");
	t_6.loadFromFile("bomb.png");
}

void PowerUp::Update(int i){
	
	if (i==0) m_sprite.setTexture(t_1);
	if (i==1) m_sprite.setTexture(t_2);
	if (i==2) m_sprite.setTexture(t_3);
	if (i==3) m_sprite.setTexture(t_4);
	if (i==4) m_sprite.setTexture(t_5);
	if (i==5) m_sprite.setTexture(t_6);
	
	int x = std::rand()%(989 + 1);
	int y = std::rand()%(435 + 1 - 200)+200;
	m_sprite.setPosition(x,y);
}

void PowerUp::ChangePosition(){
	m_sprite.setPosition(-200,-200);
}


