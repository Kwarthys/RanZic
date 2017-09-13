#include "MusicBuilder.h"

MusicBuilder::MusicBuilder()
{
    this->measureIndex = 0;
    buildGamme();
}

MusicBuilder::~MusicBuilder()
{
    //dtor
}

Measure * MusicBuilder::getNewMeasure()
{
    return new Measure(measureIndex++);
}

void MusicBuilder::buildGamme()
{

}
