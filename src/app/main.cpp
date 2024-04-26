/*
 *   This file is part of p2pchat
 *   Copyright 2017 Shashwat Dixit <parthpaghdal0@gmail.com>
 * 
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 3 of the
 *   License, or (at your option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "controlcenter.h"
#include "p2pchatwindow.h"

#include <iostream>
#include <QApplication>
#include <QLoggingCategory>
#include <QIcon>

using namespace P2PChat;

int main(int argc, char* argv[])
{
	QApplication a(argc,argv);
	a.setApplicationName("P2PChat");
	a.setOrganizationName("P2PChat");
	a.setOrganizationDomain("https://github.com/parthpaghdal0/P2PChat");
	a.setApplicationVersion("2.0");

	QLoggingCategory::setFilterRules(QStringLiteral("p2pchat.transferrigor=false\n"));

	ControlCenter::init();
	QObject::connect(&a,&QApplication::aboutToQuit,ControlCenter::instance(),&ControlCenter::shutdown);
	P2PChatWindow w;
	w.show();

	a.exec();
	ControlCenter::quit();
	return 0;
}
