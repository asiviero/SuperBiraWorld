/*
 * sound.cpp
 *
 *  Created on: Jul 27, 2012
 *      Author: andre
 */


#include "../inc.h"

/*
 * Most of the code here was taken from: http://www.kekkai.org/roger/sdl/mixer/
 * Access date is the same of file creation
 *
 */

//Mix_Music *music = NULL;


/* Mix_Music actually holds the music information.  */
Mix_Music *music = NULL;

void playBackgroundSound(char *soundName) {


	/* We're going to be requesting certain things from our audio
	     device, so we set them up beforehand */
	  int audio_rate = 22050;
	  Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
	  int audio_channels = 2;
	  int audio_buffers = 4096;

	  SDL_Init(SDL_INIT_AUDIO);

	  /* This is where we open up our audio device.  Mix_OpenAudio takes
	     as its parameters the audio format we'd /like/ to have. */
	  if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
	    printf("Unable to open audio!\n");
	    exit(1);
	  }

		/* Actually loads up the music */
		music = Mix_LoadMUS("../Birao Cowboy.mp3");

		/* This begins playing the music - the first argument is a
		   pointer to Mix_Music structure, and the second is how many
		   times you want it to loop (use -1 for infinite, and 0 to
		   have it just play once) */
		Mix_PlayMusic(music, 0);

		/* We want to know when our music has stopped playing so we
		   can free it up and set 'music' back to NULL.  SDL_Mixer
		   provides us with a callback routine we can use to do
		   exactly that */
		Mix_HookMusicFinished(musicDone);
}

/* This is the function that we told SDL_Mixer to call when the music
   was finished. In our case, we're going to simply unload the music
   as though the player wanted it stopped.  In other applications, a
   different music file might be loaded and played. */
void musicDone() {
  Mix_HaltMusic();
  Mix_FreeMusic(music);
  music = NULL;
}
