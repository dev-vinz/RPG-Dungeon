#ifndef EXTENSIONMETHOD_H
#define EXTENSIONMETHOD_H

#include <map>

#include <QLabel>
#include <QString>

#include "../apps/actors/include/player.h"

class ExtensionMethod
{
public:
    template <typename T>
    static QString Join(const T &v, const QString &delim)
    {
        QString s;

        for (const auto &i : v)
        {
            if (&i != &v[0])
            {
                s.append(delim);
            }

            s.append(i);
        }

        return s;
    }

    static void UpdateStatsLayout(std::map<Player *, QLabel *> *_statsLabels)
    {
        // We update the statistics shown

        for (auto item : *_statsLabels)
        {
            Player *p = item.first;
            QLabel *l = item.second;

            if (p->isAlive())
            {
                l->setText(p->showStat());
            }
            else
            {
                l->setText(p->getName() + "\nRIP");
            }
        }
    }
};

#endif // EXTENSIONMETHOD_H
