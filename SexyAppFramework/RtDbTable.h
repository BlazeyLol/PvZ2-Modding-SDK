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

		RtObject* GetObject(const RtWeakPtr<RtObject>& theObjectPtr);
		RtObject* AddObject(int a3, bool a4, int a5, int a6);
		bool EraseObject(const RtWeakPtr<RtObject>& theObjectPtr);
		bool Deserialize(void* theJsonSync, void* a3);
		bool Serialize(void* theJsonSync, void* a3);

	};

} // Sexy

#endif // __RtDbTable__