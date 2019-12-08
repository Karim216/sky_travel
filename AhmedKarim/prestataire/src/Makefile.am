## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = prestataire

prestataire_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	verifAuthentif.c verifAuthentif.h \
	ajouter_prest_vol.c ajouter_prest_vol.h \
	afficherPrest.c afficherPrest.h \
	supprPrest.c supprPrest.h \
	modifier_prest_vol.c modifier_prest_vol.h \
	affichageHbr.c affichageHbr.h \
	affichageVoiture.c affichageVoiture.h \
	afficherOffres.c afficherOffres.h

prestataire_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

