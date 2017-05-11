//
// Created by afghan on 02.05.17.
//

#ifndef JIMP_EXERCISES_SUBTITLES_H
#define JIMP_EXERCISES_SUBTITLES_H

#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <istream>
#include <stdexcept>

using namespace std;

namespace moviesubs {

    class MicroDvdSubtitles  {

    public:
        MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int delay, int framerate, stringstream *input, stringstream *output);

    private:

    };

    //EXCEPTION CLASSES

    class NegativeFrameAfterShift {
    public:
        NegativeFrameAfterShift();
        string what() const;
    private:
    };

    class SubtitleEndBeforeStart {
    public:
        SubtitleEndBeforeStart(int line_number, string line_content);
        string what() const;
        int LineAt() const;
    private:
        int line_number;
        string line_content;
    };

    class InvalidSubtitleLineFormat {
    public:
        InvalidSubtitleLineFormat();
        string what() const;
    };
}

#endif //JIMP_EXERCISES_SUBTITLES_H