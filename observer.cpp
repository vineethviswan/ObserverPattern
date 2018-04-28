

#include <iostream>
#include <algorithm>
#include "observer.h"

CNN::CNN(Reporter *rpt) {
	
	this->mReporter = rpt;
	this->mReporter->addListener(this);
}

News18::News18(Reporter *rpt){
	this->mReporter = rpt;
	this->mReporter->addListener(this);
}

Asianet::Asianet(Reporter *rpt) {
	this->mReporter = rpt;
	this->mReporter->addListener(this);
}

void Reporter::newsReceived(std::string &pNews) {
	mNews = pNews;
	notifyChannels();
}

std::string& Reporter::getNews() {
	return mNews;
}

void Reporter::notifyChannels() {
	for (auto itrChannel : mChannels)
		itrChannel->update();
}

void Reporter::addListener(Channel *pCh) {
	mChannels.push_back(pCh);
}

void Reporter::removeListener(Channel *pCh) {
	//mChannels.erase(mChannels.begin(), mChannels.end(), *pCh);
}

void CNN::update() {
	std::cout << "CNN - " << mReporter->getNews() << "\n";
}

void News18::update() {
	std::cout << "News18 " << mReporter->getNews() << "\n";
}

void Asianet::update() {
	std::cout << "Asianet " << mReporter->getNews() << "\n";
}