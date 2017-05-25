//
// Created by afghan on 23.05.17.
//

#include "SchedulingItem.h"

namespace academia {

    //KONSTRUKTOR
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
        SchedulingItem::course_id = course_id;
        SchedulingItem::teacher_id = teacher_id;
        SchedulingItem::room_id = room_id;
        SchedulingItem::time_slot = time_slot;
        SchedulingItem::year = year;
    }

    //GETER'Y PÓL KLASY [WYMUSZONE PRZEZ STRUKTURĘ TESTÓW

    int SchedulingItem::CourseId() const {
        return course_id;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }

    int SchedulingItem::RoomId() const {
        return room_id;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }

    int SchedulingItem::Year() const {
        return year;
    }
}
