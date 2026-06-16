//
// RtDbTable.h
//

#ifndef __RtDbTable__
#define __RtDbTable__


namespace Sexy
{

	template<typename _T>
	class RtWeakPtr;
	class RtObject;


	class RtDbTable
	{
	public:

		RtWeakPtr<RtObject>* AddObject(RtObject* theObject, int a4 = 1, int a5 = 1, int a6 = 0);
		RtObject* GetObject(const RtWeakPtr<RtObject>& theObjectPtr);
		bool EraseObject(const RtWeakPtr<RtObject>& theObjectPtr);

	};

} // Sexy

#endif // __RtDbTable__