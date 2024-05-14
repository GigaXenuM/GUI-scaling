#include "mainwindow.h"

#include "central-widget/centralwidgetcontroller.h"
#include "dock-widget/dockwidgetcontroller.h"
#include "font/fontcontroller.h"
#include "font/fontfactory.h"
#include "scaling/scalingcontroller.h"
#include "settings/settingscontroller.h"

#include "tools/scaling.h"

#include "info-dialog/dialogmanager.h"

#include <QApplication>
#include <QComboBox>

namespace
{
double readScalingFromSettings(std::shared_ptr<SettingsController> settingsController)
{
    return settingsController->read<double>(QStringLiteral("demo2"), QStringLiteral("scaling"), 1.);
}

IScalingController::ChangeScalingCallback
onScalingChangedCallback(std::shared_ptr<SettingsController> settingsController,
                         QWidget *displayWidget)
{
    return [settingsController, displayWidget](double scalingFactor)
    {
        settingsController->write(QStringLiteral("demo2"), QStringLiteral("scaling"),
                                  scalingFactor);

        DialogManager::showInfoDialog(QStringLiteral("Apply scaling"),
                                      QStringLiteral("Restart the application to apply settings."),
                                      displayWidget);
    };
}

QFont readAppFontFromSettings(std::shared_ptr<SettingsController> settingsController)
{
    const QFont defaultFont{ FontFactory::create(FontAssignment::Application) };
    return settingsController->read(QStringLiteral("demo2"), QStringLiteral("font"), defaultFont);
}

IFontController::ChangeFontCallback
onFontChangedCallback(std::shared_ptr<SettingsController> settingsController,
                      QWidget *displayWidget)
{
    return [settingsController, displayWidget](QFont font)
    {
        settingsController->write(QStringLiteral("demo2"), QStringLiteral("font"), font);

        DialogManager::showInfoDialog(QStringLiteral("Apply font"),
                                      QStringLiteral("Restart the application to apply settings."),
                                      displayWidget);
    };
}
} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _settingsController{ std::make_shared<SettingsController>() },
      _scalingFactor{ readScalingFromSettings(_settingsController) },
      _appFont{ readAppFontFromSettings(_settingsController) },
      _scalingController{ std::make_unique<ScalingController>(
          _scalingFactor, onScalingChangedCallback(_settingsController, this)) },
      _fontController{ std::make_unique<FontController>(_appFont,
                                                        onFontChangedCallback(_settingsController,
                                                                              this)) },
      _centralwidget{ new QWidget(this) },
      _centralWidgetController{ std::make_unique<CentralWidgetController>(
          _centralwidget, _scalingController->controlWidget(), _fontController->controlWidget(),
          _scalingFactor) },
      _dockWidgetController{ std::make_unique<DockWidgetController>(this, _scalingFactor) }
{
    setup();

    _centralWidgetController->setup();
    _dockWidgetController->setup();
}

MainWindow::~MainWindow() = default;

void MainWindow::setup()
{
    qApp->setFont(Tools::scaleFont(_fontController->font(), _scalingFactor));

    setCentralWidget(_centralwidget);
}
