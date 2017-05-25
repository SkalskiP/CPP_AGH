//
// Created by afghan on 23.05.17.
//

#include <algorithm>
#include "Schedule.h"

using namespace std;

namespace academia {

    Schedule Schedule::OfTeacher(int teacher_id) const {
        //wylicza fragment harmonogramu związany z danym nauczycielem akademickim

        Schedule teacher_schedule;
        copy_if(schedule.begin(), schedule.end(), back_inserter(teacher_schedule.schedule), [teacher_id](const SchedulingItem &single_item) {return single_item.TeacherId() == teacher_id; });
        return teacher_schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        //wylicza fragment harmonogramu związany z danym pomieszczeniem

        Schedule room_schedule;
        std::copy_if(schedule.begin(), schedule.end(), back_inserter(room_schedule.schedule), [room_id](const SchedulingItem &single_item) {return single_item.RoomId() == room_id; });
        return room_schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        //wylicza fragment harmonogramu dla danego roku studiów

        Schedule year_schedule;
        std::copy_if(schedule.begin(), schedule.end(), back_inserter(year_schedule.schedule), [year](const SchedulingItem &s) {return s.RoomId() == year; });
        return year_schedule;
    }

    vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        //wylicza wektor jeszcze nie zajętych okien czasowych

        vector<int> empty_slots;

        for(int i=1; i <= n_time_slots; ++i) {
            if (none_of(schedule.begin(), schedule.end(), [i](const SchedulingItem &single_item) { return single_item.TimeSlot() == i; })) {
                empty_slots.push_back(i);
            }
        }
        return empty_slots;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &new_ex) {
        //wstawia nowy element planu

        schedule.push_back(new_ex);
    }

    size_t Schedule::Size() const {
        //zwaraca rozmiar planu

        return schedule.size();
    }

    const SchedulingItem &Schedule::operator[](size_t i) const {
        return schedule[i];
    }


}