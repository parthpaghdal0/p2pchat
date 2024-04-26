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

#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QTcpServer>

namespace P2PChat
{

class IConnection;

/**
 * Represents a Server to accept Connections
 * @author Shashwat Dixit <parthpaghdal0@gmail.com>
 */
class IServer : public QTcpServer
{
	Q_OBJECT

public:
	/**
	 * @brief starts the server
	 * Server starts listening when this method is called
	 */
	virtual void start() = 0;

Q_SIGNALS:
	/**
	 * @brief emitted when a new Connection is available
	 */
	void gotConnection(IConnection*);

protected:
	/**
	 * @brief Constructor
	 */
	explicit IServer(QObject* parent);

	/**
	 * @brief Destructor
	 */
	~IServer();

};

}

#endif
