#include "Lives.h"
#include <iostream>
using namespace std;

Lives::Lives(int x, int y) : Object("lives.png"){
	real_color=m_sprite.getColor();
	m_sprite.setPosition(x,y);
}

void Lives::Update(){
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();

	if(l_status==2){
		m_sprite.setColor({r,g,b});
	}
	if(l_status==1){
		m_sprite.setColor(real_color);
	}
	if(l_status==0){
		m_sprite.setColor({0,0,0,0});
	}
}

void Lives::ChangeStatus(int i){
	l_status=i;
}
