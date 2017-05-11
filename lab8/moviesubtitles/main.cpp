//
// Created by afghan on 02.05.17.
//

#include "MovieSubtitles.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace moviesubs;

int main() {

    auto subs = make_unique<MicroDvdSubtitles>();
    stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
    stringstream out;
    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);

    return 0;
}

