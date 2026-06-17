//
// SexyAppBase.h
//

#ifndef __SexyAppBase__
#define __SexyAppBase__

#include "ButtonListener.h"
#include "DialogListener.h"
#include "GameCommon.h"
#include "drivers/app/android/AndroidAppDriver.h"
#include "drivers/audio/wwise/WwiseInteractiveAudioDriver.h"

//

namespace Sexy
{

	class ResourceManager;
	class WidgetManager;


	class SexyAppBase : public ButtonListener, public DialogListener
	{
	public:

		AndroidAppDriver* mAppDriver;
		WwiseInteractiveAudioDriver* mInteractiveAudioDriver;
		int field3;
		void* mAsyncIOFileDriver;
		void* mResStreamsDriver;
		void* mHttpDriver;
		void* mDiagDriver;
		int field8;
		int field9;
		int field10;
		int field11;
		int field12;
		int field13;
		int field14;
		int field15;
		int field16;
		int field17;
		int field18;
		int field19;
		std::string mRegKey;
		int field23;
		int field24;
		int field25;
		int field26;
		int field27;
		int field28;
		int mPreferredX;
		int mPreferredY;
		int mPreferredWidth;
		int mPreferredHeight;
		int mWidth;
		int mHeight;
		int field35;
		int field36;
		double mMusicVolume;
		double mSfxVolume;
		int field41;
		int field42;
		int field43;
		int field44;
		int field45;
		int field46;
		int field47;
		int field48;
		int field49;
		int field50;
		int field51;
		int field52;
		int field53;
		int field54;
		int field55;
		int field56;
		int field57;
		int field58;
		int field59;
		int field60;
		int field61;
		int field62;
		int field63;
		int field64;
		int field65;
		int field66;
		int field67;
		int field68;
		int field69;
		int field70;
		int field71;
		int field72;
		int field73;
		int field74;
		int field75;
		int field76;
		int field77;
		int field78;
		int field79;
		int field80;
		int field81;
		int field82;
		int field83;
		int field84;
		int field85;
		int field86;
		int field87;
		int field88;
		int field89;
		int field90;
		int field91;
		int field92;
		int field93;
		int field94;
		int field95;
		int field96;
		int field97;
		int field98;
		int field99;
		int field100;
		int field101;
		int field102;
		int field103;
		int field104;
		int field105;
		int field106;
		int field107;
		int field108;
		int field109;
		int field110;
		int field111;
		int field112;
		int field113;
		int field114;
		int field115;
		int field116;
		int field117;
		int field118;
		int field119;
		int field120;
		int field121;
		int field122;
		int field123;
		int field124;
		int field125;
		int field126;
		int field127;
		int field128;
		int field129;
		int field130;
		int field131;
		int field132;
		int field133;
		int field134;
		int field135;
		int field136;
		int field137;
		int field138;
		int field139;
		int field140;
		int field141;
		int field142;
		int field143;
		int field144;
		int field145;
		int field146;
		int field147;
		int field148;
		int field149;
		int field150;
		int field151;
		int field152;
		int field153;
		int field154;
		int field155;
		int field156;
		int field157;
		int field158;
		int field159;
		int field160;
		int field161;
		int field162;
		int field163;
		int field164;
		int field165;
		int field166;
		int field167;
		int field168;
		int field169;
		int field170;
		int field171;
		int field172;
		int field173;
		int field174;
		int field175;
		int field176;
		int field177;
		int field178;
		WidgetManager* mWidgetManager;
		int field180;
		int field181;
		int field182;
		int field183;
		int field184;
		int field185;
		int field186;
		bool unkBool1;
		bool unkBool2;
		bool unkBool3;
		bool mIsWindowed;
		int field188;
		int field189;
		int field190;
		int field191;
		bool unkBool4;
		bool unkBool5;
		bool mReadFromRegistry;
		int field193;
		int field194;
		int field195;
		int field196;
		int field197;
		int field198;
		int field199;
		int field200;
		int field201;
		int field202;
		int field203;
		int field204;
		int field205;
		int field206;
		int field207;
		int field208;
		int field209;
		int field210;
		int field211;
		int field212;
		int field213;
		int field214;
		int field215;
		int field216;
		int field217;
		int field218;
		int field219;
		int field220;
		int field221;
		int field222;
		int mMuteCount;
		int mAutoMuteCount;
		int field225;
		int field226;
		int field227;
		int field228;
		int field229;
		int field230;
		int field231;
		int field232;
		int field233;
		int field234;
		int field235;
		int field236;
		int field237;
		int field238;
		int field239;
		int field240;
		int field241;
		int field242;
		int field243;
		int field244;
		int field245;
		int field246;
		int field247;
		int field248;
		int field249;
		int field250;
		int field251;
		int field252;
		int field253;
		int field254;
		int mUpdateCount;
		int field256;
		int field257;
		int field258;
		int field259;
		int field260;
		int field261;
		int field262;
		int field263;
		int field264;
		int field265;
		int field266;
		int field267;
		int field268;
		int field269;
		int field270;
		int field271;
		int field272;
		int field273;
		int field274;
		int field275;
		bool unkBool6;
		bool unkBool7;
		bool unkBool8;
		bool mMinimized;
		int field277;
		int field278;
		int field279;
		int field280;
		int field281;
		int mFPSDirtyCount;
		int field283;
		int field284;
		int field285;
		int field286;
		int field287;
		int field288;
		int field289;
		int field290;
		int field291;
		int field292;
		int field293;
		int field294;
		int field295;
		int field296;
		int field297;
		int field298;
		int field299;
		int field300;
		int field301;
		int field302;
		int field303;
		int field304;
		int field305;
		bool mCustomCursorsEnabled;
		int field307;
		int field308;
		int field309;
		int field310;
		int field311;
		int field312;
		int field313;
		int field314;
		int field315;
		int field316;
		int field317;
		int field318;
		bool mWaitForVSync;
		int field320;
		int field321;
		int field322;
		int field323;
		int field324;
		int field325;
		int field326;
		int field327;
		int field328;
		int field329;
		int field330;
		int field331;
		int field332;
		int field333;
		int field334;
		int field335;
		int mOrigScreenWidth;
		int mOrigScreenHeight;
		int field338;
		int field339;
		int field340;
		int field341;
		int field342;
		int field343;
		int field344;
		int field345;
		int field346;
		int field347;
		int field348;
		int field349;
		int field350;
		int field351;
		int field352;
		int field353;
		ResourceManager* mResourceManager;
		int field355;
		int field356;
		int field357;
		int field358;
		int field359;
		int field360;
		int field361;
		int field362;
		int field363;
		int field364;
		int field365;
		int field366;
		int field367;
		int field368;
		int field369;
		int field370;
		int field371;
		int field372;
		int field373;
		void* mResStreamsManager;
		int field375;
		int field376;
		int field377;
		int field378;
		int field379;
		int field380;
		int field381;
		int field382;
		int field383;
		int field384;
		int field385;
		int field386;
		int field387;
		int field388;
		int field389;
		int field390;
		int field391;
		int field392;
		int field393;
		int field394;
		int field395;
		int field396;
		int field397;


		virtual void Function2() {}
		virtual void Function3() {}
		virtual void Function4() {}
		virtual void Function5() {}
		virtual void Function6() {}
		virtual void Function7() {}
		virtual void Function8() {}
		virtual void Function9() {}
		virtual void Function10() {}
		virtual void Function11() {}
		virtual void Function12() {}
		virtual void UpdateFrames() {}
		virtual void Function14() {}
		virtual void DrawScreen() {}
		virtual void Function16() {}
		virtual void Function17() {}
		virtual void Function18() {}
		virtual void Function19() {}
		virtual void Function20() {}
		virtual void Function21() {}
		virtual void Function22() {}
		virtual void Function23() {}
		virtual void Function24() {}
		virtual void Function25() {}
		virtual void Function26() {}
		virtual void Function27() {}
		virtual void Function28() {}
		virtual void Function29() {}
		virtual void Function30() {}
		virtual void Function31() {}
		virtual void Function32() {}
		virtual void Function33() {}
		virtual void Function34() {}
		virtual void Function35() {}
		virtual void Function36() {}
		virtual void Function37() {}
		virtual void Function38() {}
		virtual void Function39() {}
		virtual void Function40() {}
		virtual void Function41() {}
		virtual void Function42() {}
		virtual void Function43() {}
		virtual void Function44() {}
		virtual void Function45() {}
		virtual void Function46() {}
		virtual void Function47() {}
		virtual void Function48() {}
		virtual void Function49() {}
		virtual void Function50() {}
		virtual void Function51() {}
		virtual void Function52() {}
		virtual void Function53() {}
		virtual void Function54() {}
		virtual void Function55() {}
		virtual void Function56() {}
		virtual void Function57() {}
		virtual void Function58() {}
		virtual void Function59() {}
		virtual void Function60() {}
		virtual void Function61() {}
		virtual void Function62() {}
		virtual void Function63() {}
		virtual void Function64() {}
		virtual void Function65() {}
		virtual void Function66() {}
		virtual void Function67() {}
		virtual void Function68() {}
		virtual void Function69() {}
		virtual void Function70() {}
		virtual void Function71() {}
		virtual void Function72() {}
		virtual void Function73() {}
		virtual void Function74() {}
		virtual void Function75() {}
		virtual void Function76() {}
		virtual void Function77() {}
		virtual void Function78() {}
		virtual void Function79() {}
		virtual void Function80() {}
		virtual void Function81() {}
		virtual void Function82() {}
		virtual void Function83() {}
		virtual void Function84() {}
		virtual void Function85() {}
		virtual void Function86() {}
		virtual void Function87() {}
		virtual void Function88() {}
		virtual void Function89() {}
		virtual void Function90() {}
		virtual void Function91() {}
		virtual void Function92() {}
		virtual void Function93() {}
		virtual void Function94() {}
		virtual void Function95() {}
		virtual void Function96() {}
		virtual void Function97() {}
		virtual void Function98() {}
		virtual void Function99() {}
		virtual void Function100() {}
		virtual void Function101() {}
		virtual void Function102() {}
		virtual void Function103() {}
		virtual void Function104() {}
		virtual void Function105() {}
		virtual void Function106() {}
		virtual void Function107() {}
		virtual void Function108() {}
		virtual void Function109() {}
		virtual void Function110() {}
		virtual void Function111() {}
		virtual void Function112() {}
		virtual void Function113() {}
		virtual void Function114() {}
		virtual void Function115() {}
		virtual void Function116() {}
		virtual void Function117() {}
		virtual void Function118() {}
		virtual void Function119() {}
		virtual void Function120() {}
		virtual void Function121() {}

	} extern* gSexyAppBase;

} // Sexy

#endif // __SexyAppBase__