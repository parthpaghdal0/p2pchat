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

#include "pendingtransfers.h"

#include <interfaces/itransfermanager.h>
#include <transfer.h>
#include <file.h>

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QDebug>

namespace P2PChat
{

PendingTransfers::PendingTransfers(ITransferManager* tm, QObject* parent) : QAbstractListModel(parent) , m_tm(tm)
{
	connect(tm,&ITransferManager::pendingTransfersUpdated,this,&PendingTransfers::updateList);
	m_transfers = tm->pendingTransfers();
	beginInsertRows(QModelIndex(), 0, m_transfers.count()-1);
	endInsertRows();
}

PendingTransfers::~PendingTransfers()
{
}

int PendingTransfers::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return m_transfers.count();
}

QVariant PendingTransfers::data(const QModelIndex& index, int role) const
{
	if (index.row() < 0 || index.row() >= m_transfers.count())
		return QVariant();

	const File &file = m_transfers[index.row()];
	if (role == Id)
		return file.id();
	else if (role == FileName)
		return file.name();
	else if (role == FilePath)
		return file.path();
	else if (role == FileSize)
		return bytesToString(file.size());
	else if (role == Url)
		return file.url();
	else if (role == ClientName)
		return file.userName();
	return QVariant();
}

void PendingTransfers::updateList()
{
	int prevCount = rowCount();
	if(rowCount() > 0) {
		beginRemoveRows(QModelIndex(),0,rowCount()-1);
		endRemoveRows();
	}

	m_transfers = m_tm->pendingTransfers();

	if(m_transfers.count() <= 0)
		return;

	int newCount = rowCount();
	beginInsertRows(QModelIndex(), 0 , m_transfers.count()-1);
	endInsertRows();
	emit transfersAdded(newCount-prevCount);
}

QHash<int, QByteArray> PendingTransfers::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Id] = "id";
	roles[FileName] = "filename";
	roles[FilePath] = "filepath";
	roles[FileSize] = "filesize";
	roles[Url] = "url";
	roles[ClientName] = "clientname";
	return roles;
}

QString PendingTransfers::bytesToString(quint64 bytes) const
{
	if(bytes > 1024*1024*1024)
		return QString::number((double)bytes/(1024*1024*1024)) + QString(" GB");
	else if(bytes > 1024*1024)
		return QString::number(bytes/(1024*1024)) + QString(" MB");
	else if(bytes > 1024)
		return QString::number(bytes/1024) + QString(" KB");
	else
		return QString::number(bytes) + QString(" B");
}

}


