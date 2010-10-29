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

#ifndef GAME_MISSION_H
#define GAME_MISSION_H


#include <QString>


namespace game {


class Mission
{
public:
    Mission(const QString &name, int station);

public:
    const QString& shortName() const { return m_shortName; }
    const QString& name() const { return m_name; }
    int station() const { return m_station; }

private:
    QString m_shortName;
    QString m_name;
    int m_station;
};


} // namespace game


#endif // GAME_MISSION_H
