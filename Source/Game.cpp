#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
using namespace sf;

Game::Game() 
	: m_window(VideoMode(1024,648),"DODGE")
{
	m_window.setFramerateLimit(60);
	m_scene = new Menu();
}
void Game::Run ( ) {
	
	/// settings de la musica
	Music soundtrack;
	soundtrack.setVolume(20);
	soundtrack.openFromFile("cancion.ogg");
	soundtrack.setLoop(true);
	soundtrack.play();
	
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if (m_next_scene) {
			
			/// delete de puntero
			
			delete m_scene;
			m_scene = m_next_scene;  
			m_next_scene = nullptr;
		}
	}
}

void Game::Update ( ) {
	m_scene->Update(*this);
}

void Game::Draw ( ) {
	m_scene->Draw(m_window);
}

void Game::ProcessEvents ( ) {
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_window.close();	
	}
}

void Game::SetScene (Scene * next_scene) {
	m_next_scene = next_scene;
}

