

#include <iostream>
#include <algorithm>
#include "observer.h"

boost::signals2::connection Reporter::addListener(const ListenerType& listener) {
	return m_newsUpdate.connect(listener);
}

void Reporter::newsReceived(const std::string& news) {
	m_newsUpdate(news);
}

Channel::Channel(std::string name, Reporter &reporter) :m_channelName(name) {
	m_connection = reporter.addListener(boost::bind(&Channel::update, this, boost::placeholders::_1));
}

void Channel::update(const std::string &news) {
	std::cout << m_channelName << " : " << news << "\n";
}

Channel::~Channel() {
	m_connection.disconnect();
}