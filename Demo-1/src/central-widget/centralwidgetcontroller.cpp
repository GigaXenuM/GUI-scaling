#include "centralwidgetcontroller.h"

#include <QComboBox>
#include <QFontComboBox>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

CentralWidgetController::CentralWidgetController(QWidget *centralWidget,
                                                 QWidget *scaleControlWidget,
                                                 QWidget *fontControlWidget,
                                                 const double scalingFactor)
    : _centralWidget{ centralWidget },
      _scaleControlWidget{ scaleControlWidget },
      _fontControlWidget{ fontControlWidget },
      _scalingFactor{ scalingFactor }
{
}

void CentralWidgetController::setup()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    _centralWidget->setLayout(mainLayout);

    QHBoxLayout *sceneLayout{ new QHBoxLayout };
    mainLayout->addLayout(sceneLayout);

    QHBoxLayout *controlsLayout{ new QHBoxLayout };
    mainLayout->addLayout(controlsLayout);

    QVBoxLayout *comboLayout = new QVBoxLayout;
    controlsLayout->addLayout(comboLayout);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    controlsLayout->addLayout(buttonLayout);

    QGraphicsView *view{ new QGraphicsView() };
    QGraphicsScene *scene = new QGraphicsScene();

    view->setMinimumSize({ 400, 150 });
    view->setMinimumSize(view->minimumSize() * _scalingFactor);
    view->setBackgroundBrush(QColor(180, 180, 180));
    view->setScene(scene);

    QGraphicsTextItem *textItem = new QGraphicsTextItem("Text on the scene");
    scene->addItem(textItem);

    QPushButton *button = new QPushButton("I button");

    sceneLayout->addWidget(view);
    comboLayout->addWidget(_scaleControlWidget);
    comboLayout->addWidget(_fontControlWidget);
    buttonLayout->addWidget(button);
}
