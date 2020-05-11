
#include "..\..\observer.h"
#include <string>

int main() {

	Reporter rptr1("Venu");

	Channel asianet(std::string("Asianet"), rptr1);
	Channel news18(std::string("News18"), rptr1);
	Channel cnn(std::string("Cnn"), rptr1);

	rptr1.newsReceived("News Update at 1700");
}
