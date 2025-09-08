#include "elementfactory.h"

ElementFactory::ElementFactory() {
    m_base = {
        Element("Огонь", 1, ElementType::Base, "icons/fire.png"),
        Element("Вода", 1, ElementType::Base, "icons/water.png"),
        Element("Земля", 1, ElementType::Base, "icons/earth.png"),
        Element("Воздух", 1, ElementType::Base, "icons/air.png")
    };

    for (const auto &e : m_base)
        m_catalog.insert(e.name(), e);

    // Рецепты
    m_recipes.append(Recipe("Вода","Огонь","Пар",2));
    m_recipes.append(Recipe("Земля","Вода","Грязь",2));
    m_recipes.append(Recipe("Земля","Воздух","Пыль",2));
    m_recipes.append(Recipe("Вода","Воздух","Дождь",2));

    m_recipes.append(Recipe("Грязь","Огонь","Кирпич",3));
    m_recipes.append(Recipe("Пар","Воздух","Облако",3));
    m_recipes.append(Recipe("Земля","Пар","Камень",3));
    m_recipes.append(Recipe("Грязь","Вода","Болото",3));

    m_recipes.append(Recipe("Облако","Дождь","Шторм",4));
    m_recipes.append(Recipe("Камень","Огонь","Лава",4));
    m_recipes.append(Recipe("Кирпич","Грязь","Дом",4));
    m_recipes.append(Recipe("Облако","Пар","Молния",4));

    for (const auto &r : m_recipes) {
        QString fileName = r.resultName().toLower();
        fileName.replace(" ", "_");
        m_catalog.insert(r.resultName(), Element(r.resultName(), r.resultLevel(), levelToType(r.resultLevel()),
                                                 "icons/" + fileName + ".png"));
    }
}

ElementType ElementFactory::levelToType(int level) const {
    if(level == 1) return ElementType::Base;
    if(level <= 3) return ElementType::Composite;
    return ElementType::Advanced;
}

Element ElementFactory::createElement(const QString &name) const {
    auto it = m_catalog.constFind(name);
    if(it != m_catalog.cend()) return it.value();
    return Element(name, 1, ElementType::Base, "icons/default.png");
}

Element ElementFactory::combine(const Element &e1, const Element &e2) const {
    for(const auto &r : m_recipes) {
        if(r.matches(e1,e2)) {
            return createElement(r.resultName());
        }
    }
    return Element("Неизвестно", 0, ElementType::Unknown, "icons/default.png");
}

QVector<Element> ElementFactory::baseElements() const {
    return m_base;
}


