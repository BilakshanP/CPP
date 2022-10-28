#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main(int argc, char *argv[])
{
	if (!al_init())
	{
		fprintf(stderr, "Couldn't initialize Allegro\n");
		return 1;
	}
	// This is important for image format support
	if (!al_init_image_addon())
	{
		fprintf(stderr, "Couldn't initialize Allegro image addon\n");
		return 1;
	}
	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
	if (display == NULL)
	{
		fprintf(stderr, "Couldn't create display\n");
		return 1;
	}
	// Better scaling quality
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	ALLEGRO_BITMAP *image = al_load_bitmap("cxxdroid.png");
	if (image == NULL)
	{
		fprintf(stderr, "Couldn't load image\n");
		return 1;
	}
	int w = al_get_display_width(display);
	int h = al_get_display_height(display);
	int bw = al_get_bitmap_width(image);
	int bh = al_get_bitmap_height(image);

	if (h > w)
	{
		al_draw_scaled_bitmap(image, 0, 0, bw, bh, 0, (h - w) / 2, w, w, 0);
	}
	else
	{
		al_draw_scaled_bitmap(image, 0, 0, bw, bh, (w - h) / 2, 0, h, h, 0);
	}
	al_flip_display();
	al_rest(5.);
	al_destroy_display(display);
	return 0;
}