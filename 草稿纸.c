#ifndef _EXTRACTDATA_H_
#define _EXTRACTDATA_H_
 
#include <stdint.h>
 
typedef struct tagWAVHEADER {
	uint8_t   ChunkID[4];     // ?????       ?????"RIFF",????????? RIFF ?????
	uint32_t  ChunkSize;      // ???????   ????????????????????????????? 8 ???????????
	uint8_t   Format[4];      // ???????   ?? WAV ???????????"WAVE",?????? WAV ?????
	uint8_t   FmtChunkID[4];  // ??????     ?????,"fmt "?
	uint32_t  FmtChunkSize;   // ??????     ??????,??????????? 16? 18 ?20?40 ??
	uint16_t  AudioFormat;    // ???????   ??? WAV ???? PCM ????????,?????? 1?
	uint16_t  NumChannels;    // ?????       ???? 1,???????? 2?
	uint32_t  SampleRate;     // ?????       ????????????????????? 11025, 22050 ? 44100 kHz?
	uint32_t  ByteRate;       // ???????   ????:???�????�????????/8????????????????????
	uint16_t  BlockAlign;     // ???????? ??????????:???�??/8??????????????????????,??????????
	uint16_t  BitsPerSample;  // ?????       ??????????????????????? 4?8?12?16?24?32?
	uint8_t   DataChunkID[4];
	uint32_t  DataChunkSize;
} WAVHEADER;
 
void showWavHead(WAVHEADER Header);
#endif  // #ifndef _EXTRACTDATA_H_