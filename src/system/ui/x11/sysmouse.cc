/* 
 *	PearPC
 *	mouse.cc - mouse access functions for X11
 *
 *	Copyright (C) 1999-2004 Stefan Weyergraf
 *	Copyright (C) 1999-2004 Sebastian Biallas (sb@biallas.net)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <cstdlib>

#include "system/systhread.h"
#include "sysx11.h"

#include "system/display.h"
#include "system/mouse.h"

class X11SystemMouse: public SystemMouse {
public:

	virtual bool handleEvent(const SystemEvent &ev)
	{
		return SystemMouse::handleEvent(ev);
	}
};

SystemMouse *allocSystemMouse()
{
	if (gMouse) return NULL;
	return new X11SystemMouse();
}
