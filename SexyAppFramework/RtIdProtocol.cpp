//
// RtIdProtocol.cpp
//

#include "RtIdProtocol.h"

//

RT_CLASS_IMPLEMENT(Sexy::RtIdProtocol);
void Sexy::RtIdProtocol::StaticClassInit()
{}


Sexy::RtIdProtocol::RtIdProtocol()
{}

Sexy::RtIdProtocol::~RtIdProtocol()
{}


void Sexy::RtIdProtocol::AssignDelegate(const Delegate1wRet<RtId, RtObject*>& delegate)
{
	m_delegate = delegate;
}