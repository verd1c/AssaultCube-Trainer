#pragma once

namespace cheats {
	/**
 * Toggle infinite ammo
 */
	bool inf_ammo();

	bool inf_health();

	bool inf_grenade();

	bool inf_jump();

	bool set_health(BYTE amount);

	bool set_ammo(BYTE amount);

	bool set_armor(BYTE amount);

	bool initialize();
}
