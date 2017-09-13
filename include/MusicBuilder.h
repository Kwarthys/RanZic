#ifndef MUSICBUILDER_H
#define MUSICBUILDER_H

#include "Measure.h"
#include "Note.h"

class MusicBuilder
{
    public:
        MusicBuilder();
        virtual ~MusicBuilder();

        Measure * getNewMeasure();

        const static int MAX_NOTE_NUMBER = 16;   /*** 16 Notes ***/

    protected:
        int measureIndex;
        Note gamme[MAX_NOTE_NUMBER];

    private:
        void buildGamme();

};

#endif // MUSICBUILDER_H
