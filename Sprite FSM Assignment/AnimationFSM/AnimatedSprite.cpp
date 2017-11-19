#include <AnimatedSprite.h>
#include <iostream>

AnimatedSprite::AnimatedSprite() 
{
	m_current_frame = 0;
	m_endFrame = 0;
}

AnimatedSprite::AnimatedSprite(const sf::Texture& t) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {}

AnimatedSprite::AnimatedSprite(const sf::Texture& t, const sf::IntRect& rect) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}

const sf::Clock& AnimatedSprite::getClock() {
	return m_clock;
}

const sf::Time& AnimatedSprite::getTime() {
	return m_time;
}

const vector<IntRect>& AnimatedSprite::getFrames() {
	return m_frames;
}

const IntRect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(IntRect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::setStartFrame(int t_startFrame)//The First frame in an animation Loop.
{
	m_startFrame = t_startFrame;
}

void AnimatedSprite::setEndFrame(int t_endFrame)//The Last frame in an animation Loop.
{

	m_endFrame = t_endFrame;
}

void AnimatedSprite::setCurrentFrame(int t_currentFrame)
{
	m_current_frame = t_currentFrame;
}


void AnimatedSprite::update(){
	if (m_clock.getElapsedTime() > m_time) {
		if (m_frames.size() > m_current_frame + 1 
			&& m_current_frame < m_endFrame //If the current frame is past the end point stop incrementing
			&& (m_endFrame - m_current_frame) < 6 )//If the current frame is outside the range of the animation loop
		{	
			m_current_frame++;
		}
		else {
			m_current_frame = m_startFrame;//Restart animation

		}
		m_clock.restart();
	}
}

