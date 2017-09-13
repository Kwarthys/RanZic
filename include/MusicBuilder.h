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

        int MAX_NOTE_NUMBER;

    protected:
        int measureIndex;
        Note gamme[];

    private:
        void buildGamme();

};

#endif // MUSICBUILDER_H
