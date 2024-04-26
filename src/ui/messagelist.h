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

#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <messageinformation.h>

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace P2PChat
{
class IClientManager;

/**
 * @brief provides all Messages send or recieved for GUI
 */
class MessageList : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Sent = Qt::UserRole + 1,
		User,
		Message
	};

	explicit MessageList(IClientManager* cm, QObject* parent = nullptr);
	~MessageList();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:
	/**
	 * @brief adds new message provided to the message list
	 * @param mi Message to add to list
	 */
	void updateList(MessageInformation mi);

Q_SIGNALS:
	/**
	 * @brief emitted when new message is added
	 */
	void messagesAdded(int);

protected:
	QHash<int, QByteArray> roleNames() const;
	IClientManager *m_cm;

private:
	QList<MessageInformation> m_messages;

};

}

#endif

