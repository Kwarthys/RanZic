#include <iostream>

#include "XMLElement.h"
#include "PerlinNoise.h"
#include "Note.h"
#include "Guitar.h"
#include "Measure.h"

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

    XMLElement * partList = new XMLElement("part-list");

    XMLElement * song = new XMLElement("score-partwise");
    song->addAttribute("version=\"2.0\"");

    song->addChild(titre);
    song->addChild(id);
    song->addChild(partList);

    Guitar * guitar = new Guitar();
    Guitar * guitar2 = new Guitar();

    partList->addChild(guitar->getDescriptor());
    partList->addChild(guitar2->getDescriptor());

    XMLElement * part = new XMLElement("part");
    part->addAttribute("id=\"P0\"");

    song->addChild(part);

    Measure * measure1 = new Measure();

    measure1->getDescriptor()->getChildByName("attributes")->addChild(guitar->getStaffDescriptor());

    XMLElement * dir = new XMLElement("direction");
    dir->addAttribute("directive=\"yes\"");
    dir->addAttribute("placement=\"above\"");

    XMLElement * dirType = new XMLElement("direction-type");
    XMLElement * metronome = new XMLElement("metronome");
    metronome->addAttribute("default=\"40\"");
    metronome->addAttribute("parentheses=\"yes\"");
    XMLElement * beatUnit = new XMLElement("beat-unit");
    beatUnit->setValue("quarter");
    metronome->addChild(beatUnit);
    XMLElement * perMin = new XMLElement("per-minute");
    perMin->setValue("150");
    metronome->addChild(perMin);
    dirType->addChild(metronome);
    dir->addChild(dirType);
    XMLElement * sound = new XMLElement("sound");
    sound->setValue("150");
    dir->addChild(sound);

    measure1->getDescriptor()->addChild(dir);

    part->addChild(measure1->getDescriptor());

    Note * note1 = new Note();
    note1->setStep('F');
    note1->setOctave(2);
    note1->setduration(2);
    note1->setFret(1);
    note1->setString(6);

    measure1->getDescriptor()->addChild(note1->getDescriptor());
    measure1->getDescriptor()->addChild(note1->getDescriptor());
    measure1->getDescriptor()->addChild(note1->getDescriptor());
    measure1->getDescriptor()->addChild(note1->getDescriptor());

    /*
    <part-list>
        <score-part id="P0">               <-----------Instrument
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
    cout << "Guitars created" << endl << endl;

    cout << song->toString() << endl << endl;

    cout << "Job's done" << endl << endl;

    return 0;
}
