#include "elementfactory.h"

ElementFactory::ElementFactory() {
    m_base = {
        Element("Огонь", 1),
        Element("Вода", 1),
        Element("Земля", 1),
        Element("Воздух", 1)
    };

    for(const auto &e : m_base)
        m_catalog.insert(e.name(), e);

    m_recipes = {
        Recipe("Вода","Огонь","Пар",2),
        Recipe("Земля","Вода","Грязь",2),
        Recipe("Земля","Воздух","Пыль",2),
        Recipe("Вода","Воздух","Дождь",2),
        Recipe("Грязь","Огонь","Кирпич",3),
        Recipe("Пар","Воздух","Облако",3),
        Recipe("Земля","Пар","Камень",3),
        Recipe("Грязь","Вода","Болото",3),
        Recipe("Облако","Дождь","Шторм",4),
        Recipe("Камень","Огонь","Лава",4),
        Recipe("Кирпич","Грязь","Дом",4),
        Recipe("Облако","Пар","Молния",4)
    };

    for(const auto &r : m_recipes)
        m_catalog.insert(r.createResult().name(), r.createResult());
}

QVector<Element> ElementFactory::baseElements() const {
    return m_base;
}

QVector<Element> ElementFactory::allElements() const {
    return m_catalog.values().toVector();
}

Element ElementFactory::createElement(const QString &name) const {
    auto it = m_catalog.constFind(name);
    if(it != m_catalog.cend()) return it.value();
    return Element("Неизвестно",0,ElementType::Unknown);
}

Element ElementFactory::combine(const Element &e1,const Element &e2) const {
    for(const auto &r : m_recipes)
        if(r.matches(e1,e2))
            return r.createResult();
    return Element("Неизвестно",0,ElementType::Unknown);
}







