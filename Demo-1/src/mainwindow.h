#pragma once

#include "isetupui.h"

#include <QMainWindow>

class QWidget;
class QComboBox;

class IScalingController;
class IFontController;
class SettingsController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setup();

    std::shared_ptr<SettingsController> _settingsController;

    const double _scalingFactor{ 1. };
    const QFont _appFont;

    std::unique_ptr<IScalingController> _scalingController;
    std::unique_ptr<IFontController> _fontController;

    QWidget *_centralwidget{ nullptr };

    std::unique_ptr<ISetupUI> _centralWidgetController;
    std::unique_ptr<ISetupUI> _dockWidgetController;
};
