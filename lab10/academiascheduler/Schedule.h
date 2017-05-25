//
// Created by afghan on 23.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULE_H
#define JIMP_EXERCISES_SCHEDULE_H

#include<vector>
#include "SchedulingItem.h"

using namespace std;

namespace academia {
    class Schedule {
        //KLASA OPISUJĄCA CAŁOŚĆ KALENDARZA

        //POLA KLASY
        vector<SchedulingItem> schedule;

    public:
        //KONSTRUKTOR
        Schedule() {};

        //METODY
        Schedule OfTeacher(int teacher_id) const;               //wylicza fragment harmonogramu związany z danym nauczycielem akademickim
        Schedule OfRoom(int room_id) const;                     //wylicza fragment harmonogramu związany z danym pomieszczeniem
        Schedule OfYear(int year) const;                        //wylicza fragment harmonogramu dla danego roku studiów
        vector<int> AvailableTimeSlots(int n_time_slots) const; //wylicza wektor jeszcze nie zajętych okien czasowych
        void InsertScheduleItem(const SchedulingItem &item);    //wstawia nowy element planu
        size_t Size() const;                                    //zwaraca rozmiar planu

        //OPERATORY
        const SchedulingItem& operator[](std::size_t i) const;

    };
}

#endif //JIMP_EXERCISES_SCHEDULE_H
