#ifndef QSETTINGSDIALOGENGINE_GLOBAL_H
#define QSETTINGSDIALOGENGINE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QSharedPointer>
#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

#if defined(QSETTINGSDIALOG_LIBRARY)
#  define QSETTINGSDIALOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QSETTINGSDIALOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#define outParam &

#ifdef QT_NO_DEBUG
#define safe_cast static_cast
#else
template <typename TTo, typename TFrom>
inline TTo safeCast(TFrom from) {
	Q_ASSERT_X(dynamic_cast<TTo>(from), "", "static cast not possible! Dynamic cast assertion failed!");
	return static_cast<TTo>(from);
}
#define safe_cast safeCast
#endif

#ifdef QT_NO_DEBUG
#define sharedSafeCast(type, sharedPointer) sharedPointer.staticCast<type>()
#else
template <typename TTo, typename TFrom>
inline QSharedPointer<TTo> safeCast_sharedPointer(QSharedPointer<TFrom> from) {
	Q_ASSERT_X(from.dynamicCast<TTo>(), "", "static cast not possible! Dynamic cast assertion failed!");
	return from.staticCast<TTo>();
}
#define sharedSafeCast(type, sharedPointer) safeCast_sharedPointer<type>(sharedPointer)
#endif


#endif // QSETTINGSDIALOGENGINE_GLOBAL_H
