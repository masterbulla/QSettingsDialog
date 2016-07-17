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

//! Enviroment variable name for autoload configuration @ingroup grp_variantwidgets
#define VARIANT_WIDGETS_AUTOLOAD "env_qsettingsdialog_autoload"
//! Enviroment variable value to autoload groups @ingroup grp_variantwidgets
#define AUTOLOAD_GROUPS 0b1000
//! Enviroment variable value to autoload default edit widgets @ingroup grp_variantwidgets
#define AUTOLOAD_WIDGETS 0b0100
//! Enviroment variable value to autoload enum factories @ingroup grp_variantwidgets
#define AUTOLOAD_ENUMS 0b0010
//! Enviroment variable value to autoload extended edit widgets @ingroup grp_variantwidgets
#define AUTOLOAD_EXTENDED 0b0001

//! Simple define for "&" to mark parameters as out-parameter @ingroup grp_core
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
    Q_ASSERT_X(from.template dynamicCast<TTo>(), "", "static cast not possible! Dynamic cast assertion failed!");
    return from.template staticCast<TTo>();
}
#define sharedSafeCast(type, sharedPointer) safeCast_sharedPointer<type>(sharedPointer)
#endif

//! a Hash for strings to variant, to provide properties for edit widgets @ingroup grp_core
typedef QHash<QString, QVariant> UiPropertyMap;

#endif // QSETTINGSDIALOGENGINE_GLOBAL_H
