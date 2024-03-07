#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

Player::Player(string p_sp) :  Object(p_sp) {
	
	m_sprite.setScale(.25,.25);
	real_color=m_sprite.getColor();
	
	m_sprite.setPosition(200,200);
	m_up = Keyboard::Key::Up;
	m_down = Keyboard::Key::Down;
	m_right = Keyboard::Key::Right;
	m_left = Keyboard::Key::Left;
	
}

void Player::Update ( ) {
	auto p = m_sprite.getPosition();

	/// los && en los if de up/down para que no se mueva en diagonal, 
	/// no es necesario en right/left porque ya está supuesto con estos
	
	if(debuff){
		sp=4;
	}else{
		sp=7;
	}
	
		if (p.y>200)
			if (Keyboard::isKeyPressed(m_up) && !Keyboard::isKeyPressed(m_right) && !Keyboard::isKeyPressed(m_left))
				m_sprite.move(0,-sp);
		if (p.y+50<455) 
			if (Keyboard::isKeyPressed(m_down) && !Keyboard::isKeyPressed(m_right) && !Keyboard::isKeyPressed(m_left))
				m_sprite.move(0,+sp);

		if (p.x+100<1024)
			if (Keyboard::isKeyPressed(m_right))
				m_sprite.move(+sp,0);
		if (p.x>0) 
			if (Keyboard::isKeyPressed(m_left))
				m_sprite.move(-sp,0);
	
}

void Player::Disappear(){
	m_sprite.setColor({0,0,0,0});
}

void Player::Reappear(){
	m_sprite.setColor(real_color);
}

void Player::SetSpeed(int i){
	if(i==0){
		debuff=true;
	} else{
		debuff=false;
	}
}
