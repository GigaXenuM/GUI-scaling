#pragma once

#include <QScrollArea>

class CustomScrollArea : public QScrollArea
{
public:
    CustomScrollArea(QWidget *parent = nullptr);

private:
    void adjustWidth();
};
