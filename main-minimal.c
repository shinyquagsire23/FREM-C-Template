#include "include/gba.h"

#define Tiles   ((u16 *) 0x6008000)
#define MapData ((u16 *) 0x600E800)
#define BG0Data ((u16 *) 0x6000000)
#define BG2Data ((u16 *) 0x600F000)
#define OBJData ((u16 *) 0x6010000)
#define MenuBG  ((u16 *) 0x600F800)

#define DMA3Source		(*(u32 *) 0x040000D4)
#define DMA3Dest		(*(u32 *) 0x040000D8)
#define DMA3Options		(*(u32 *) 0x040000DC)

#define status		(*(u8 *) (globalVars + 0x0))

void main();

void init() 
{
	main();
}

#include "include/gba_compress.h"
#include "useful.h"

//Select the proper useful.h for the version we're compiling
#ifdef engine
#if engine == 1
	#include "useful-bpee.h"
#else
	#include "useful-bpre.h"
#endif
#endif

//Main Loop
void main() 
{		
	//Your code here!
}
