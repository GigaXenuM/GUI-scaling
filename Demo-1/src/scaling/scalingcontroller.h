#pragma once

#include "iscalingcontroller.h"

#include <QComboBox>

class SettingsController;

class ScalingController : public IScalingController
{
public:
    ScalingController(double scalingFactor, ChangeScalingCallback callback);
    ~ScalingController() override;

    QWidget *controlWidget() const override;
    double scalingFactor() const override;

private:
    void setupWidget(double scalingFactor);
    void connectSignals(ChangeScalingCallback callback);

    QComboBox *_scalingControlWidget{ nullptr };
};
