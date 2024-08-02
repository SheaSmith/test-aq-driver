# $FreeBSD$

.PATH:  ./

KMOD=	if_atlantic
SRCS=	if_atlantic.c

CFLAGS+= -DIFLIB -I/usr/include -Werror

.include <bsd.kmod.mk>
