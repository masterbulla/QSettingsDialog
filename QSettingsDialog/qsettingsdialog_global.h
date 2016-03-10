#ifndef QSETTINGSDIALOG_GLOBAL_H
#define QSETTINGSDIALOG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QSETTINGSDIALOG_LIBRARY)
#  define QSETTINGSDIALOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QSETTINGSDIALOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#define Q_ASSERT_X2(condition, message) Q_ASSERT_X(condition, Q_FUNC_INFO, message)

#include <QDebug>//DEBUG

#endif // QSETTINGSDIALOG_GLOBAL_H