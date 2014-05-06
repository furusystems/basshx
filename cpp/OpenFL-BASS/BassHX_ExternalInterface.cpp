#define WIN32_LEAN_AND_MEAN
#define IMPLEMENT_API
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <bass.h>
#pragma comment(lib, "bass.lib")

#include <hx\CFFI.h>

#include <array>

using namespace std;

extern "C" {
	static void endMusic() {
		BASS_Stop();
		BASS_Free();
	}
	static void startMusic (value path) {
		endMusic();
		HMUSIC hm;
		BASS_Init (-1, 44100, 0, 0, NULL);
		hm=BASS_MusicLoad(FALSE, val_string(path) ,0,0,BASS_SAMPLE_LOOP,0);
		BASS_ChannelPlay(hm,FALSE);
	}
}
DEFINE_PRIM(startMusic, 1);
DEFINE_PRIM(endMusic, 0);