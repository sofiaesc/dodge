#include "Menu.h"
#include "Highscores.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <fstream>

using namespace std;

Highscores::Highscores() {
	h_font.loadFromFile("ARCADECLASSIC.ttf");
	h_t1.setFont(h_font); h_t2.setFont(h_font); h_t3.setFont(h_font); h_t4.setFont(h_font); h_t5.setFont(h_font);
	h_p1.setFont(h_font); h_p2.setFont(h_font); h_p3.setFont(h_font); h_p4.setFont(h_font); h_p5.setFont(h_font);
	
	ifstream archi("highscores.txt", ios::in);
	vector<string>v;
	string aux_str;
	
	while(archi>>aux_str){
		v.push_back(aux_str);
	}
	
	h_t1.setString(v[0]); h_p1.setString(v[1]);
	h_t2.setString(v[2]); h_p2.setString(v[3]);
	h_t3.setString(v[4]); h_p3.setString(v[5]);
	h_t4.setString(v[6]); h_p4.setString(v[7]);
	h_t5.setString(v[8]); h_p5.setString(v[9]);
	
	h_t1.setFillColor({255,255,255}); h_p1.setFillColor({255,255,255}); 
	h_t1.setPosition(280,324); h_p1.setPosition(650,324);
	h_t1.setCharacterSize(36); h_p1.setCharacterSize(36);
	
	h_t2.setFillColor({255,255,255}); h_p2.setFillColor({255,255,255}); 
	h_t2.setPosition(280,364); h_p2.setPosition(650,364);
	h_t2.setCharacterSize(36); h_p2.setCharacterSize(36);
	
	h_t3.setFillColor({255,255,255}); h_p3.setFillColor({255,255,255}); 
	h_t3.setPosition(280,404); h_p3.setPosition(650,404);
	h_t3.setCharacterSize(36); h_p3.setCharacterSize(36);
	
	h_t4.setFillColor({255,255,255}); h_p4.setFillColor({255,255,255}); 
	h_t4.setPosition(280,444); h_p4.setPosition(650,444);
	h_t4.setCharacterSize(36); h_p4.setCharacterSize(36);
	
	h_t5.setFillColor({255,255,255}); h_p5.setFillColor({255,255,255}); 
	h_t5.setPosition(280,484); h_p5.setPosition(650,484);
	h_t5.setCharacterSize(36); h_p5.setCharacterSize(36);
}

void Highscores::Update (Game &game) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu());
}

void Highscores::Draw (RenderWindow & window) {
	Texture h_bg;
	h_bg.loadFromFile("bg_highscores.png");
	Sprite s_bg;
	s_bg.setTexture(h_bg);
	
	window.draw(s_bg);
	window.draw(h_t1); 
	window.draw(h_p1);
	window.draw(h_t2); 
	window.draw(h_p2);
	window.draw(h_t3); 
	window.draw(h_p3);
	window.draw(h_t4); 
	window.draw(h_p4);
	window.draw(h_t5); 
	window.draw(h_p5);
	window.display();
}
