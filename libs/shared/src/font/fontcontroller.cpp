#include "fontcontroller.h"

FontController::FontController(const QFont &font, ChangeFontCallback callback)
    : _fontControlWidget{ new QFontComboBox }
{
    setupWidget(font);
    connectSignals(callback);
}

FontController::~FontController()
{
    delete _fontControlWidget;
}

QWidget *FontController::controlWidget() const
{
    return _fontControlWidget;
}

QFont FontController::font() const
{
    return _fontControlWidget->currentFont();
}

void FontController::setupWidget(const QFont &font)
{
    _fontControlWidget->setEditable(false);
    _fontControlWidget->setCurrentFont(font);
}

void FontController::connectSignals(ChangeFontCallback callback)
{
    QObject::connect(_fontControlWidget, &QFontComboBox::currentFontChanged,
                     [callback](const QFont &font) { callback(font); });
}
