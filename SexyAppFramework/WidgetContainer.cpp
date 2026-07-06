//
// WidgetContainer.cpp
//

#include "WidgetContainer.h"
#include "WidgetManager.h"
#include "Widget.h"
#include "Graphics.h"

//

RT_CLASS_IMPLEMENT(WidgetContainer);
void Sexy::WidgetContainer::StaticClassInit()
{

}


Sexy::WidgetContainer::WidgetContainer()
{
	mWidgetManager = nullptr;
	mParent = nullptr;
	mX = 0;
	mY = 0;
	mWidth = 0;
	mHeight = 0;
	mUpdateIterator = mWidgets.end();
	mLastWMUpdateCount = 0;
	mUpdateCnt = 0;
	mCanDraw = false;
	mPriority = 0;
	mZOrder = 0;
	mHasAlpha = true;
}

Sexy::WidgetContainer::~WidgetContainer()
{}


Sexy::Widget* Sexy::WidgetContainer::GetWidgetAtHelper(int x, int y, int theFlags, bool* found, int* theWidgetX, int* theWidgetY)
{
	bool belowModal = false;

	ModFlags(theFlags, mWidgetFlagsMod);

	WidgetList::reverse_iterator anItr = mWidgets.rbegin();
	while (anItr != mWidgets.rend())
	{
		Widget* aWidget = *anItr;

		int aCurFlags = theFlags;
		ModFlags(aCurFlags, aWidget->mWidgetFlagsMod);
		if (belowModal) ModFlags(aCurFlags, mWidgetManager->mBelowModalFlagsMod);

		if (aCurFlags & WIDGETFLAGS_ALLOW_MOUSE)
		{
			if (aWidget->mVisible)
			{
				bool childFound;
				Widget* aCheckWidget = aWidget->GetWidgetAtHelper(x - aWidget->mX, y - aWidget->mY, aCurFlags, &childFound, theWidgetX, theWidgetY);
				if ((aCheckWidget != NULL) || (childFound))
				{
					*found = true;
					return aCheckWidget;
				}

				if ((aWidget->mMouseVisible) && (aWidget->GetInsetRect().Contains(x, y)))
				{
					*found = true;

					if (aWidget->IsPointVisible(x - aWidget->mX, y - aWidget->mY))
					{
						if (theWidgetX)
							*theWidgetX = x - aWidget->mX;
						if (theWidgetY)
							*theWidgetY = y - aWidget->mY;
						return aWidget;
					}
				}
			}
		}

		belowModal |= aWidget == mWidgetManager->mBaseModalWidget;

		++anItr;
	}

	*found = false;
	return GetWidgetAt(x, y, theFlags, found, theWidgetX, theWidgetY);
}

bool Sexy::WidgetContainer::IsBelowHelper(Widget* theWidget1, Widget* theWidget2, bool* found)
{
	WidgetList::iterator anItr = mWidgets.begin();
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;

		if (aWidget == theWidget1)
		{
			*found = true;
			return true;
		}
		else if (aWidget == theWidget2)
		{
			*found = true;
			return false;
		}

		bool result = aWidget->IsBelowHelper(theWidget1, theWidget2, found);
		if (*found)
			return result;

		++anItr;
	}

	return false;
}

void Sexy::WidgetContainer::InsertWidgetHelper(const WidgetList::iterator& where, Widget* theWidget)
{
	// Search forwards
	WidgetList::iterator anItr = where;
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;
		if (aWidget->mZOrder >= theWidget->mZOrder)
		{
			if (anItr != mWidgets.begin())
			{
				WidgetList::iterator anItr2 = anItr;
				anItr2--;
				aWidget = *anItr;
				if (aWidget->mZOrder > theWidget->mZOrder) // need to search backwards
					break;
			}

			mWidgets.insert(anItr, theWidget);
			return;
		}
		++anItr;
	}

	// Search backwards
	while (anItr != mWidgets.begin())
	{
		--anItr;
		Widget* aWidget = *anItr;
		if (aWidget->mZOrder <= theWidget->mZOrder)
		{
			mWidgets.insert(++anItr, theWidget);
			return;
		}
	}

	// It goes at the beginning
	mWidgets.push_front(theWidget);
}


Sexy::Widget* Sexy::WidgetContainer::GetWidgetAt(int x, int y, int theFlags, bool* found, int* theWidgetX, int* theWidgetY)
{
	return nullptr;
}

Sexy::Rect Sexy::WidgetContainer::GetRect()
{
	return Rect(mX, mY, mWidth, mHeight);
}

Sexy::Rect Sexy::WidgetContainer::GetClipRect()
{
	return Rect(0, 0, mWidth, mHeight);
}

bool Sexy::WidgetContainer::Intersects(WidgetContainer* theWidget)
{
	return GetRect().Intersects(theWidget->GetRect());
}

void Sexy::WidgetContainer::AddWidget(Widget* theWidget)
{
	if (std::find(mWidgets.begin(), mWidgets.end(), theWidget) == mWidgets.end())
	{
		InsertWidgetHelper(mWidgets.end(), theWidget);
		theWidget->mWidgetManager = mWidgetManager;
		theWidget->mParent = this;

		if (mWidgetManager)
		{
			theWidget->AddedToManager(mWidgetManager);
			theWidget->MarkDirtyFull();
			mWidgetManager->RehupMouse();
		}

		MarkDirty();
	}
}

void Sexy::WidgetContainer::RemoveWidget(Widget* theWidget)
{
	WidgetList::iterator anItr = std::find(mWidgets.begin(), mWidgets.end(), theWidget);
	if (anItr != mWidgets.end())
	{
		theWidget->WidgetRemovedHelper();
		theWidget->mParent = nullptr;

		bool erasedCur = (anItr == mUpdateIterator);
		mWidgets.erase(anItr++);
		if (erasedCur)
		{
			mUpdateIterator = anItr;
			mUpdateIteratorModified = true;
		}
	}
}

bool Sexy::WidgetContainer::HasWidget(Widget* theWidget)
{
	return std::find(mWidgets.begin(), mWidgets.end(), theWidget) != mWidgets.end();
}

void Sexy::WidgetContainer::DisableWidget(Widget* theWidget)
{}

void Sexy::WidgetContainer::UpdateMousePos(Widget* theWidget)
{}

void Sexy::WidgetContainer::RemoveAllWidgets(bool doDelete, bool recursive)
{
	while (!mWidgets.empty())
	{
		Widget* aWidget = mWidgets.front();
		RemoveWidget(aWidget);

		if (recursive)
		{
			aWidget->RemoveAllWidgets(doDelete, recursive);
		}

		if (doDelete)
		{
			delete aWidget;
		}
	}
}

void Sexy::WidgetContainer::DisableAllWidgets(Widget* theWidget)
{
	while (mUpdateIterator != mWidgets.end())
	{
		mUpdateIteratorModified = false;

		Widget* aWidget = *mUpdateIterator;
		aWidget->SetDisabled(theWidget->mDisabled);
		
		if (!mUpdateIteratorModified)
			++mUpdateIterator;
	}

	mUpdateIteratorModified = true;
}

void Sexy::WidgetContainer::RemoveModFlags(bool allowMouse)
{
	int aRemoveFlags = mWidgetFlagsMod.mRemoveFlags & 0xFFFFFFEF;

	if (allowMouse)
	{
		aRemoveFlags |= WIDGETFLAGS_ALLOW_MOUSE;
	}

	mWidgetFlagsMod.mRemoveFlags = aRemoveFlags;
}

void Sexy::WidgetContainer::SetFocus(Widget* theWidget)
{}

bool Sexy::WidgetContainer::IsBelow(Widget* theWidget1, Widget* theWidget2)
{
	bool found = false;
	return IsBelowHelper(theWidget1, theWidget2, &found);
}

void Sexy::WidgetContainer::MarkAllDirty()
{
	MarkDirty();

	WidgetList::iterator anItr = mWidgets.begin();
	while (anItr != mWidgets.end())
	{
		(*anItr)->mDirty = true;
		(*anItr)->MarkAllDirty();
		++anItr;
	}
}

void Sexy::WidgetContainer::BringToFront(Widget* theWidget)
{
	WidgetList::iterator anItr = std::find(mWidgets.begin(), mWidgets.end(), theWidget);
	if (anItr != mWidgets.end())
	{
		if (anItr == mUpdateIterator)
		{
			mUpdateIterator++;
			mUpdateIteratorModified = true;
		}

		mWidgets.erase(anItr);
		InsertWidgetHelper(mWidgets.end(), theWidget);

		theWidget->OrderInManagerChanged();
	}
}

void Sexy::WidgetContainer::BringToBack(Widget* theWidget)
{
	WidgetList::iterator anItr = std::find(mWidgets.begin(), mWidgets.end(), theWidget);
	if (anItr != mWidgets.end())
	{
		if (anItr == mUpdateIterator)
		{
			mUpdateIterator++;
			mUpdateIteratorModified = true;
		}

		mWidgets.erase(anItr);
		InsertWidgetHelper(mWidgets.begin(), theWidget);

		theWidget->OrderInManagerChanged();
	}
}

void Sexy::WidgetContainer::PutBehind(Widget* theWidget, Widget* theRefWidget)
{
	WidgetList::iterator anItr = std::find(mWidgets.begin(), mWidgets.end(), theWidget);
	if (anItr != mWidgets.end())
	{
		if (anItr == mUpdateIterator)
		{
			mUpdateIterator++;
			mUpdateIteratorModified = true;
		}

		mWidgets.erase(anItr);
		anItr = std::find(mWidgets.begin(), mWidgets.end(), theRefWidget);
		InsertWidgetHelper(anItr, theWidget);

		theWidget->OrderInManagerChanged();
	}
}

void Sexy::WidgetContainer::PutInfront(Widget* theWidget, Widget* theRefWidget)
{
	WidgetList::iterator anItr = std::find(mWidgets.begin(), mWidgets.end(), theWidget);
	if (anItr != mWidgets.end())
	{
		if (anItr == mUpdateIterator)
		{
			mUpdateIterator++;
			mUpdateIteratorModified = true;
		}

		mWidgets.erase(anItr);
		anItr = std::find(mWidgets.begin(), mWidgets.end(), theRefWidget);
		if (anItr != mWidgets.end())
			anItr++;
		InsertWidgetHelper(anItr, theWidget);

		theWidget->OrderInManagerChanged();
	}
}

Sexy::Point Sexy::WidgetContainer::GetAbsPos()
{
	if (mParent)
		return Point(mX, mY);
	else
		return Point(mX, mY) + mParent->GetAbsPos();
}

void Sexy::WidgetContainer::MarkDirty()
{
	if (mParent)
	{
		mParent->MarkDirty(this);
	}
	else
	{
		mDirty = true;
	}
}

void Sexy::WidgetContainer::MarkDirtyFull()
{
	if (mParent)
	{
		mParent->MarkDirtyFull(this);
	}
	else
	{
		mDirty = true;
	}
}

void Sexy::WidgetContainer::MarkDirtyFull(WidgetContainer* theWidget)
{
	// Mark all things dirty that are under or over this widget

	// Mark ourselves dirty
	MarkDirtyFull();

	theWidget->mDirty = true;

	// Top-level windows are treated differently, as marking a child dirty always
	//  causes a parent redraw which always causes all children to redraw
	if (mParent != NULL)
		return;

	WidgetList::iterator aFoundWidgetItr = std::find(mWidgets.begin(), mWidgets.end(), theWidget);
	if (aFoundWidgetItr == mWidgets.end())
		return;

	WidgetList::iterator anItr = aFoundWidgetItr;
	if (anItr != mWidgets.begin())
	{
		anItr--;

		for (;;)
		{
			Widget* aWidget = *anItr;

			if (aWidget->mVisible)
			{
				if ((!aWidget->mHasTransparencies) && (!aWidget->mHasAlpha))
				{
					// Clip the widget's bounds to the screen and check if it fully overlapped by this non-transparent widget underneath it
					// If it is fully overlapped then we can stop marking dirty underneath it since it's not transparent.
					Rect aRect = Rect(theWidget->mX, theWidget->mY, theWidget->mWidth, theWidget->mHeight).Intersection(Rect(0, 0, mWidth, mHeight));
					if ((aWidget->Contains(aRect.mX, aRect.mY) &&
						 (aWidget->Contains(aRect.mX + aRect.mWidth - 1, aRect.mY + aRect.mHeight - 1))))
					{
						// If this widget is fully contained within a lower widget, there is no need to dig down
						// any deeper.
						aWidget->MarkDirty();
						break;
					}
				}

				if (aWidget->Intersects(theWidget))
					MarkDirty(aWidget);
			}

			if (anItr == mWidgets.begin())
				break;

			--anItr;
		}
	}

	anItr = aFoundWidgetItr;
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;
		if ((aWidget->mVisible) && (aWidget->Intersects(theWidget)))
			MarkDirty(aWidget);

		++anItr;
	}
}

void Sexy::WidgetContainer::MarkDirty(WidgetContainer* theWidget)
{
	if (theWidget->mDirty) {
		return;
	}

	// Only mark things dirty that are on top of this widget
	// Mark ourselves dirty
	MarkDirty();

	theWidget->mDirty = true;

	// Top-level windows are treated differently, as marking a child dirty always
	//  causes a parent redraw which always causes all children to redraw
	if (mParent) {
		return;
	}

	if (theWidget->mHasAlpha)
	{
		MarkDirtyFull(theWidget);
	}
	else
	{
		bool found = false;
		WidgetList::iterator anItr = mWidgets.begin();
		while (anItr != mWidgets.end())
		{
			Widget* aWidget = *anItr;
			if (aWidget == theWidget)
			{
				found = true;
			}
			else if (found)
			{
				if ((aWidget->mVisible) && (aWidget->Intersects(theWidget)))
				{
					MarkDirty(aWidget);
				}
			}

			++anItr;
		}
	}
}

void Sexy::WidgetContainer::AddedToManager(WidgetManager* theWidgetManager)
{
	WidgetList::iterator anItr = mWidgets.begin();
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;

		aWidget->mWidgetManager = theWidgetManager;
		aWidget->AddedToManager(theWidgetManager);
		++anItr;

		MarkDirty();
	}
}

void Sexy::WidgetContainer::RemovedFromManager(WidgetManager* theWidgetManager)
{
	for (WidgetList::iterator anItr = mWidgets.begin(); anItr != mWidgets.end(); ++anItr)
	{
		Widget* aWidget = *anItr;

		theWidgetManager->DisableWidget(aWidget);
		aWidget->RemovedFromManager(theWidgetManager);
		aWidget->mWidgetManager = nullptr;
	}

	if (theWidgetManager->mPopupCommandWidget == this) {
		theWidgetManager->mPopupCommandWidget = nullptr;
	}
}

void Sexy::WidgetContainer::Update()
{
	mUpdateCnt++;
}

void Sexy::WidgetContainer::UpdateAll(ModalFlags* theFlags)
{
	AutoModalFlags anAutoModalFlags(theFlags, mWidgetFlagsMod);

	if (theFlags->GetFlags() & WIDGETFLAGS_MARK_DIRTY)
		MarkDirty();

	// Can update?
	WidgetManager* aWidgetManager = mWidgetManager;
	if (aWidgetManager == NULL)
		return;

	if (theFlags->GetFlags() & WIDGETFLAGS_UPDATE)
	{
		if (mLastWMUpdateCount != mWidgetManager->mUpdateCnt)
		{
			mLastWMUpdateCount = mWidgetManager->mUpdateCnt;
			Update();
		}
	}

	mUpdateIterator = mWidgets.begin();

	while (mUpdateIterator != mWidgets.end())
	{
		mUpdateIteratorModified = false;

		Widget* aWidget = *mUpdateIterator;
		if (aWidget == aWidgetManager->mBaseModalWidget)
			theFlags->mIsOver = true;

		aWidget->UpdateAll(theFlags);

		if (!mUpdateIteratorModified)
			++mUpdateIterator;
	}

	mUpdateIteratorModified = true; // prevent incrementing iterator off the end of the list
}

void Sexy::WidgetContainer::UpdateF(float theFrac)
{}

void Sexy::WidgetContainer::UpdateFAll(ModalFlags* theFlags, float theFrac)
{
	AutoModalFlags anAutoModalFlags(theFlags, mWidgetFlagsMod);

	// Can update?
	if (theFlags->GetFlags() & WIDGETFLAGS_UPDATE)
	{
		UpdateF(theFrac);
	}

	mUpdateIterator = mWidgets.begin();
	while (mUpdateIterator != mWidgets.end())
	{
		mUpdateIteratorModified = false;

		Widget* aWidget = *mUpdateIterator;
		if (aWidget == mWidgetManager->mBaseModalWidget)
			theFlags->mIsOver = true;

		aWidget->UpdateFAll(theFlags, theFrac);

		if (!mUpdateIteratorModified)
			++mUpdateIterator;
	}

	mUpdateIteratorModified = true; // prevent incrementing iterator off the end of the list
}

void Sexy::WidgetContainer::Draw(Graphics* g)
{}

void Sexy::WidgetContainer::DrawAll(ModalFlags* theFlags, Graphics* g)
{
	if (mPriority > mWidgetManager->mMinDeferredOverlayPriority)
		mWidgetManager->FlushDeferredOverlayWidgets(mPriority);

	AutoModalFlags anAutoModalFlags(theFlags, mWidgetFlagsMod);

	if ((mClip) && (theFlags->GetFlags() & WIDGETFLAGS_CLIP))
		g->ClipRect(GetClipRect());

	if (mWidgets.size() == 0)
	{
		if (theFlags->GetFlags() & WIDGETFLAGS_DRAW)
			Draw(g);
		return;
	}

	if (theFlags->GetFlags() & WIDGETFLAGS_DRAW)
	{
		g->PushState();
		Draw(g);
		g->PopState();
	}

	static Rect sClipRect = Rect();

	if (mCanDraw)
	{
		if (mClipParent)
		{
			Rect aParentRect = mParent->GetClipRect();
			sClipRect = Rect(mParent->mX + aParentRect.mX, mParent->mY + aParentRect.mY, aParentRect.mWidth, aParentRect.mHeight);
		}
		else
			sClipRect = GetClipRect();

		sClipRect.mX -= mClipOrigin;
		sClipRect.mY -= mClipOrigin;
		sClipRect.mWidth += 2 * mClipOrigin;
		sClipRect.mHeight += 2 * mClipOrigin;
	}

	WidgetList::iterator anItr = mWidgets.begin();
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;

		if (aWidget->mVisible)
		{
			if (aWidget == mWidgetManager->mBaseModalWidget)
				theFlags->mIsOver = true;

			if (!mCanDraw)
			{
				g->PushState();
				g->Translate(aWidget->mX, aWidget->mY);
				aWidget->DrawAll(theFlags, g);
				aWidget->mDirty = false;
				g->PopState();
			}
		}

		++anItr;
	}
}

void Sexy::WidgetContainer::SysColorChangedAll()
{
	SysColorChanged();

	static int aDepthCount = 0;
	if (mWidgets.size() > 0)
		aDepthCount++;

	WidgetList::iterator anItr = mWidgets.begin();
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;

		aWidget->SysColorChangedAll();
		++anItr;
	}
}

void Sexy::WidgetContainer::SysColorChanged()
{}

bool Sexy::WidgetContainer::IterateAllWidgets()
{
	WidgetList::iterator anItr = mWidgets.begin();
	while (anItr != mWidgets.end())
	{
		Widget* aWidget = *anItr;
		if (aWidget->IterateAllWidgets())
			return true;

		++anItr;
	}

	return false;
}

void Sexy::WidgetContainer::InitClip(bool canDraw, bool clipParent, bool clipOrigin)
{
	mClipParent = clipParent;
	mCanDraw = true;
	clipOrigin = clipOrigin;
}