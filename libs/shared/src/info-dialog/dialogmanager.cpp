#include "dialogmanager.h"

#include <QMessageBox>
#include <QPushButton>

namespace DialogManager
{

void showInfoDialog(const QString &title, const QString &message, QWidget *displayWidget)
{
    QMessageBox msgBox(displayWidget);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Information);

    auto *okButton = msgBox.addButton(QMessageBox::Ok);
    okButton->setText("Ok");

    msgBox.exec();
}

} // namespace DialogManager
