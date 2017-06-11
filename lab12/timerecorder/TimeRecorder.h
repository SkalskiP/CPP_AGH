//
// Created by afghan on 10.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <iostream>
#include <tuple>
#include <chrono>

using std::make_pair;
using time_point = std::chrono::steady_clock::time_point;

namespace profiling {

    template <class T>
    auto TimeRecorder(const T& object) {
        time_point start_time = std::chrono::steady_clock::now();
        auto value = object();
        time_point end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> dif = (end_time - start_time);
        double duration = dif.count();
        return make_pair(value, duration);
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
