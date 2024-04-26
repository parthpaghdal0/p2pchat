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

#include "file.h"

namespace P2PChat
{

File::File() : m_name(QString()) , m_path(QString()) , m_size(0) , m_action(UNKNOWN) , m_url(QString()) ,
				 m_userName(QString()) , m_prog(0) , m_rate(0) , m_transfered(0) , m_timeRemaining(0)
{
}

File::~File()
{
}

qint16 File::id() const
{
	return m_id;
}

QString File::name() const
{
	return m_name;
}

QString File::path() const
{
	return m_path;
}

quint64 File::size() const
{
	return m_size;
}

File::Action File::action() const
{
	return m_action;
}

QString File::url() const
{
	return m_url;
}

QString File::userName() const
{
	return m_userName;
}

int File::progress() const
{
	return m_prog;
}

int File::rate() const
{
	return m_rate;
}

int File::transfered() const
{
	return m_transfered;
}

quint64 File::timeRemaining() const
{
	return m_timeRemaining;
}

void File::setId(qint16 id)
{
	m_id = id;
}

void File::setName(QString name)
{
	m_name = name;
}

void File::setPath(QString path)
{
	m_path = path;
}

void File::setSize(quint64 size)
{
	m_size = size;
}

void File::setAction(Action action)
{
	m_action = action;
}

void File::setUrl(QString url)
{
	m_url = url;
}

void File::setUserName(QString name)
{
	m_userName  = name;
}

void File::setProgress(int prog)
{
	m_prog = prog;
}

void File::setRate(int rate)
{
	m_rate = rate;
}

void File::setTransfered(quint64 trans)
{
	m_transfered = trans;
}

void File::setTimeRemaining(quint64 trem)
{
	m_timeRemaining = trem;
}

}
