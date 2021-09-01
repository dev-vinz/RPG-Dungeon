#ifndef EXTENSIONMETHOD_H
#define EXTENSIONMETHOD_H

#include <QString>

class ExtensionMethod
{
public:
    template <typename T>
    static QString Join(const T& v, const QString& delim)
    {
        QString s;

        for (const auto& i : v)
        {
            if (&i != &v[0])
            {
                s.append(delim);
            }

            s.append(i);
        }

        return s;
    }
};

#endif // EXTENSIONMETHOD_H
