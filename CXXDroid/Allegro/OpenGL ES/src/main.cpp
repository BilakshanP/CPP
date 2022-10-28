#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>
#include "triangle_renderer.hpp"

int main(int argc, char *argv[])
{
	if (!al_init())
	{
		fprintf(stderr, "Couldn't initialize Allegro\n");
		return 1;
	}

	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
	if (display == NULL)
	{
		fprintf(stderr, "Couldn't create display\n");
		return 1;
	}

	// Initialize triangle renderer
	triangle_init();

	while (true)
	{
		// Draw triangle
		triangle_render(al_get_time() * 1000.);
		// Swap buffers
		al_flip_display();
	}

	al_destroy_display(display);
	return 0;
}