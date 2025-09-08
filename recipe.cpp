#include "recipe.h"

Recipe::Recipe(const QString& first, const QString& second, const QString& result)
    : first(first), second(second), result(result) {}

bool Recipe::matches(const Element& e1, const Element& e2) const {
    return (e1.getName() == first && e2.getName() == second) ||
           (e1.getName() == second && e2.getName() == first);
}

QString Recipe::getResult() const {
    return result;
}
