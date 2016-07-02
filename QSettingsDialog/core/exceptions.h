#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "qsettingsdialog_global.h"
#include "qtexception.h"

class QSETTINGSDIALOGSHARED_EXPORT InvalidContainerPathException : public QtException
{
public:
	InvalidContainerPathException();
};

class QSETTINGSDIALOGSHARED_EXPORT LayoutPropertyNotDefinedException : public QtException
{
public:
	LayoutPropertyNotDefinedException();
};

class QSETTINGSDIALOGSHARED_EXPORT InvalidTargetLayoutException : public QtException
{
public:
	InvalidTargetLayoutException();
};

#endif // EXCEPTIONS_H
