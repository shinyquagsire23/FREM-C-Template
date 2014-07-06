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

void init2();
void init3();
void main();

void init() {

	storeCallback((void *) init2 + 1);
	
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

void init2() 
{
	storeCallback2(0);
	globalVars = malloc(0x2228);						//malloc 0x2228 bytes
	
	int blank = 0;
	DMA3Source = &blank;
	DMA3Dest = globalVars;
	DMA3Options = 0x81001114;						//blank out malloc space
	
	storeCallback((void *) init3 + 1);
	
}

void init3() 
{
	for(int i=0x10;i<0x20;i+=2) 
		changeIO(i,0);
	
	initStuff();
	storeCallback((void *) main + 1);
}

//Main Loop
void main() 
{		
	if(status == 0)
	{
		unfadeScreen();
		storeCallback2((void *) updateEverything2 + 1);

		status++;
	}
	else if(status == 1)
	{
		//Your looping code here!
	}		
	else if (status == 2) 
	{
		storeCallback(nullCallback);
		if (globalVars != 0) 
		{
			free(globalVars);
			globalVars = 0;
		}
		someExitFunc();
	}
	
	updateEverything();

}
