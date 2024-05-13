#pragma once

class QWidget;

class IControlWidget
{
public:
    virtual ~IControlWidget() = default;

    virtual QWidget *controlWidget() const = 0;
};
