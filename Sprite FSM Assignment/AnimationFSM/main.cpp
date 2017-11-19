#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>



//@Author Sean Nash
//@login C00217019
//Finite State Machine Sprite Assignment
//Time Taken 4 Hours
//Known Issues: Currently even if a state cannot swap to another state the animation still changes. This is due to placing the animation setting functions where they are. However I wasnt able to work out a better way to do this.

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	int idleTracker = 0;
	bool idleCheck = true;//Idle Variables to reset the state back to idle once a period of time passes
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);
	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));//IDLE LINE 0 - 5
	animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));

	animated_sprite.addFrame(sf::IntRect(3, 87, 84, 84));//WALK LINE 6 - 11 
	animated_sprite.addFrame(sf::IntRect(88, 87, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 87, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 87, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 87, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 87, 84, 84));

	animated_sprite.addFrame(sf::IntRect(3, 171, 84, 84));//Jump LINE 12 - 17 
	animated_sprite.addFrame(sf::IntRect(88, 171, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 171, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 171, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 171, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 171, 84, 84));

	animated_sprite.addFrame(sf::IntRect(3, 255, 84, 84));//Climb LINE 18 - 23 
	animated_sprite.addFrame(sf::IntRect(88, 255, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 255, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 255, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 255, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 255, 84, 84));

	animated_sprite.addFrame(sf::IntRect(3, 339, 84, 84));//Shovel LINE 24 - 29 
	animated_sprite.addFrame(sf::IntRect(88, 339, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 339, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 339, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 339, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 339, 84, 84));

	animated_sprite.addFrame(sf::IntRect(3, 423, 84, 84));//Hammer LINE 30 - 35
	animated_sprite.addFrame(sf::IntRect(88, 423, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 423, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 423, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 423, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 423, 84, 84));


	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{	
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//Takes the input and resets the IDLE counter.
				{
					idleCheck = false;
					idleTracker = 0;
					input.setCurrent(Input::Action::LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					idleCheck = false;
					idleTracker = 0;
					input.setCurrent(Input::Action::RIGHT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					idleCheck = false;
					idleTracker = 0;
					input.setCurrent(Input::Action::SHOVEL);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					idleCheck = false;
					idleTracker = 0;
					input.setCurrent(Input::Action::HAMMER);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Takes the input and resets the IDLE counter.
				{
					idleCheck = false;
					idleTracker = 0;
					input.setCurrent(Input::Action::UP);
				}
				break;
			default:
				break;
			}

		}
		if (idleTracker > 6500)//Once the idle counter reaches this point it resets itself and sets the state to idle
		{
			
			idleTracker = 0;
			idleCheck = true;
			input.setCurrent(Input::Action::IDLE);
		}
		if (idleCheck == false)
		{
			idleTracker++;
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};