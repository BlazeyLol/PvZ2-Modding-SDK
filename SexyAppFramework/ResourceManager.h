//
// ResourceManager.h
//

#ifndef __ResourceManager__
#define __ResourceManager__


namespace Sexy
{

	class Image;

	class ResourceManager
	{
	public:

		void RemoveUngroupedSharedImage(Image* image);

		virtual ~ResourceManager() {}

	} extern* gResourceManager;

} // Sexy

#endif // __ResourceManager__