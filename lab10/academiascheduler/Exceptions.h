//
// Created by afghan on 24.05.17.
//

#ifndef JIMP_EXERCISES_EXCEPTIONS_H
#define JIMP_EXERCISES_EXCEPTIONS_H

#include <stdexcept>
using namespace std;

namespace academia {

    class NoViableSolutionFound : public runtime_error {

    public:
        NoViableSolutionFound() : runtime_error("tworzenie planu nie powiodło się") {}

    };

}

#endif //JIMP_EXERCISES_EXCEPTIONS_H
