#include "dockwidgetcontroller.h"

#include <QDockWidget>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>

namespace
{
std::shared_ptr<DockWidgetContext> createDockWidgetContext()
{
    auto dockWidget{ new QDockWidget };
    auto centralWidget{ new QWidget };
    auto mainLayout{ new QVBoxLayout{ centralWidget } };
    dockWidget->setWidget(centralWidget);

    return std::make_shared<DockWidgetContext>(dockWidget, centralWidget, mainLayout);
}
} // namespace

DockWidgetController::DockWidgetController(QMainWindow *window)
    : _window{ window }, _leftDockWidgetContext{ createDockWidgetContext() }
{
}

void DockWidgetController::setup()
{
    _window->addDockWidget(Qt::LeftDockWidgetArea, _leftDockWidgetContext->dockWidget);

    addLabel(QStringLiteral("Label 1"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Label 2"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Label 3"), _leftDockWidgetContext->mainLayout);
}

void DockWidgetController::addLabel(QAnyStringView text, QBoxLayout *layout)
{
    QLabel *label = new QLabel(text.toString());
    layout->addWidget(label, 0, Qt::AlignHCenter);
}
