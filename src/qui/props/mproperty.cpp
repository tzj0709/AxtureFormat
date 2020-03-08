﻿#include "mproperty.h"

namespace RQt{

MProperty::MProperty():m_kind(Unknown),m_propRect(nullptr)
{

}

MProperty::~MProperty()
{
    delete m_propRect;
    m_propRect = nullptr;
}

void MProperty::write(QXmlStreamWriter &writer, QString tagName)
{
    writer.writeStartElement(tagName.isEmpty() ? "property" : tagName);

    if(hasAtributeName())
        writer.writeAttribute("name",attributeName());

    switch(m_kind){
        case Cstring:{
            writer.writeTextElement("string",m_propString);
            break;
        }
        case Bool:{
            writer.writeTextElement("bool",m_propString);
            break;
        }
        case Enum:{
            writer.writeTextElement("enum",m_propString);
            break;
        }
        case Number:{
            writer.writeTextElement("number",m_propString);
            break;
        }
        case Rect:{
            m_propRect->write(writer,"rect");
            break;
        }
        default:break;
    }

    writer.writeEndElement();
}

void MProperty::setPropString(QString value)
{
    m_kind = Cstring;
    m_propString = value;
}

void MProperty::setPropBool(QString value)
{
    m_kind = Bool;
    m_propString = value;
}

void MProperty::setPropEnum(QString value)
{
    m_kind = Enum;
    m_propString = value;
}

void MProperty::setPropNumber(QString value)
{
    m_kind = Number;
    m_propString = value;
}

void MProperty::setPropRect(MRect *rect)
{
    m_kind = Rect;
    m_propRect = rect;
}

} //namespace RQt