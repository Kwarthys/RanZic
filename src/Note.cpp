#include "Note.h"
#include <iostream>

Note::Note()
{
    //ctor
    std::string note = "note", pitchName = "pitch", notationName = "notations", techName = "technical";
    _descriptor = new XMLElement(note);
    XMLElement * pitch = new XMLElement(pitchName);
    XMLElement * notations = new XMLElement(notationName);
    XMLElement * technical = new XMLElement(techName);

    _descriptor->addChild(pitch);
    _descriptor->addChild(notations);
    notations->addChild(technical);
}

void Note::setStep(char c)
{
    _step = c;
    std::string stepName = "step", pitchName = "pitch", stepString = std::string(1,c);
    XMLElement * step = new XMLElement(stepName);
    step->setValue(stepString);
    _descriptor->getChildByName(pitchName)->addChild(step);
}

void Note::setOctave(short s)
{
    _octave = s;
    std::string octaveName = "octave", pitchName = "pitch", octaveValue = std::to_string(s);
    XMLElement * octave = new XMLElement(octaveName);
    octave->setValue(octaveValue);
    _descriptor->getChildByName(pitchName)->addChild(octave);
}

void Note::setduration(short s)
{
    _duration = s;
    std::string durationName = "duration", durationValue = std::to_string(s);
    XMLElement * duration = new XMLElement(durationName);
    duration->setValue(durationValue);
    _descriptor->addChild(duration);
}

void Note::setString(short s)
{
    _string = s;
    std::string stringName = "string", technicalName = "technical", stringValue = std::to_string(s);
    XMLElement * guitarString = new XMLElement(stringName);
    guitarString->setValue(stringValue);
    //_descriptor->getChildByName(technicalName)->addChild(*guitarString);
    if(_descriptor->getChildByName(technicalName) != nullptr) _descriptor->getChildByName(technicalName)->addChild(guitarString);
    else std::cout << "can't find that child" << std::endl;
}

void Note::setFret(short s)
{
    _fret = s;
    std::string fretName = "fret", technicalName = "technical", fretValue = std::to_string(s);
    XMLElement * fret = new XMLElement(fretName);
    fret->setValue(fretValue);
    //_descriptor->getChildByName(technicalName)->addChild(*fret);
    if(_descriptor->getChildByName(technicalName) != nullptr) _descriptor->getChildByName(technicalName)->addChild(fret);
    else std::cout << "can't find that child" << std::endl;
}

Note::~Note()
{
    //dtor
}
