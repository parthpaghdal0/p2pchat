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

#ifndef FILE_H
#define FILE_H

#include <QObject>

namespace P2PChat
{

/**
 * @brief Container for all informations related to a transfer
 * i.e. filename , path to store to , file size , url to send to, etc.
 * @author Shashwat Dixit <parthpaghdal0@gmail.com>
 */
class File
{

public:
	explicit File();
	~File();

	typedef enum Action {
		UNKNOWN = 0,
		SEND,
		RECIEVE
	} Action;

	qint16 id() const;
	QString name() const;
	QString path() const;
	quint64 size() const;
	Action action() const;
	QString url() const;
	QString userName() const;
	int progress() const;
	int rate() const;
	int transfered() const;
	quint64 timeRemaining() const;

	void setId(qint16);
	void setName(QString);
	void setPath(QString);
	void setSize(quint64);
	void setAction(Action);
	void setUrl(QString);
	void setUserName(QString);
	void setProgress(int);
	void setRate(int);
	void setTransfered(quint64);
	void setTimeRemaining(quint64);

protected:
	qint16 m_id;
	QString m_name;
	QString m_path;
	quint64 m_size;
	Action m_action;
	QString m_url;
	QString m_userName;
	int m_prog;
	int m_rate;
	quint64 m_transfered;
	quint64 m_timeRemaining;

};

}

Q_DECLARE_METATYPE(P2PChat::File);

#endif

