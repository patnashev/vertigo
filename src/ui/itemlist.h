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


#ifndef UI_ITEMLIST_H
#define UI_ITEMLIST_H


#include "widget.h"
#include "button.h"
#include "label.h"
#include "gfx/texture.h"
#include "gfx/image.h"


namespace ui {


class ItemList : public Widget
{
    Q_OBJECT

public:
    ItemList(Widget *parent);
    ~ItemList();

public:
    void addItem(const gfx::Image &icon, bool red, bool green);
    void selectItem(int index);

signals:
    void clicked(int);

private:
    struct Item
    {
        gfx::Image icon;
        bool red;
        bool green;
    };

private:
    void draw();
    void redraw();

private:
    gfx::Texture m_texture;
    gfx::Image m_chkGreen;
    gfx::Image m_chkRed;
    gfx::Image m_imgFrame;

    ui::Label *m_lblList;
    ui::Button *m_btnLeft;
    ui::Button *m_btnRight;
    ui::Label *m_lblLeft;
    ui::Label *m_lblRight;

    QList<Item*> m_items;
    int m_firstItem;
    int m_selectedItem;
};


} // namespace ui


#endif // UI_ITEMLIST_H