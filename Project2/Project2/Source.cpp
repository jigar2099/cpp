#include<iostream>
#include<list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	//string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
protected:
	string OwnerName;
public:
	//constructor
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
	// method to get information
	void GetInfo() {
		cout << "Name:" << Name << endl;
		cout << "OwnerName:" << OwnerName << endl;
		cout << "SubscriberCounts:" << SubscribersCount << endl;
		cout << "videos:";
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
		cout << "\n ---------------------------------------" << endl;
	}
	void Subscribe() {
		SubscribersCount++;
	}
	void unSubscribe() {
		// if condition to avoid negative number of subscribers
		if (SubscribersCount > 0) {
			SubscribersCount--;
		}
		else;

	}
	void PublishVideo(string name) {
		PublishedVideoTitles.push_back(name);
	}
};

//inheritance from base class(YouTubeChannel) to child class(newsLetter)
class newsLetter:public YouTubeChannel {
public:
	newsLetter(string name, string ownerName): YouTubeChannel(name,ownerName) {

	}
	void Experiment() {
		cout << OwnerName << ":BASE(Baryon Anti-baryon Symmetry Experiment )" << endl;
	}
};


int main() {

	newsLetter ytChannel("CERN news","CERN");
	ytChannel.PublishVideo("ATLAS");
	ytChannel.PublishVideo("CMS");
	ytChannel.PublishVideo("ALICE");
	ytChannel.PublishVideo("LHCb");
	ytChannel.PublishVideo("TOTEM");
	ytChannel.PublishVideo("LHCf");
	ytChannel.PublishVideo("MoEDAL");
	ytChannel.Subscribe();
	ytChannel.Subscribe();
	ytChannel.GetInfo();
	ytChannel.Experiment();

	newsLetter nsLetter("CERN news", "CERN");
	nsLetter.PublishVideo("ATLAS");
	nsLetter.PublishVideo("CMS");
	nsLetter.PublishVideo("ALICE");
	nsLetter.PublishVideo("LHCb");
	nsLetter.PublishVideo("TOTEM");
	nsLetter.PublishVideo("LHCf");
	nsLetter.PublishVideo("MoEDAL");
	for (int i = 0; i < 1000; i++) {
		nsLetter.Subscribe();
		nsLetter.Subscribe();
	}
	nsLetter.GetInfo();
	nsLetter.Experiment();

	system("pause>0");
}