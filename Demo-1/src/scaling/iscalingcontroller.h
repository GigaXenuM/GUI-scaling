#pragma once

#include "icontrolwidget.h"

#include <QWidget>

#include <functional>

class IScalingController : public IControlWidget
{
public:
    using ChangeScalingCallback = std::function<void(double)>;

    virtual ~IScalingController() = default;

    virtual double scalingFactor() const = 0;
};
