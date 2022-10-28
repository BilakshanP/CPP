#include <stdio.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "triangle_renderer.hpp"

int main(int argc, char *argv[])
{
	// SFML supports OpenGL ES 1.1 only
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Hello SFML OpenGL ES 1.1");

	sf::View view = window.getDefaultView();
	sf::Clock clock;

	// Initialize triangle renderer
	triangle_init();

	while (window.isOpen())
	{
		// Handle screen resizes
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Resized)
			{
				view.setSize(event.size.width, event.size.height);
				view.setCenter(event.size.width / 2, event.size.height / 2);
				window.setView(view);
			}
		}
		// Draw triangle
		triangle_render(clock.getElapsedTime().asMilliseconds());
		// Swap buffers
		window.display();
	}
	return 0;
}