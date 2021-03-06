//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 Dardalorth / Fremos / Carlio
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

#include <types.h>

// Define used to set the memory address where transparency table will be
// included. Please, read more detailed explanations on sprites.c
//
#define cpct_transparentMaskTable00M0_address 0x0100

// Declare transparent table symbol, that will be defined at sprites.c (The symbol
// is included from CPCtelera's header file transparency_tables.h).
//
extern __at(cpct_transparentMaskTable00M0_address) const u8 cpct_transparentMaskTable00M0[256];

// Alien sprite 
//   Generated running this command on the assets folder (command line):
//    cpct_img2tileset -pf { 0 18 5 6 9 11 12 } -bn alien -tw 12 -th 24 alien.png
//
extern __at(0x200) const u8 g_alien[6*24];

// Palette declarations
extern const u8 g_palette[7];

// Tile Declarations 
//   Generated running this command on the assets folder (command line):
//    cpct_img2tileset -pf { 0 18 5 6 9 11 12 } tiles.png
//
extern const u8 g_tile0[2*4];
extern const u8 g_tile1[2*4];
extern const u8 g_tile2[2*4];
extern const u8 g_tile3[2*4];
extern const u8 g_tile4[2*4];
extern const u8 g_tile5[2*4];
extern const u8 g_tile6[2*4];
extern const u8 g_tile7[2*4];
extern const u8 g_tile8[2*4];
extern const u8 g_tile9[2*4];
extern const u8 g_tile10[2*4];
extern const u8 g_tile11[2*4];
extern const u8 g_tile12[2*4];
extern const u8 g_tile13[2*4];
extern const u8 g_tile14[2*4];
extern const u8 g_tile15[2*4];
extern const u8 g_tile16[2*4];
extern const u8 g_tile17[2*4];
extern const u8 g_tile18[2*4];
extern const u8 g_tile19[2*4];
extern const u8 g_tile20[2*4];
extern const u8 g_tile21[2*4];
extern const u8 g_tile22[2*4];
extern const u8 g_tile23[2*4];
extern const u8 g_tile24[2*4];

// Tileset declaration (Generated with cpct_img2tileset)
extern const u8* const g_tileset[25];

// Background tilemap created with tiled.
extern const u8 g_background[40*50];