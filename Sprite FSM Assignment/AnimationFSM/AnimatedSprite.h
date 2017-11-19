#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Clock.hpp>
#include <vector>
#include <Debug.h>

using namespace std;
using namespace sf;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(const Texture&);
	AnimatedSprite(const Texture&, const IntRect&);
	~AnimatedSprite();

	const Clock& getClock();
	const Time& getTime();
	const vector<IntRect>& getFrames();
	const IntRect& getFrame(int);
	void addFrame(IntRect&);
	const int getCurrentFrame();
	void setStartFrame(int t_startFrame);
	void setEndFrame(int t_endFrame);
	void setCurrentFrame(int t_currentFrame);
	void update();
	
private:
	Clock m_clock;
	Time m_time;
	vector<IntRect> m_frames;
	int m_current_frame;//The Current Frame the animation is on
	int m_endFrame;//The Last frame in an animation loop
	int m_startFrame;//The First Frame in an animation loop
};

#endif // !ANIMATED_SPRITE_H
