#pragma once

#include "isetupui.h"

class QWidget;
class QComboBox;

class CentralWidgetController : public ISetupUI
{
public:
    CentralWidgetController(QWidget *centralWidget, QWidget *scaleControlWidget,
                            QWidget *fontControlWidget, const double scalingFactor);

    void setup() override;

private:
    QWidget *_centralWidget{ nullptr };
    QWidget *_scaleControlWidget{ nullptr };
    QWidget *_fontControlWidget{ nullptr };

    const double _scalingFactor{ 1. };
};
