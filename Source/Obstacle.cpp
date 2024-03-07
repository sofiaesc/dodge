#include "Obstacle.h"
using namespace std;

Obstacle::Obstacle(float x,float y,float v) : Object("obstacle.png") {
	m_sprite.setPosition(x,y);
	initial_pos.x=x; initial_pos.y=y;
	this->SetSpeed(v);
}

void Obstacle::Update ( ) {
	m_sprite.move(m_speed);
	auto p = m_sprite.getPosition();
	if (p.x<=-250 || p.x+52>=1350){
		m_speed.x = -m_speed.x;
	}
}

void Obstacle::SetSpeed(float v){
	m_speed = {v,0};
}

float Obstacle::CheckSpeed(){
	return m_speed.x;
}

/// para hacer que vaya a otra parte de la pantalla y vuelva:

void Obstacle::Disappear(){
	m_sprite.setPosition(-100,-100);
}

void Obstacle::Reappear(){
	m_sprite.setPosition(initial_pos);
}

/// para bajar transparencia y después desactivar colisiones:
/// lo mismo d las vidas q paja 

void Obstacle::ChangeColor(int i){
	Color c_transparent=m_sprite.getColor();
	c_transparent.a=40;
	Color c_full=m_sprite.getColor();
	c_full.a=255;
	
	if(i==0){
		m_sprite.setColor(c_transparent);
	} else {
	m_sprite.setColor(c_full);
	}
}
