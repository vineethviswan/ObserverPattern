
#include <vector>
#include <string>

class Channel;

class Reporter {
public:
	Reporter() = default;
	void newsReceived(std::string &);
	std::string& getNews();
	void notifyChannels();
	void addListener(Channel *);
	void removeListener(Channel *);
private:
	std::vector<Channel*> mChannels;
	std::string mNews;
};

class Channel {
public:
	virtual ~Channel() = default;
	virtual void update() = 0;
protected:
	Reporter *mReporter;
};

class CNN : public Channel {
public:
	CNN(Reporter *rpt);
	void update();
};

class News18 : public Channel {
public:
	News18(Reporter *rpt);
	void update();
};

class Asianet : public Channel {
public:
	Asianet(Reporter *rpt);
	void update();
};