//
// ResourceManager.cpp
//

#include "ResourceManager.h"
#include "GameCommon.h"

//

Sexy::ResourceManager* Sexy::gResourceManager = nullptr;

void Sexy::ResourceManager::RemoveUngroupedSharedImage(Image* image)
{
	CallFunc<void, ResourceManager*, Image*>(0x1263C60, this, image);
}