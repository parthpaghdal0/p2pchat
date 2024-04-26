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

#ifndef CONNECTION_H
#define CONNECTION_H

#include "interfaces/iconnection.h"

#include <QObject>

namespace P2PChat
{

class Connection : public IConnection
{
	Q_OBJECT

public:
	explicit Connection();
	~Connection();

	QByteArray data(quint32 size = 0) override;
	QByteArray seek(quint32 size = 0) override;
	bool hasUnreadData() override;
	quint32 availableSize() override;

protected:
	void isError();
	void saveData();

	QByteArray m_data;
	bool m_unreadData;

};

}

#endif
