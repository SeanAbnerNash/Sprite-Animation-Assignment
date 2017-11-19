#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

//@Author Sean Nash
//@login C00217019
//Finite State Machine Sprite Assignment
//Time Taken 4 Hours
//Known Issues: Currently even if a state cannot swap to another state the animation still changes. This is due to placing the animation setting functions where they are. However I wasnt able to work out a better way to do this.

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())//This is where the issue with the animations is, I'm not sure how to improve this. Had issues when trying to pass the animated sprite as a pointer/into the function
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_animated_sprite.setStartFrame(0);//Sets the animation loops first frame
		m_animated_sprite.setEndFrame(5);//Sets the animation loops last frame
		m_animation.idle();
		break;
	case Input::Action::UP://Climb Up
		
		m_animated_sprite.setStartFrame(18);
		m_animated_sprite.setEndFrame(23);
		m_animation.climbing();
		break;
	case Input::Action::LEFT://Walk LEFT
	
		m_animated_sprite.setStartFrame(6);
		m_animated_sprite.setEndFrame(11);
		m_animation.walking();
		break;
	case Input::Action::SHOVEL://Shovel S
		
		m_animated_sprite.setStartFrame(24);
		m_animated_sprite.setEndFrame(29);
		m_animation.shoveling();
		break;
	case Input::Action::HAMMER://HAMMER H
							  
		m_animated_sprite.setStartFrame(30);
		m_animated_sprite.setEndFrame(35);
		m_animation.hammering();
		break;
	case Input::Action::RIGHT://Jump RIGHT
		m_animated_sprite.setStartFrame(12);
		m_animated_sprite.setEndFrame(17);
		m_animation.jumping();
		break;
	default:
		break;
	}
}


void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}