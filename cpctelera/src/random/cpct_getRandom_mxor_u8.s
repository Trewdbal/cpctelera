;;-----------------------------LICENSE NOTICE------------------------------------
;;  This file is part of CPCtelera: An Amstrad CPC Game Engine 
;;  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
;;
;;  This program is free software: you can redistribute it and/or modify
;;  it under the terms of the GNU General Public License as published by
;;  the Free Software Foundation, either version 3 of the License, or
;;  (at your option) any later version.
;;
;;  This program is distributed in the hope that it will be useful,
;;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;  GNU General Public License for more details.
;;
;;  You should have received a copy of the GNU General Public License
;;  along with this program.  If not, see <http://www.gnu.org/licenses/>.
;;-------------------------------------------------------------------------------
.module cpct_random

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Function: cpct_getRandom_mxor_u8
;;
;;    Gets a high-quality 8-bit pseudo-random number using Marsaglia's XOR-shift 
;; algorithm.
;;
;; C Definition:
;;    <u8> <cpct_getRandom_mxor_u8> ();
;;
;; Assembly call:
;;    > call cpct_getRandom_mxor_u8_asm
;;
;; Known limitations:
;;    * This function *cannot be used from ROM*, as is uses self-modifying code.
;;
;; Details:
;;    This function uses <cpct_nextRandom_mxor_u32> to produce a stream of random 
;; bytes in groups of 4. Then, it returns each one of the last 4 random bytes produced
;; previous to calling <cpct_nextRandom_mxor_u32> again. It uses <cpct_mxor32_seed> as
;; storage buffer for the last 4 random bytes got from <cpct_nextRandom_mxor_u32>.
;;
;;    It is important to know that this function will have 2 different behaviors:
;;    * [*available*] 3 out of every 4 calls, it will only return the next random-byte from the buffer
;; (<cpct_mxor32_seed>).
;;    * [*production*] 1 out of every 4 calls, it will also call <cpct_nextRandom_mxor_u32> to produce
;; 4 new random bytes.
;;    This behaviour is reflected in the time measures.
;;
;; Destroyed Register values: 
;;      AF, BC, DE, HL
;;
;; Required memory:
;;    75 bytes divided in, 
;;    *  36 bytes (this function's code)
;;    * +35 bytes (from <cpct_nextRandom_mxor_u32> function's code)
;;    *  +4 bytes (from <cpct_mxor32_seed>)
;;
;; Time Measures:
;; (start code)
;;    Case     | microSecs (us) | CPU Cycles
;; -----------------------------------------
;;  available  |      22        |     88
;;  production |      87        |    348
;; -----------------------------------------
;;  average-4  |     38,25      |    153
;; -----------------------------------------
;; (end code)
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

_cpct_getRandom_mxor_u8::
cpct_getRandom_mxor_u8::

.globl _cpct_mxor32_seed
.globl cpct_nextRandom_mxor_u32_asm

n_randoms = .+1
   ld    a, #1          ;; [2] A = random bytes left in the seed buffer + 1
   dec   a              ;; [1]   If there are more than 0 random bytes on the buffer
   jr   nz, next_rand   ;; [2/3] just return the next one

   ;; Calculate next 32-bits random value using Marsaglia's XOR-shift
   ld   de, (_cpct_mxor32_seed+0)     ;; [6] | 
   ld   hl, (_cpct_mxor32_seed+2)     ;; [5] | DE:HL = Current 32-bits seed
   call cpct_nextRandom_mxor_u32_asm  ;; [5+37] Calculate next 32-bits pseudo-random value
   ld   (_cpct_mxor32_seed+0), de     ;; [6] |
   ld   (_cpct_mxor32_seed+2), hl     ;; [5] | Store new value as next seed
   ld   a, #4                         ;; [2] We've produced 4 random bytes

   ;; Return next random value
next_rand:  
   ld   (n_randoms), a           ;; [4] | Update number of random bytes left in the buffer (+1)

   ld   hl, #_cpct_mxor32_seed-1 ;; [3] HL points to the byte previous to the start of the 32-bits seed 
   add  l                        ;; [1] |
   ld   l, a                     ;; [1] |
   adc  h                        ;; [1] |
   sub  l                        ;; [1] |> HL += A (as A is the number of random bytes left)
   ld   l, (hl)                  ;; [2] L = next 8-bits random value 

   ret          ;; [3] Returns next 8-bits random value
