#include "pch.h"
#include "cheats.h"
#include <Windows.h>
#include "offsets.h"

// Handle
HANDLE g_proc_handle;

// States
bool g_enabled = false;
bool g_infAmmo = false;
bool g_infHealth = false;
bool g_infGrenades = false;
bool g_infJump = false;
bool g_speedH = false;

// Static pointers
uintptr_t base_player_addr;

// Patchbytes
BYTE reset_inf_ammo[2];
BYTE reset_inf_health[6];
BYTE reset_inf_jump[3];

/**
 * Toggle infinite ammo
 */
bool cheats::inf_ammo() {
	BYTE nop_it[] = { 0x90, 0x90 };

	if (g_infAmmo) {
		// Reset old 2 bytes
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaCurBullets), reset_inf_ammo, sizeof(reset_inf_ammo), NULL);
	}else {
		// Nop the 2 bytes
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaCurBullets), nop_it, sizeof(nop_it), NULL);
	}

	g_infAmmo = !g_infAmmo;
	return g_infAmmo;
}

/**
 * Toggle infinite health
 */
bool cheats::inf_health() {
	BYTE nopp[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 }; // nop x6 (health decrease instruction is 6 bytes total)

	if(g_infHealth){
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaHealthDecBomb), reset_inf_health, sizeof(reset_inf_health), NULL);
	}else{
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaHealthDecBomb), nopp, sizeof(nopp), NULL);
	}

	g_infHealth = !g_infHealth;
	return g_infHealth;
}

/**
 * Toggle infinite grenades
 */
bool cheats::inf_grenade() {
	BYTE patch[] = { 0x1 };
	BYTE old[] = { 0xFF, 0x08 };
	BYTE oldNades[1];

	if (g_infGrenades) {
		// Restore old nades
		WriteProcessMemory(g_proc_handle, (LPVOID)(base_player_addr + pGrenades), oldNades, sizeof(oldNades), NULL);

		// Restore instruction FF08
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaGrenade), old, sizeof(old), NULL);
	}else {
		// Save old nades
		ReadProcessMemory(g_proc_handle, (LPVOID)(base_player_addr + pGrenades), &oldNades, sizeof(oldNades), NULL);

		// Set nades to 1
		WriteProcessMemory(g_proc_handle, (LPVOID)(base_player_addr + pGrenades), patch, sizeof(patch), NULL);
	}

	g_infGrenades = !g_infGrenades;
	return g_infGrenades;
}

/**
 * Toggle infinite jumping
 */
bool cheats::inf_jump() {
	BYTE patch[] = { 0x32, 0xC0, // xor al, al (al = 0)
					0x90};		 // nop

	// Enable or disable
	if (g_infJump)
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaJump), reset_inf_jump, sizeof(patch), NULL);
	else
		WriteProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaJump), patch, sizeof(patch), NULL);

	g_infJump = !g_infJump;
	return g_infJump;
}

/**
 * Change current health value
 *
 * amount	- value to change to
 */
bool cheats::set_health(BYTE amount){
	if(WriteProcessMemory(g_proc_handle, (LPVOID)(base_player_addr + pHealth), &amount, sizeof(amount), NULL))
		return true;

	return false;
}

/**
 * Change current ammo value
 *
 * amount	- value to change to
 */
bool cheats::set_ammo(BYTE amount){
	if (WriteProcessMemory(g_proc_handle, (LPVOID)(base_player_addr + pAmmo), &amount, sizeof(amount), NULL))
		return true;

	return false;
}

/**
 * Change current armor value
 *
 * amount	- value to change to
 */
bool cheats::set_armor(BYTE amount){
	if (WriteProcessMemory(g_proc_handle, (LPVOID)(base_player_addr + pArmor), &amount, sizeof(amount), NULL))
		return true;

	return false;
}

/**
 * Get handle and proc id and also calculate the dynamic base player address and the original instructions for some functions that will be patched to nop
 */
bool cheats::initialize() {
	HWND hProc;
	DWORD procId;

	// Find game window
	hProc = FindWindowA(NULL, "AssaultCube");
	if (!hProc) return false;

	// Get all access to game
	GetWindowThreadProcessId(hProc, &procId);
	g_proc_handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
	if (!g_proc_handle) return false;;

	// Get dynamic local player address	
	ReadProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + LocalPlayerOffset), &base_player_addr, sizeof(base_player_addr), NULL);

	// Original decrease bullet instruction
	ReadProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaCurBullets), &reset_inf_ammo, sizeof(reset_inf_ammo), NULL);

	// Original decrease health instruction
	ReadProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaHealthDecBomb), &reset_inf_health, sizeof(reset_inf_health), NULL);

	// Original jump instruction
	ReadProcessMemory(g_proc_handle, (LPVOID)(BaseAddress + RvaJump), &reset_inf_jump, sizeof(reset_inf_jump), NULL);
	
	return true;
}