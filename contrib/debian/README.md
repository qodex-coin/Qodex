
Debian
====================
This directory contains files used to package qodexd/qodex-qt
for Debian-based Linux systems. If you compile qodexd/qodex-qt yourself, there are some useful files here.

## qodex: URI support ##


qodex-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install qodex-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your qodex-qt binary to `/usr/bin`
and the `../../share/pixmaps/qodex128.png` to `/usr/share/pixmaps`

qodex-qt.protocol (KDE)

