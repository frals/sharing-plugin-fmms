AC_INIT([sharing-fmms], [0.1])
AM_INIT_AUTOMAKE([foreign])

AM_MAINTAINER_MODE
AM_CONFIG_HEADER([config.h])


dnl =======================================================
dnl ===== Checks for programs
dnl =======================================================

AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
AC_ISC_POSIX
AC_PROG_CXX
AC_PROG_CC
AM_PROG_CC_STDC
AC_HEADER_STDC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL


CFLAGS="$CFLAGS -Wall -Wmissing-prototypes -Wcast-align -std=gnu99"


PKG_CHECK_MODULES(PACKAGE, [glib-2.0 gtk+-2.0 libsharing conic libosso dbus-glib-1])
AC_SUBST(PACKAGE_CFLAGS)
AC_SUBST(PACKAGE_LIBS)

PKG_CHECK_MODULES(SHARING, libsharing)

pluginsdir=`$PKG_CONFIG libsharing --variable=pluginsdir`
AC_SUBST(pluginsdir)
PKG_PROG_PKG_CONFIG()
servicesdir=`$PKG_CONFIG libsharing --variable=servicesdir`
AC_SUBST(servicesdir)


AC_ARG_ENABLE(debug, AC_HELP_STRING([--enable-debug], [Turn on debug messages]),
        enable_debug=yes, enable_debug=no)

if test x$enable_debug = xyes; then
  DEBUG_CFLAGS="-DOSSOLOG_COMPILE"
  AC_SUBST(DEBUG_CFLAGS)
fi


dnl Set PACKAGE_LOCALE_DIR in config.h
DATADIRNAME="share"
if test "x${prefix}" = "xNONE"; then
  AC_DEFINE_UNQUOTED([PACKAGE_LOCALE_DIR], ["${ac_default_prefix}/${DATADIRNAME}/locale"],[Locale directory])
else
  AC_DEFINE_UNQUOTED([PACKAGE_LOCALE_DIR], ["${prefix}/${DATADIRNAME}/locale"], [Locale directory])
fi
AC_SUBST(PACKAGE_LOCALE_DIR)

AC_OUTPUT([
    Makefile
    data/Makefile
    data/sharing-fmms.service.xml
    src/Makefile
])


dnl =======================================================
dnl ===== Summary
dnl =======================================================

echo ""
echo "                  $PACKAGE $VERSION"
echo "                 ==================="
echo ""
echo "           Debug messages:   ${enable_debug}"
echo "       Plug-ins directory:   ${pluginsdir}"
echo "       Services directory:   ${servicesdir}"
echo ""
