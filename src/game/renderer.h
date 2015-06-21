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

#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include "util/deferreddeletable.h"

#include <QDebug>
#include <QRect>
#include <glm/mat4x4.hpp>


class QKeyEvent;
class QMouseEvent;


namespace game {


class Renderer : public util::DeferredDeletable
{
public:
    Renderer();

public:
    virtual void draw() = 0;
    virtual void activate() {}
    virtual void deactivate() {}

public:
    void setWindow(QWidget *window);
    virtual bool isCursorVisible() const { return m_cursorVisible; }
    virtual void setRect(const QRect &rect);
    QRect rect() const { return m_rect; }
    int width() const { return m_rect.width(); }
    int height() const { return m_rect.height(); }
    const glm::mat4& projectionMatrix() const { return m_projectionMatrix; }
    const glm::mat4& projectionMatrixInverted() const { return m_projectionMatrixInverted; }
    QRectF rectOrtho() const { return m_rectOrtho; }
    QPointF screenToImage(const QPointF &pos);

public:
    virtual void keyPressEvent(QKeyEvent *) {}
    virtual void keyReleaseEvent(QKeyEvent *) {}
    virtual void mousePressEvent(QMouseEvent *) {}
    virtual void mouseReleaseEvent(QMouseEvent *) {}
    virtual void mouseMoveEvent(QMouseEvent *) {}

protected:
    void showCursor();
    void hideCursor();
    void setupOrthographicMatrix(float w, float h);
    void setupGL();
    QWidget* window() const { return m_window; }

protected:
    glm::mat4 m_projectionMatrix;
    glm::mat4 m_projectionMatrixInverted;

private:
    bool m_cursorVisible;
    QRect m_rect;
    QRectF m_rectOrtho;
    QWidget *m_window;
};


} // namespace game


#endif // GAME_RENDERER_H
