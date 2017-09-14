#ifndef MUSICBUILDER_H
#define MUSICBUILDER_H

#include <iostream>

#include "Measure.h"
#include "Note.h"
#include "PerlinNoise.h"

class MusicBuilder
{
    public:
        MusicBuilder();
        virtual ~MusicBuilder();

        Measure * getNewMeasure();

        Note * getRandomNote();

        const static int MAX_NOTE_NUMBER = 16;   /*** 16 Notes ***/

    protected:
        int noteIndex, rythmeIndex;
        int measureIndex;
        Note gamme[MAX_NOTE_NUMBER];
        PerlinNoise * noiseGenerator;

        double generalSeed;

    private:
        void buildGamme();

};

#endif // MUSICBUILDER_H
