#include <stdio.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char *argv[])
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Hello SFML Music");
	sf::Music music;
	if (!music.openFromFile("music.ogg"))
	{
		fprintf(stderr, "Couldn't load music\n");
		return 1;
	}
	music.play();
	while (window.isOpen())
	{
		// It is required to poll all events so we can paint
		sf::Event event;
		while (window.pollEvent(event))
			;
		window.clear();
		window.display();
		if (music.getStatus() == sf::Sound::Stopped)
			break;
	}
	return 0;
}