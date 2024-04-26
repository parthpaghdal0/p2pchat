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

#ifndef CONTROLCENTERPRIVATE_H
#define CONTROLCENTERPRIVATE_H

namespace P2PChat
{

class MessageServer;
class ClientManager;
class CryptEngine;
class TransferManager;
class TransferServer;
class UserSettings;
class ControlCenter;

/**
 * @brief Container for all instances provided by IControlCenter
 */
class ControlCenterPrivate
{
public:
	/**
	 * @brief CTOR
	 */
	explicit ControlCenterPrivate(ControlCenter* parent = nullptr);

	/**
	 * @brief DTOR
	 */
	~ControlCenterPrivate();

	/**
	 * @brief creates all instances
	 */
	void init();

	/**
	 * @brief deletes all instances
	 */
	void shutdown();

	MessageServer* m_messageServer;
	TransferServer* m_transferServer;
	ClientManager* m_clientManager;
	CryptEngine* m_cryptEngine;
	TransferManager* m_transferManager;
	UserSettings* m_userSettings;

	ControlCenter* m_cc;
};

}

#endif
