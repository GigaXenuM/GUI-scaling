#include "dockwidgetcontroller.h"

#include "scrollarea/customscrollarea.h"

#include <QApplication>
#include <QDockWidget>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>

constexpr int LABEL_BORDER_WIDTH{ 1 };

namespace
{

std::shared_ptr<DockWidgetContext> createDockWidgetContext(double scalingFactor)
{
    auto dockWidget{ new QDockWidget };
    auto scrollArea{ new CustomScrollArea };
    auto centralWidget{ new QWidget };
    auto mainLayout{ new QVBoxLayout{ centralWidget } };

    centralWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    scrollArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    scrollArea->setWidget(centralWidget);
    scrollArea->setWidgetResizable(true);
    dockWidget->setWidget(scrollArea);

    return std::make_shared<DockWidgetContext>(dockWidget, centralWidget, mainLayout);
}

QSize defineContentSize(const QString &text, double scalingFactor, int rawBorderWidth)
{
    QFontMetrics fontMetrics(qApp->font());
    QSize textSize = fontMetrics.boundingRect(text).size();
    const int borderWidth{ static_cast<int>(rawBorderWidth * 2 * scalingFactor) };
    return QSize(textSize.width() + borderWidth, textSize.height() + borderWidth);
}

} // namespace

DockWidgetController::DockWidgetController(QMainWindow *window, double scalingFactor)
    : _window{ window },
      _leftDockWidgetContext{ createDockWidgetContext(scalingFactor) },
      _scalingFactor{ scalingFactor }
{
}

void DockWidgetController::setup()
{
    _window->addDockWidget(Qt::LeftDockWidgetArea, _leftDockWidgetContext->dockWidget);

    addLabel(QStringLiteral("For"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("dogfooding"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("only"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Option 1"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Option 2"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Option 3"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Option 4"), _leftDockWidgetContext->mainLayout);
    addLabel(QStringLiteral("Option 5"), _leftDockWidgetContext->mainLayout);
}

void DockWidgetController::addLabel(const QString &text, QBoxLayout *layout)
{
    QLabel *label = new QLabel(text);

    const QString styleSheet{ QString{
        "border: %0px solid #B9B9B9;"
        "background-color: #DADADA;" }
                                  .arg(LABEL_BORDER_WIDTH) };

    label->setStyleSheet(styleSheet);
    label->setAlignment(Qt::AlignCenter);
    label->setFixedSize(defineContentSize(label->text(), _scalingFactor, LABEL_BORDER_WIDTH));

    layout->addWidget(label);
}
