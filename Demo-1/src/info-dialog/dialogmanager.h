#pragma once

class QWidget;
class QString;

namespace DialogManager
{
void showInfoDialog(const QString &title, const QString &message, QWidget *displayWidget);
}
