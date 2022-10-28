#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

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
	if (!al_install_audio())
	{
		fprintf(stderr, "Couldn't initialize Allegro audio addon\n");
		return -1;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "Couldn't initialize Allegro audio codecs\n");
		return -1;
	}
	if (!al_reserve_samples(1))
	{
		fprintf(stderr, "Couldn't reserve samples!\n");
		return -1;
	}
	ALLEGRO_SAMPLE *music = al_load_sample("music.ogg");
	if (music == NULL)
	{
		fprintf(stderr, "Couldn't load music\n");
		return 1;
	}
	ALLEGRO_SAMPLE_INSTANCE *music_instance = al_create_sample_instance(music);
	al_attach_sample_instance_to_mixer(music_instance, al_get_default_mixer());
	al_play_sample_instance(music_instance);
	while (al_get_sample_instance_playing(music_instance))
	{
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;
}