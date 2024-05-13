#pragma once

#include <QAnyStringView>
#include <QSettings>
#include <QVariant>

class SettingsController
{
public:
    SettingsController() : _organizationName{ "SomeSoft" }
    {
    }

    template <typename T> void write(QAnyStringView groupName, QAnyStringView propertyName, T value)
    {
        QSettings settings(_organizationName.c_str());

        settings.beginGroup(std::move(groupName));
        settings.setValue(std::move(propertyName), value);
        settings.endGroup();
    }

    template <typename T>
    T read(QAnyStringView groupName, QAnyStringView propertyName, T defaultValue)
    {
        QSettings settings(_organizationName.c_str());
        settings.beginGroup(groupName);

        const T value{ settings.value(propertyName, defaultValue).template value<T>() };
        settings.endGroup();

        return value;
    }

private:
    std::string _organizationName;
};
