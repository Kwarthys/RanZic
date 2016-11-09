#include "Instrument.h"

short Instrument::GLOBAL_ID = 0;

Instrument::Instrument()
{
    _descriptor = new XMLElement("score-part");
    _shortid = GLOBAL_ID++;
    _id = "id=\"P" + std::to_string(_shortid) + "\"";
    _descriptor->addAttribute(_id);
    XMLElement * midiInstru = new XMLElement("midi-instrument");
    midiInstru->addAttribute(_id);
    _descriptor->addChild(midiInstru);

}

Instrument::~Instrument()
{
    //dtor
    delete(_descriptor);
}
