#pragma once

#include "isetupui.h"

#include <QAnyStringView>

class QMainWindow;
class QDockWidget;
class QLabel;
class QWidget;
class QBoxLayout;

struct DockWidgetContext
{
    DockWidgetContext(QDockWidget *pDockWidget, QWidget *pCentralWidget, QBoxLayout *pMainLayout)
        : dockWidget{ pDockWidget }, centralWidget{ pCentralWidget }, mainLayout{ pMainLayout }
    {
    }

    QDockWidget *dockWidget{ nullptr };
    QWidget *centralWidget{ nullptr };
    QBoxLayout *mainLayout{ nullptr };
};

class DockWidgetController : public ISetupUI
{
public:
    DockWidgetController(QMainWindow *window);

    void setup() override;
    void afterScalingLog();

private:
    void addLabel(QAnyStringView text, QBoxLayout *layout);

    QMainWindow *_window{ nullptr };
    std::shared_ptr<DockWidgetContext> _leftDockWidgetContext;
};