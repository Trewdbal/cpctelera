//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <cpctelera.h>
#include "demo.song"

// Status of a Key (Pressed / Released)
typedef enum { K_RELEASED, K_PRESSED } TKeyStatus;

void main(void) {
   TKeyStatus space_bar = K_RELEASED;
   unsigned char playing = 1, color = 1;
   char* video_pos = (char*) 0xC000;

   cpct_disableFirmware();
   cpct_setVideoMode(2);

   // Initialize the song to be played
   cpct_arkosPlayer_init(molusk_song);

   while (1) {
      // We have to call the play function 50 times per second (because the song is 
      // designed at 50Hz). We only have to wait for VSYNC and call the play function
      // when the song is not stopped (still playing)
      cpct_waitVSYNC();

      if (playing) {
         cpct_arkosPlayer_play();

         // Write a new dash to the screen to see something while playing
         cpct_drawROMCharM2(video_pos, color, '#');
         if (++video_pos >= (char*)0xC7D0) {
            video_pos = (char*)0xC000;
            color ^= 1;
         }
      }

      // Check keyboard to let the user play/stop the song with de Space Bar
      // (Only change status when space_bar is released)
      cpct_scanKeyboardFast();
      if (space_bar == K_PRESSED) {
         if ( !cpct_isKeyPressed(Key_Space) ) {
            space_bar = K_RELEASED;
            if (playing)
               cpct_arkosPlayer_stop();
            playing ^= 1;
         }
      } else if (cpct_isKeyPressed(Key_Space)) {
         space_bar = K_PRESSED;
      }
   }
}