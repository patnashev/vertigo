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

#ifndef GFX_VIDEO_H
#define GFX_VIDEO_H

#include "colortable.h"
#include "image.h"

#include "util/file.h"

#include <QTime>

namespace gfx {

class Video
{
public:
    Video();
    Video(const QString &filename);

public:
    void open(const QString &filename);
    void play();
    void playLoop();
    void stop();
    bool isPlaying() const { return m_playing; }
    void setFrameRate(int frameRate);
    Image getFrame();
    QByteArray getAudio();
    bool atEnd() const;
    std::uint32_t width() const { return m_width; }
    std::uint32_t height() const { return m_height; }

private:
    void reset();
    void mergeChannel(QByteArray &data, int size, int channelIndex);
    void loadColorTable(int size);
    void loadVideoFull(int size);
    void loadVideoDiff(int size);
    void decode(int size, std::vector<char> &output);
    bool decompressLZW(int size, std::vector<char> &out);
    QImage createImage();
    QImage createEmpty();

private:
    struct Entry
    {
        enum Type { ColorTable = 5, VideoFull = 1, VideoDiff = 2, AudioLeft = 3, AudioRight = 4 };
        Type type;
        std::uint32_t length;
        std::uint32_t offset;
    };

    std::vector<Entry> m_entries;
    ColorTable m_colorTable;
    std::vector<char> m_indexMap;
    std::vector<char> m_frame;
    util::File m_file;

    std::uint32_t m_width;
    std::uint32_t m_height;
    std::uint32_t m_videoPos;
    std::uint32_t m_nextVideoPos;
    std::uint32_t m_audioPos;
    std::uint32_t m_lastAudioPos;
    bool m_hasAudio;
    std::uint32_t m_frameRate;

    QTime m_time;
    bool m_playing;
    bool m_looping;
};

} // namespace gfx

#endif // GFX_VIDEO_H
