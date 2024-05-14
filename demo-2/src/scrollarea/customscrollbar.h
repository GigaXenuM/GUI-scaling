#pragma once

#include <QScrollBar>

class CustomScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    explicit CustomScrollBar(QWidget *parent = nullptr);

signals:
    void visibilityChanged(bool visible);

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
};
