//
// Created by afghan on 25.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace academia {

    class NoViableSolutionFound : public runtime_error {

    public:
        NoViableSolutionFound() : runtime_error("tworzenie planu nie powiodło się") {}

    };

}

namespace academia {
    class SchedulingItem {
        //KLASA OPISUJĄCA POJEDYŃCZĄ REZERWACJĘ SALI W KALENDARZU

        //POLA KLASY
        int course_id;      //identyfikator kursu
        int teacher_id;     //identyfikator nauczyciela akademickiego prowadzącego te zajęcia o tej godzinie
        int room_id;        //identyfikator pomieszczenia w którym odbywają się zajęcia
        int time_slot;      //okno czasowe, w którym odbywają się zajęcia
        int year;           //rok studiów na którym obowiązuje przedmiot

    public:
        //KONSTRUKTOR
        SchedulingItem(int, int, int, int, int);

        //GETER'Y PÓL KLASY [WYMUSZONE PRZEZ STRUKTURĘ TESTÓW
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;


    };
}

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

#endif //JIMP_EXERCISES_SCHEDULER_H
