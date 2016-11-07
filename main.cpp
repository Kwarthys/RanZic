#include <iostream>

#include "XMLElement.h"
#include "PerlinNoise.h"
#include "Note.h"

using namespace std;

int main()
{
    std::string idName = "identification", rigthsName = "rights", artistName = "Kwarthys";
    std::string titleName = "movement-title", title = "Try It";
    XMLElement* titre = new XMLElement(titleName);
    titre->setValue(title);
    XMLElement* id = new XMLElement(idName);
    XMLElement* owner = new XMLElement(rigthsName);
    owner->setValue(artistName);
    id->addChild(owner);

    /*
    <movement-title>Titre</movement-title>
    <identification>
            <rights>Artiste</rights>
    </identification>
    */

    std::string midiInstName = "midi-instrument", midiInstAttr = "id=\"P0\"", midiChannelName = "midi-channel";
    std::string midiBankName = "midi-bank", un = "1", d26 = "26", d80 = "80", d0 = "0";
    std::string midiProgName = "midi-program", volumeName = "volume", panName = "pan";
    XMLElement * midiC = new XMLElement(midiChannelName);
    midiC->setValue(un);
    XMLElement * midiB = new XMLElement(midiBankName);
    midiB->setValue(un);
    XMLElement * midiP = new XMLElement(midiProgName);
    midiP->setValue(d26);
    XMLElement * volume = new XMLElement(volumeName);
    volume->setValue(d80);
    XMLElement * pan = new XMLElement(panName);
    pan->setValue(d0);
    XMLElement * midiInstru = new XMLElement(midiInstName);
    midiInstru->addAttribute(midiInstAttr);
    midiInstru->addChild(midiC);midiInstru->addChild(midiB);midiInstru->addChild(midiP);midiInstru->addChild(volume);midiInstru->addChild(pan);

    XMLElement * abrev = new XMLElement("part-abreviation");
    abrev->setValue("S-GT");
    XMLElement * partName = new XMLElement("part-name");
    partName->setValue("Steel Guitar");

    XMLElement * scorePart = new XMLElement("score-part");
    scorePart->addAttribute("id=\"P0\"");
    scorePart->addChild(partName);scorePart->addChild(abrev);scorePart->addChild(midiInstru);

    XMLElement * partList = new XMLElement("part-list");
    partList->addChild(scorePart);

    XMLElement * song = new XMLElement("score-partwise");
    song->addAttribute("version=\"2.0\"");

    song->addChild(titre);
    song->addChild(id);
    song->addChild(partList);

    /*
    <part-list>
        <score-part id="P0">
            <part-name>Steel Guitar</part-name>
            <part-abbreviation>S-Gt</part-abbreviation>
            <midi-instrument id="P0">
                <midi-channel>1</midi-channel>
                <midi-bank>1</midi-bank>
                <midi-program>26</midi-program>
                <volume>80</volume>
                <pan>0</pan>
            </midi-instrument>
        </score-part>
    </part-list>
    */
    cout << song->toString() << endl << endl;


    cout << "creating Note" << endl << endl;

    Note note = Note();
    note.setduration(2);
    note.setOctave(2);
    note.setFret(2);
    note.setString(6);
    note.setStep('F');

    cout << "End of Note creation" << endl << endl;

    cout << note.toString() << endl;


    return 0;
}
