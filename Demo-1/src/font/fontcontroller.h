#pragma once

#include "ifontcontroller.h"

#include <QFontComboBox>

class SettingsController;

class FontController : public IFontController
{
public:
    FontController(const QFont &font, ChangeFontCallback callback);
    ~FontController() override;

    QWidget *controlWidget() const override;
    QFont font() const override;

private:
    void setupWidget(const QFont &font);
    void connectSignals(ChangeFontCallback callback);

    QFontComboBox *_fontControlWidget{ nullptr };
};
