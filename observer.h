
#include <string>
#include <boost\signals2.hpp>
#include <boost\bind.hpp>


class Reporter {
public:
	using NewsUpdater = boost::signals2::signal<void(std::string)>;
	using ListenerType = NewsUpdater::slot_type;
	Reporter(const std::string& name):m_reporterName(name){}
	void newsReceived(const std::string &);
	boost::signals2::connection addListener(const ListenerType& listener);

private:
	std::string m_reporterName;
	NewsUpdater m_newsUpdate;
};

class Channel {
public:
	Channel(std::string name, Reporter& reporter);
	void update(const std::string &news);
	~Channel();
protected:
	std::string m_channelName;
	boost::signals2::connection m_connection;
};

