#include "MusicBuilder.h"

MusicBuilder::MusicBuilder()
{
    this->measureIndex = 0;
    this->noteIndex = 0;
    this->rythmeIndex = 0;
    buildGamme();
    this->noiseGenerator = new PerlinNoise();
}

MusicBuilder::~MusicBuilder()
{
    //dtor
}

Measure * MusicBuilder::getNewMeasure()
{
    return new Measure(measureIndex++);
}

Note * MusicBuilder::getRandomNote()
{
    double noteSeed = (1.0*noteIndex)/5;
    double rythmeSeed = (rythmeIndex*1.0)/2;
    double note = this->noiseGenerator->noise(noteSeed, 0 , 0);
    double rythme = this->noiseGenerator->noise(rythmeSeed, 0 , 0);

    this->noteIndex++;
    this->rythmeIndex++;

    int gameIndex = (int)(note*this->MAX_NOTE_NUMBER);

    Note * toReturn = new Note();
    toReturn->setFret(this->gamme[gameIndex].getFret());
    toReturn->setString(this->gamme[gameIndex].getString());
    toReturn->setDuration(rythme > 0.5 ? 2 : 1);

    std::cout << gameIndex << std::endl;

    return toReturn;
}

void MusicBuilder::buildGamme()
{
    int i = 0;

    /*** 16 Notes ***/

    Note mi0 = Note();
    mi0.setFret(0);
    mi0.setString(6);
    this->gamme[i++] = mi0;

    Note n36 = Note();
    n36.setFret(3);
    n36.setString(6);
    this->gamme[i++] = n36;

    Note n56 = Note();
    n56.setFret(5);
    n56.setString(6);
    this->gamme[i++] = n56;

    Note n86 = Note();
    n86.setFret(8);
    n86.setString(6);
    this->gamme[i++] = n86;

    Note n55 = Note();
    n55.setFret(5);
    n55.setString(5);
    this->gamme[i++] = n55;

    Note n75 = Note();
    n75.setFret(7);
    n75.setString(5);
    this->gamme[i++] = n75;

    Note n54 = Note();
    n54.setFret(5);
    n54.setString(4);
    this->gamme[i++] = n54;

    Note n74 = Note();
    n74.setFret(7);
    n74.setString(4);
    this->gamme[i++] = n74;

    Note n53 = Note();
    n53.setFret(5);
    n53.setString(3);
    this->gamme[i++] = n53;

    Note n73 = Note();
    n73.setFret(7);
    n73.setString(3);
    this->gamme[0] = n73;

    Note n52 = Note();
    n52.setFret(5);
    n52.setString(2);
    this->gamme[i++] = n52;

    Note n82 = Note();
    n82.setFret(8);
    n82.setString(2);
    this->gamme[i++] = n82;

    Note n51 = Note();
    n51.setFret(5);
    n51.setString(1);
    this->gamme[i++] = n51;

    Note n81 = Note();
    n81.setFret(8);
    n81.setString(1);
    this->gamme[i++] = n81;

    Note n101 = Note();
    n101.setFret(10);
    n101.setString(1);
    this->gamme[i++] = n101;

    Note n121 = Note();
    n121.setFret(12);
    n121.setString(1);
    this->gamme[i++] = n121;
}
