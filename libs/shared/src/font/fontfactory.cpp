#include "fontfactory.h"

namespace FontFactory
{

std::unordered_map<FontAssignment, QFont> fontMap{ { FontAssignment::Application,
                                                     QFont("Times", 12) } };

QFont create(FontAssignment assignment)
{
    return fontMap.at(assignment);
}

} // namespace FontFactory
