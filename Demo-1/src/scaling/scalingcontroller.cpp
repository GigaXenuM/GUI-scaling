#include "scalingcontroller.h"

#include <QComboBox>

namespace
{
std::array<double, 4> SCALE_FACTORS{ 1, 1.25, 1.5, 1.75 };
}

ScalingController::ScalingController(double scalingFactor, ChangeScalingCallback callback)
    : _scalingControlWidget{ new QComboBox }
{
    setupWidget(scalingFactor);
    connectSignals(callback);
}

ScalingController::~ScalingController()
{
    delete _scalingControlWidget;
}

QWidget *ScalingController::controlWidget() const
{
    return _scalingControlWidget;
}

double ScalingController::scalingFactor() const
{
    return SCALE_FACTORS.at(_scalingControlWidget->currentIndex());
}

void ScalingController::setupWidget(double scalingFactor)
{
    _scalingControlWidget->addItem("100%");
    _scalingControlWidget->addItem("125%");
    _scalingControlWidget->addItem("150%");
    _scalingControlWidget->addItem("175%");

    const auto scalingFactorIt{ std::find(SCALE_FACTORS.begin(), SCALE_FACTORS.end(),
                                          scalingFactor) };
    const int scalingFactorIndex{ static_cast<int>(
        std::distance(SCALE_FACTORS.begin(), scalingFactorIt)) };
    _scalingControlWidget->setCurrentIndex(scalingFactorIndex);
}

void ScalingController::connectSignals(ChangeScalingCallback callback)
{
    QObject::connect(_scalingControlWidget, &QComboBox::currentIndexChanged,
                     [callback](int index)
                     {
                         const double scaling{ SCALE_FACTORS.at(index) };
                         callback(scaling);
                     });
}
