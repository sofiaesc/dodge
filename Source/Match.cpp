#include "Match.h"
#include "Game.h"
#include "Menu.h"
#include "EnterPoints.h"
#include <sstream>
using namespace std;

Match::Match(string p_sp) : m_pl(p_sp), ob_1(1200,200,2.5), ob_2(-140,270,3), ob_3(1290,340,4), ob_4(-230,410,2), lv_1(100,115), lv_2(145,115), lv_3(190,115) {
	
	m_fnt.loadFromFile("ARCADECLASSIC.ttf");
	m_txt.setFont(m_fnt);
	m_txt.setString("0");
	
	m_txt.setFillColor({255,255,255});
	m_txt.setPosition(526,108);
	m_txt.setCharacterSize(34);
	
	p_buffer.loadFromFile("point_sound.wav");
	l_buffer.loadFromFile("lost_sound.wav");
	p_sound.setBuffer(p_buffer);
	l_sound.setBuffer(l_buffer);
	p_sound.setVolume(70);
	l_sound.setVolume(85);
	
	go_txt.loadFromFile("gameover.png");
	go_spr.setTexture(go_txt);
	go_spr.setPosition(-200,-200);
	
	cn_txt.loadFromFile("coin.png");
	cn_spr.setTexture(cn_txt);
	cn_spr.setPosition(-200,-200);
	
	rs_txt.loadFromFile("r_star.png");
	rs_spr.setTexture(rs_txt);
	rs_spr.setPosition(-200,-200);
	
	sn_txt.loadFromFile("snail.png");
	sn_spr.setTexture(sn_txt);
	sn_spr.setPosition(-200,-200);
}

void Match::Update (Game &game ) {
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu());
	
	if(collisions_enabled){
		
		/// para que vuelva al estado normal despues del rgb:
		
		if(lives_count==3){
			lv_1.ChangeStatus(1);
			lv_2.ChangeStatus(1);
			lv_3.ChangeStatus(1);
		}
		if(lives_count==2){
			lv_1.ChangeStatus(1);
			lv_2.ChangeStatus(1);
			lv_3.ChangeStatus(0);
		}
		if(lives_count==1){
			lv_1.ChangeStatus(1);
			lv_2.ChangeStatus(0);
			lv_3.ChangeStatus(0);
		}
		if(lives_count == 0){
			lv_1.ChangeStatus(0);
			int i = m_pt.CheckPoints();
			
			// GAME OVER:
			game_over = true;
			go_spr.setPosition(310,250);
			
			// DELAY:
			Time elapsed_5 = clock_5.getElapsedTime();
			
			if(elapsed_5.asSeconds()>=1.8f){
				game.SetScene(new EnterPoints(i));
			}
		}
		
		/// CUANDO CHOCA :
		if (ob_1.CollideWith(m_pl) || ob_2.CollideWith(m_pl) || ob_3.CollideWith(m_pl) || ob_4.CollideWith(m_pl)){
			
			// clock 5: clock para el delay cuando perdés
			clock_5.restart();
			clock_1.restart();
			life_lost=true;
			l_sound.play();
			lives_count=lives_count-1;
		}
	} else {
		
		if(lives_count==3){
			lv_1.ChangeStatus(2);
			lv_2.ChangeStatus(2);
			lv_3.ChangeStatus(2);
		}
		if(lives_count==2){
			lv_1.ChangeStatus(2);
			lv_2.ChangeStatus(2);
		}
		if(lives_count==1){
			lv_1.ChangeStatus(2);
		}
	}
	
	/// DELAY DE OBSTACULOS Y FLICKERING DEL PJ :
	
	if(life_lost){
		Time elapsed_1=clock_1.getElapsedTime();
		ob_1.Disappear(); ob_2.Disappear(); ob_3.Disappear(); ob_4.Disappear();
		
		if(elapsed_1.asSeconds()>=0.2f) m_pl.Disappear();
		if(elapsed_1.asSeconds()>=0.4f) m_pl.Reappear();
		if(elapsed_1.asSeconds()>=0.6f) m_pl.Disappear();
		if(elapsed_1.asSeconds()>=0.8f) m_pl.Reappear();
		if(elapsed_1.asSeconds()>=1.0f) m_pl.Disappear();
		if(elapsed_1.asSeconds()>=1.2f) m_pl.Reappear();
		if(elapsed_1.asSeconds()>=1.4f) m_pl.Disappear();
		if(elapsed_1.asSeconds()>=1.6f) m_pl.Reappear();
		
		if(elapsed_1.asSeconds()>=2.5f){
			ob_1.Reappear(); ob_2.Reappear(); ob_3.Reappear(); ob_4.Reappear();
			life_lost=false;
		}
	}
	
	if (m_pt.CollideWith(m_pl)){
		
		/// AUMENTO VELOCIDAD DE OBSTACULOS Y UPDATE CONTEO :
		m_pt.Update();
		p_sound.play();
		
		stringstream ss;
		ss << m_pt.CheckPoints();
		string str = ss.str();
		m_txt.setString(str);
		
		if(ob_1.CheckSpeed()>0){
			ob_1.SetSpeed(ob_1.CheckSpeed()+0.1);
		} else {
			ob_1.SetSpeed(ob_1.CheckSpeed()-0.1);
		}
		
		if(ob_2.CheckSpeed()>0){
			ob_2.SetSpeed(ob_2.CheckSpeed()+0.1);
		} else {
			ob_2.SetSpeed(ob_2.CheckSpeed()-0.1);
		}
		
		if(ob_3.CheckSpeed()>0){
			ob_3.SetSpeed(ob_3.CheckSpeed()+0.1);
		} else {
			ob_3.SetSpeed(ob_3.CheckSpeed()-0.1);
		}
		
		if(ob_4.CheckSpeed()>0){
			ob_4.SetSpeed(ob_4.CheckSpeed()+0.1);
		} else {
			ob_4.SetSpeed(ob_4.CheckSpeed()-0.1);
		}
	}
	
	/// ANIMACIÓN VIDA:
	
	if(recovering){
		Time elapsed_6=clock_6.getElapsedTime();
		
		if(lives_count == 3){
			if(elapsed_6.asSeconds()>=0.2f) lv_3.ChangeStatus(0);
			if(elapsed_6.asSeconds()>=0.4f) lv_3.ChangeStatus(1);
			if(elapsed_6.asSeconds()>=0.6f) lv_3.ChangeStatus(0);
			if(elapsed_6.asSeconds()>=0.8f) lv_3.ChangeStatus(1);
			if(elapsed_6.asSeconds()>=1.0f) lv_3.ChangeStatus(0);
			if(elapsed_6.asSeconds()>=1.2f) lv_3.ChangeStatus(1);
			if(elapsed_6.asSeconds()>=1.4f) recovering=false;
		}
		if(lives_count == 2){
			if(elapsed_6.asSeconds()>=0.2f) lv_2.ChangeStatus(0);
			if(elapsed_6.asSeconds()>=0.4f) lv_2.ChangeStatus(1);
			if(elapsed_6.asSeconds()>=0.6f) lv_2.ChangeStatus(0);
			if(elapsed_6.asSeconds()>=0.8f) lv_2.ChangeStatus(1);
			if(elapsed_6.asSeconds()>=1.0f) lv_2.ChangeStatus(0);
			if(elapsed_6.asSeconds()>=1.2f) lv_2.ChangeStatus(1);
			if(elapsed_6.asSeconds()>=1.4f) recovering=false;
		}
	}
	
	/// APARICION POWER-UPS :
	Time elapsed_2 = clock_2.getElapsedTime();
	Time elapsed_3 = clock_3.getElapsedTime();
	
	if(!game_over){ // para que no sigan apareciendo después de perder (estético)
		if(elapsed_2.asSeconds()>=8.0f){
			srand(time(0));
			if(lives_count==3){
				x=rand()%(5)+1; // para que no aparezca el +1 vida si tenemos 3/3 vidas
			} else { 
				x=rand()%6;
			}
			pwp.Update(x); // cambia el sprite y la posición cada 8 segundos
			clock_3.restart();
			clock_2.restart();
		}
	}
	
	/// EFECTOS POWERUPS
	if(pwp.CollideWith(m_pl)){
		switch(x){
		case 0: // suma una vida
			lives_count=lives_count+1;
			clock_6.restart();
			recovering = true;
			break;
			
		case 1: // estrella desactiva colisiones
			collisions_enabled=false;
			ob_1.ChangeColor(0); ob_2.ChangeColor(0); ob_3.ChangeColor(0); ob_4.ChangeColor(0);
			rs_spr.setPosition(900,120);
			break;
			
		case 2: // disminuye velocidad obstaculos
			if(ob_1.CheckSpeed()>0){
				ob_1.SetSpeed(ob_1.CheckSpeed()-1);
			} else {
				ob_1.SetSpeed(ob_1.CheckSpeed()+1);
			}
			
			if(ob_2.CheckSpeed()>0){
				ob_2.SetSpeed(ob_2.CheckSpeed()-1);
			} else {
				ob_2.SetSpeed(ob_2.CheckSpeed()+1);
			}
			
			if(ob_3.CheckSpeed()>0){
				ob_3.SetSpeed(ob_3.CheckSpeed()-1);
			} else {
				ob_3.SetSpeed(ob_3.CheckSpeed()+1);
			}
				
			if(ob_4.CheckSpeed()>0){
				ob_4.SetSpeed(ob_4.CheckSpeed()-1);
			} else {
				ob_4.SetSpeed(ob_4.CheckSpeed()+1);
			}
			break;
			
		case 3: // x2 al score por 5 segundos
			m_pt.ChangeState(1);
			cn_spr.setPosition(900,120);
			break;
			
		case 4: // disminuye velocidad pl
			m_pl.SetSpeed(0);
			sn_spr.setPosition(900,120);
			break;
			
		case 5: // pierde una vida
			lives_count = lives_count - 1;
			l_sound.play();
			clock_1.restart();
			clock_5.restart();
			life_lost=true;
			break;
		}
		pwp.ChangePosition(); // posicion al -200,-200 para que no se vea
		// restarts para que se reestablezca el clock cuando se agarra el powerup.
		// sino si lo agarras a los 4 segundos que aparece, por ejemplo, 
		// el efecto dura 1 solo segundo o algo asi:
		clock_4.restart();
		clock_3.restart();
	}
	
	Time elapsed_4 = clock_4.getElapsedTime();
	if(elapsed_4.asSeconds()>=5.0f){
		collisions_enabled=true; // efecto estrella arcoiris
		rs_spr.setPosition(-200,-200); // estrella indicadora arriba
		m_pt.ChangeState(0); // efecto duplicador
		cn_spr.setPosition(-200,-200); // moneda indicadora arriba
		ob_1.ChangeColor(1); ob_2.ChangeColor(1); ob_3.ChangeColor(1); ob_4.ChangeColor(1);
		clock_4.restart();
	}
	
	if(elapsed_3.asSeconds()>=3.0f){
		pwp.ChangePosition(); // desaparece el pwp si no es agarrado
		m_pl.SetSpeed(1); // efecto ralentizador
		sn_spr.setPosition(-200,-200); // caracol indicador arriba
		clock_3.restart();
	}
	
	if(!game_over){ //para que no sigan moviéndose los sprites en esa pantalla
	ob_1.Update(); ob_2.Update(); ob_3.Update(); ob_4.Update(); 
	m_pl.Update();
	}
	
	lv_1.Update(); lv_2.Update(); lv_3.Update();
	
}

void Match::Draw (RenderWindow & window) {
	Texture t_bgg;
	t_bgg.loadFromFile("bg_game.png");
	Sprite s_bgg;
	s_bgg.setTexture(t_bgg);
	
	window.draw(s_bgg);
	window.draw(m_txt);
	
	lv_1.Draw(window); lv_2.Draw(window); lv_3.Draw(window);
	m_pt.Draw(window); pwp.Draw(window);
	ob_1.Draw(window); ob_2.Draw(window); ob_3.Draw(window); ob_4.Draw(window);
	m_pl.Draw(window);
	
	window.draw(go_spr); window.draw(cn_spr); window.draw(rs_spr); window.draw(sn_spr);
	
	window.display();
}

