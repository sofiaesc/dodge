#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Object.h"

class Obstacle : public Object {
public:
	/// constructor tiene coordenadas y velocidad
	Obstacle(float x, float y, float v);
	void Update();
	void Disappear();
	void Reappear();
	void SetSpeed(float v);
	float CheckSpeed();
	void ChangeColor(int i);
private:
	Vector2f m_speed = {0,0};
	Vector2f initial_pos;
};


#endif
