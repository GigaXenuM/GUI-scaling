#include "customscrollbar.h"

CustomScrollBar::CustomScrollBar(QWidget *parent) : QScrollBar(parent)
{
}

void CustomScrollBar::showEvent(QShowEvent *event)
{
    QScrollBar::showEvent(event);
    emit visibilityChanged(true);
}

void CustomScrollBar::hideEvent(QHideEvent *event)
{
    QScrollBar::hideEvent(event);
    emit visibilityChanged(false);
}
