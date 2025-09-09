#include "elementfactory.h"

ElementFactory::ElementFactory() {
    m_base = {
        Element("Огонь", 1, ElementType::Base, "icons/fire.png"),
        Element("Вода", 1, ElementType::Base, "icons/water.png"),
        Element("Земля", 1, ElementType::Base, "icons/earth.png"),
        Element("Воздух", 1, ElementType::Base, "icons/air.png")
    };

    for(const auto &e : m_base)
        m_catalog.insert(e.name(), e);

    m_recipes = {
        Recipe("Огонь","Вода","Пар",2,"icons/steam.png"),
        Recipe("Земля","Вода","Грязь",2,"icons/mud.png"),
        Recipe("Земля","Воздух","Пыль",2,"icons/dust.png"),
        Recipe("Огонь","Воздух","Энергия",2,"icons/energy.png"),
        Recipe("Грязь","Огонь","Камень",3,"icons/stone.png"),
        Recipe("Камень","Огонь","Металл",3,"icons/metal.png"),
        Recipe("Энергия","Воздух","Буря",3,"icons/storm.png"),
        Recipe("Вода","Воздух","Волна",3,"icons/wave.png"),
        Recipe("Волна","Земля","Жизнь",4,"icons/life.png"),
        Recipe("Огонь","Земля","Лава",4,"icons/lava.png"),
        Recipe("Камень","Земля","Гора",4,"icons/mountain.png"),
        Recipe("Вода","Энергия","Лёд",4,"icons/ice.png"),
        Recipe("Пар","Воздух","Облако",3,"icons/cloud.png"),
        Recipe("Грязь","Вода","Болото",3,"icons/swamp.png"),
        Recipe("Облако","Дождь","Шторм",4,"icons/storm2.png"),
        Recipe("Кирпич","Грязь","Дом",4,"icons/house.png")
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
    return Element("Неизвестно",0,ElementType::Unknown,"icons/default.png");
}

Element ElementFactory::combine(const Element &e1,const Element &e2) const {
    for(const auto &r : m_recipes)
        if(r.matches(e1,e2))
            return r.createResult();
    return Element("Неизвестно",0,ElementType::Unknown,"icons/default.png");
}





