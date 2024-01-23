#pragma once
#include "Location.h"

class KeyDoor
{
public:
	KeyDoor();
	Location GetKeyLocation();
	Location GetDoorLocation();
	Location GetGiftLocation();

	void SetKeyLocation(Location location);
	void SetDoorLocation(Location location);
	void SetGiftLocation(Location location);

	bool GetFoundKey();
	bool GetentryDoor();
	////bool FoundGift();
	
	void UpdateKeyFoundStatus();
	void UpdatedoorentryStatus();
private:
	Location m_keylocation;
	bool m_foundkey; // if the mouse has found the key

	Location m_doorlocation;
	bool m_doorentry; // helps us to know if to print the door

	//Location m_giftlocation;
	////bool m_foundgift;
};