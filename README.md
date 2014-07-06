FREM-C-Template
--------------

A simple C template for executing C code in Fire Red and Emerald via callasm or other methods, shipping with a custom auto-inserting makefile. To compile, execute **make -B <engine version, bpre for FR or bpee for EM> fname=<.gba file> offset=<offset>**. This uses the split useful.h system from the Ruins of Alph port, so to maintain proper cross-platform support changes in useful-bpre.h must be echoed to useful-bpee.h and vice versa.

There are two main C files used in this project, main.c and main-minimal.c. The difference is the usage between them. main.c features a callback hooking function which will allow you to exit and return from the overworld into your custom code. This is useful for things like cutscenes where you will want to have complete control over the GBA hardware. The second is main-minimal.c. This one features the proper #includes, and a main loop. Nothing else. This is useful for routines which do stuff behind the scenes which may or may not be too complicated to write in ASM. Both files are designed to be used with callasm, although they can work in other places if done properly.

