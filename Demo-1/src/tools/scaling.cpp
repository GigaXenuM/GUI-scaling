#include "scaling.h"

#include <QFont>
#include <QList>
#include <QWidget>

namespace Tools
{

QFont scaleFont(QFont font, double scalingFactor)
{
    font.setPointSizeF(font.pointSizeF() * scalingFactor);
    return font;
}

} // namespace Tools
