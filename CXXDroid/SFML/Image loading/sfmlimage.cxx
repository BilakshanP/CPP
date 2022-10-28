#include <stdio.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

// Function for scaling and placing a sprite to fill width / height
void placeSprite(sf::Sprite &sprite, float w, float h)
{
	// Our image is square, so scale accordingly
	if (h > w)
	{
		sprite.setScale(w / sprite.getLocalBounds().width, w / sprite.getLocalBounds().width);
		sprite.setPosition(0, (h - w) / 2.f);
	}
	else
	{
		sprite.setScale(h / sprite.getLocalBounds().height, h / sprite.getLocalBounds().height);
		sprite.setPosition((w - h) / 2.f, 0);
	}
}

int main(int argc, char *argv[])
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Hello SFML Image");
	sf::Image image;
	if (!(image.loadFromFile("cxxdroid.png")))
	{
		fprintf(stderr, "Couldn't load image\n");
		return 1;
	}
	sf::Texture texture;
	texture.loadFromImage(image);
	// Better scaling quality
	texture.setSmooth(true);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::View view = window.getDefaultView();
	placeSprite(sprite, view.getSize().x, view.getSize().y);
	sf::Clock clock;
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

				placeSprite(sprite, event.size.width, event.size.height);
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
		if (clock.getElapsedTime().asMilliseconds() > 5000)
			break;
	}
	return 0;
}