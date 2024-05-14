#include "customscrollarea.h"

#include "customscrollbar.h"

CustomScrollArea::CustomScrollArea(QWidget *parent) : QScrollArea(parent)
{
    CustomScrollBar *vScrollBar{ new CustomScrollBar(this) };
    setVerticalScrollBar(vScrollBar);
    connect(vScrollBar, &CustomScrollBar::visibilityChanged, this, &CustomScrollArea::adjustWidth);
}

void CustomScrollArea::adjustWidth()
{
    const int scrollbarWidth{ verticalScrollBar()->width() };
    const int widthOffset{ verticalScrollBar()->isVisible() ? scrollbarWidth : -scrollbarWidth };

    setFixedWidth(width() + widthOffset);
}
