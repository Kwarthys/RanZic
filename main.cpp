#include <iostream>

#include "XMLElement.h"
#include "PerlinNoise.h"
#include "Note.h"
#include "Guitar.h"

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

    Guitar guitar = Guitar();
    Guitar guitar2 = Guitar();

    partList->addChild(guitar.getDescriptor());
    partList->addChild(guitar2.getDescriptor());

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

    cout << guitar.getStaffDescriptor()->toString() << endl << endl;

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
