//
// Created by afghan on 14.03.17.
//

#include "MinimalTimeDifference.h"
using namespace std;
namespace minimaltimedifference {

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        int min_dif = 3601;
        vector <int> minutes;
        for (string time : times) {
            minutes.push_back(ToMinutes(time));
        }
        for (int index = 0; index < minutes.size() - 1; index++) {
            for (int index2 = index+1; index2 < minutes.size(); index2++) {
                int dif = abs(minutes[index2] - minutes[index]);
                if (dif > 720) {
                    dif = 1440 - dif;
                }
                if (dif < min_dif) {
                    min_dif = dif;
                }
            }
        }
        return min_dif;
    }

    unsigned int ToMinutes(std::string time_HH_MM) {
        regex wzor {R"((\d{1,2}):(\d{2}))"};
        smatch matches;
        if (regex_match(time_HH_MM, matches, wzor)) {

            string hours = matches[1].str();
            string minutes = matches[2].str();

            int number_hours = atoi(hours.c_str());
            int number_minutes = atoi(minutes.c_str());
            int total_minutes = number_hours*60 + number_minutes;

            return total_minutes;
        }
    }



}



