//
// LazySingleton.h
//

#ifndef __LazySingleton__
#define __LazySingleton__


namespace Sexy
{

	template<typename _T>
	class LazySingleton
	{
	public:

		LazySingleton()
		{
			s_instance = this;
		}

		virtual ~LazySingleton()
		{
		}

	protected:

		static _T* s_instance;

	};

} // Sexy

#endif // __LazySingleton__