#include "XMLElement.h"

XMLElement::XMLElement(std::string & name)
{
    //ctor
    _name = new std::string(name);
    _value = nullptr;
    _childs =  std::vector<XMLElement*>();
    _attributes =  std::vector<std::string*>();
}

XMLElement::~XMLElement()
{
    //dtor
}

XMLElement * XMLElement::getChildByName(std::string& wanted)
{
    XMLElement* ret = nullptr;

    for(unsigned int i = 0; i < _childs.size(); i++)
    {
        if(_childs.at(i)->getName() != wanted) //if the wanted item is not in the first generation of children
        {
            if(_childs.at(i)->getChildByName(wanted) != nullptr) ret = _childs.at(i)->getChildByName(wanted); //Recursively search in the child of this item
        }
        else ret = _childs.at(i);
    }

    return ret;
}

std::string XMLElement::toString()
{
    std::string ret = "";
    ret += "<" + *_name + " ";
    for(unsigned int i = 0; i < _attributes.size(); i++)
    {
        ret += *(_attributes.at(i)) + " ";
    }
    ret += ">";

    if(_value)
    {
        ret+= *_value;
    }

    for(unsigned int i = 0; i < _childs.size(); i++)
    {
        ret += "\r\n" + (_childs.at(i))->toString();
        if(i == _childs.size()-1)ret+= "\r\n";
    }

    ret += "</" + *_name + ">";
    return ret;
}

void XMLElement::addChild(XMLElement* e )
{
    _childs.push_back(e);
}

void XMLElement::addAttribute(std::string& s )
{
    _attributes.push_back(new std::string(s));
}

void XMLElement::setValue(std::string& s )
{
    _value = new std::string(s);
}
