//
// Created by afghan on 23.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULINGITEM_H
#define JIMP_EXERCISES_SCHEDULINGITEM_H

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

#endif //JIMP_EXERCISES_SCHEDULINGITEM_H
