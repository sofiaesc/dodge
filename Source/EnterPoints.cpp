#include "EnterPoints.h"
#include "Game.h"
#include "Match.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "Highscores.h"
#include "Menu.h"
using namespace std;

bool sort_by_score(player_hs a,player_hs b){
	return (a.pl_points>b.pl_points);
}

EnterPoints::EnterPoints(int pnts) : text_entrada(p_font,40,sf::Color::White){
	
	ifstream archi("highscores.txt", ios::in);
	string aux_str;
	
	while(getline(archi,aux_str)){
		stringstream ss(aux_str);
		string aux_name; ss>>aux_name;
		int aux_pt; ss>>aux_pt;
		
		player_hs aux_pl;
		aux_pl.pl_points=aux_pt;
		aux_pl.pl_name=aux_name;
		
		v.push_back(aux_pl);
	}
	
	archi.close();
	
	p_font.loadFromFile("ARCADECLASSIC.ttf");
	c_points.setFont(p_font);
	t1.setFont(p_font);
	
	current_pl.pl_points=pnts;
	stringstream ss;
	ss << pnts;
	string str = ss.str();
	
	t1.setString("N E W   H I G H S C O R E !");
	t1.setPosition(395,170);
	t1.setCharacterSize(25);
	
	c_points.setString(str);
	c_points.setFillColor({255,255,255});
	
	if(current_pl.pl_points>v[4].pl_points){
		enter_hs=true;
		c_points.setPosition(223,317);
		c_points.setCharacterSize(40);
	} else{
		c_points.setPosition(478,350);
		c_points.setCharacterSize(60);
	}

	text_entrada.setPosition(194,480);
	text_entrada.setMaxChars(10);
	text_entrada.setSingleWord(true);
}

void EnterPoints::Update(Game &game){
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	t1.setColor({r,g,b});
	
	if(!current_pl.pl_name.empty()){
		game.SetScene(new Highscores());
	}
	
	if(!enter_hs){
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			game.SetScene(new Menu());
		}
	}
}

void EnterPoints::Draw(RenderWindow &window){
	Texture ep_bg;
	
	if(enter_hs){
		
		ep_bg.loadFromFile("bg_points.png");
		Sprite s_bg;
		s_bg.setTexture(ep_bg);
		window.draw(s_bg);
		window.draw(c_points);
		window.draw(t1);
		
		Event e;
		while(window.pollEvent(e)) {
			if(e.type == Event::Closed)
				window.close();	
			else if (e.type==sf::Event::KeyPressed && e.key.code==sf::Keyboard::Return) { 
				string string_ingresado = text_entrada.getValue();
				current_pl.pl_name=string_ingresado;
				
				v.push_back(current_pl);
				sort(v.begin(),v.end(),sort_by_score);
				
				ofstream archi2("highscores.txt", ios::trunc);
				
				for(int i=0;i<5;i++) { 
					archi2<<v[i].pl_name<<" "<<v[i].pl_points<<endl;
				}
				archi2.close();
				
			} else text_entrada.processEvent(e); 
		}
		text_entrada.update();
		window.draw(text_entrada);
		
	} else {
		ep_bg.loadFromFile("bg_points2.png");
		Sprite s_bg;
		s_bg.setTexture(ep_bg);
		window.draw(s_bg);
		window.draw(c_points);
	}

	window.display();
}

