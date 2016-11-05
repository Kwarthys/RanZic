#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <vector>
#include <string>

class XMLElement
{
    public:

        XMLElement(std::string &);
        virtual ~XMLElement();
        void addChild(XMLElement*);
        void addAttribute(std::string&);
        void setValue(std::string&);
        std::string toString();

        std::string getName(){return *_name;}

        XMLElement* getChildByName(std::string&);

    protected:

    private:

        std::vector<XMLElement*> _childs;
        std::string * _name;
        std::string * _value;
        std::vector<std::string*> _attributes;
};

#endif // XMLELEMENT_H
