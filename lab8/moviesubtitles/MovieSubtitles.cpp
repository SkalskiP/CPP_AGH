//
// Created by afghan on 02.05.17.
//

#include "MovieSubtitles.h"

using namespace moviesubs;
using namespace std;

MicroDvdSubtitles::MicroDvdSubtitles() {}

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, stringstream *input, stringstream *output) {

    //Buffor, przechowuje obecnie analizowaną linię
    string currentLine, fullLine;

    //Numer klatki otwierającej i zamykającej oraz treść napisu
    string openingFrameStr, endingFrameStr;
    int openingFrameNum = 0, endingFrameNum = 0;
    string subtitleContent;

    regex pharse{R"((\{)([0-9]+)(\})(\{)([0-9]+)(\}))"};
    std::smatch matches;

    int line_counter = 0;

    if(framerate <= 0) {
        throw invalid_argument("Framerate can not be smaller than 0.");
        //Niepoprawne dane wejściowe do metody - framerate nie może być ujemny
    }

    while (std::getline(*input, currentLine)) {
        line_counter++;

        if (std::regex_search(currentLine, matches, pharse)) {

            openingFrameStr = matches[2];
            endingFrameStr =  matches[5];
            subtitleContent = matches.suffix();

        } else {
            throw InvalidSubtitleLineFormat();
            //Niepoprawne dane wejściowe do metody - brak sparowanych nawiasów w konstrukcji lini
        }

        openingFrameNum = stoi(openingFrameStr);
        endingFrameNum = stoi(endingFrameStr);

        openingFrameNum += delay * framerate / 1000;
        endingFrameNum += delay * framerate / 1000;

        if(openingFrameNum < 0 || endingFrameNum < 0) {
            throw NegativeFrameAfterShift();
        }

        if(openingFrameNum > endingFrameNum) {
            throw SubtitleEndBeforeStart(line_counter, currentLine);
        }

        *output << "{" << openingFrameNum << "}" << "{" << endingFrameNum << "}" << subtitleContent << "\n";
    }
}

NegativeFrameAfterShift::NegativeFrameAfterShift() {}

string NegativeFrameAfterShift::what() const {
    return "NegativeFrameAfterShift";
}

SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_number, std::string line_content) {
    this->line_number = line_number;
    this->line_content = line_content;
}

string SubtitleEndBeforeStart::what() const {
    std::string to_return = "At line ";
    to_return += to_string(this->line_number);
    to_return +=  ": ";
    to_return +=  this->line_content;
    return to_return;
}

int SubtitleEndBeforeStart::LineAt() const {
    return this->line_number;
}

InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() {}

string InvalidSubtitleLineFormat::what() const {
    return "InvalidSubtitleLineFormat";
}
