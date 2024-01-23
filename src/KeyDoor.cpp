#include "KeyDoor.h"
#include "KeyDoor.h"
#include "KeyDoor.h"
#include "KeyDoor.h"

KeyDoor::KeyDoor() 
	: m_foundkey(false), m_doorentry(false)
{
}

Location KeyDoor::GetKeyLocation()
{
	return m_keylocation;
}

Location KeyDoor::GetDoorLocation()
{
	return m_doorlocation;
}

bool KeyDoor::GetFoundKey()
{
	return m_foundkey;
}

bool KeyDoor::GetentryDoor()
{
	return m_doorentry;
}

//bool KeyDoor::FoundGift()
//{
//	return true;
//}

void KeyDoor::SetKeyLocation(Location location)
{
	m_keylocation = location;
}

void KeyDoor::SetDoorLocation(Location location)
{
	m_doorlocation = location;
}

//void KeyDoor::SetGiftLocation(Location location)
//{
//	m_giftlocation = location;
//}

void KeyDoor::UpdateKeyFoundStatus()
{
	m_foundkey = true;
}

void KeyDoor::UpdatedoorentryStatus()
{
	m_doorentry = true;
}