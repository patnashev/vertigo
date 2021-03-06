/***************************************************************************
 *  Copyright (C) 2010  Philipp Nordhus                                    *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#ifndef HUD_SONARMONITOR_H
#define HUD_SONARMONITOR_H


#include "util/geometry2d.h"
#include "ui/widget.h"
#include "gfx/texture.h"


namespace hud {


class HUD;


class SonarMonitor : public ui::Widget
{
public:
    SonarMonitor(HUD *hud, Point point, int radius, int scale);

public:
    int scale() const { return m_scale; }
    void setScale(int scale) { m_scale = scale; }

protected:
    void draw();

private:
    HUD *m_hud;
    Point m_point;
    int m_radius;
    int m_scale;

    gfx::Texture m_center;
    gfx::Texture m_nav;
    gfx::Texture m_friend;
    gfx::Texture m_enemy;
    gfx::Texture m_target;
};


} // namespace hud


#endif // HUD_SONARMONITOR_H
