#include "PointBall.h"

PointBall::PointBall() : Object("pointball.png") {
	this->ChangePosition();
	this->ChangeColor();
}

void PointBall::Update(){

	this->ChangePosition();
	this->ChangeColor();
	
	if(!buff){
		point_count=point_count+10;
	} else {
		point_count=point_count+20;
	}
}

void PointBall::ChangeState(int i){
	if(i==1){
		buff=true;
	}else{
		buff=false;
	}
}

int PointBall::CheckPoints(){
	return point_count;
}

/// hago funciones aparte para no repetir los rand en el constructor
/// y en el update, solo llamo a las funciones con this-> y listo

void PointBall::ChangeColor(){
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	m_sprite.setColor({r,g,b});
}

void PointBall::ChangePosition(){
	/// el sprite mide 35x35, por eso las dimensiones máximas tienen
	/// que ser 1024 y 470 restándole el 35, sino sobrepasa el límite
	int x = std::rand()%(989 + 1);
	int y = std::rand()%(435 + 1 - 200)+200;
	m_sprite.setPosition(x,y);
}





