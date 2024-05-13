#pragma once

#include "icontrolwidget.h"

#include <QFont>

#include <functional>

class IFontController : public IControlWidget
{
public:
    using ChangeFontCallback = std::function<void(QFont)>;

    virtual ~IFontController() = default;

    virtual QFont font() const = 0;
};
