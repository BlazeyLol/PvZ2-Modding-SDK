//
// RtObject.h
//

#ifndef __RtObject__
#define __RtObject__


namespace Sexy
{

    class RtClass;
    class RtSerializeContext;
    

    class RtObject
    {
    public:

		RtObject();

        static RtClass* s_rtClass;
        static RtClass* StaticGetType();
        static RtObject* Construct();
        
        virtual RtClass* GetType() const;
        virtual bool Function1() const;
        virtual ~RtObject();
        virtual bool IsType(RtClass* theClass) const;
        virtual bool Function5() const;
        virtual bool Serialize(const RtSerializeContext& serializeContext);

    };

} // Sexy


#endif // __RtObject__