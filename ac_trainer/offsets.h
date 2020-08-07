#pragma once
#ifndef _WINDEF_
typedef unsigned long DWORD;
#endif

// Base
DWORD RvaCurBullets = 0x637E9;
DWORD RvaHealthDecBomb = 0x2CA5E;
DWORD RvaGrenade = 0x63378;
DWORD RvaJump = 0x5AC26;
DWORD BaseAddress = 0x400000;
DWORD LocalPlayerOffset = 0x109B74;

// Local Player
DWORD pSpeed = 0x80;
DWORD pArmor = 0xFC;
DWORD pName = 0x225;
DWORD pHealth = 0x00F8;
DWORD xPos = 0x0038;
DWORD yPos = 0x003C;
DWORD zPos = 0x0040;
DWORD pJump = 0x69;
DWORD pAmmo = 0x0150;
DWORD pGrenades = 0x158;