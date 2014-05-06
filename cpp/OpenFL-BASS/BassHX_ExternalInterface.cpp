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
	static HMUSIC musicHandle;
	static void init(){
		BASS_Init (-1, 44100, 0, 0, NULL);
	}
	static void shutdown(){
		BASS_Stop();
		BASS_Free();
	}
	static void endMusic(value free) {
		bool f = val_bool(free);
		BASS_ChannelStop(musicHandle);
		if(f) BASS_MusicFree(musicHandle);
	}
	static void startMusic (value path) {
		HMUSIC newHandle = BASS_MusicLoad(FALSE, val_string(path) ,0,0,BASS_SAMPLE_LOOP,0);
		endMusic(alloc_bool(newHandle != musicHandle));
		musicHandle = newHandle;
		BASS_ChannelPlay(musicHandle,FALSE);
	}
}
DEFINE_PRIM(init,0);
DEFINE_PRIM(shutdown,0);
DEFINE_PRIM(startMusic, 1);
DEFINE_PRIM(endMusic, 1);