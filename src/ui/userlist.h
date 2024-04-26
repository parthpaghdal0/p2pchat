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

#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace P2PChat
{
class IClientManager;
class ClientInformation;

/**
 * @brief List of all available clients
 * @author Shashwat Dixit <parthpaghdal0@gmail.com>
 */
class UserList : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Name = Qt::UserRole + 1,
		Id,
		Ip
	};

	explicit UserList(IClientManager* cm, QObject* parent = nullptr);
	~UserList();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:
	/**
	 * @brief updates the list of clients
	 */
	void updateList();

protected:
	QHash<int, QByteArray> roleNames() const;
	IClientManager *m_cm;

private:
	QList<ClientInformation> m_users;

};

}

#endif
