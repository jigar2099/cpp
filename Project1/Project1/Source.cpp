#include<iostream>
#include<list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
public:	
	//constructor
	YouTubeChannel(string name,string ownerName) {
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


int main() {

	YouTubeChannel ytChannel("Alpha","alaskov");
	ytChannel.PublishVideo("Scream");
	ytChannel.PublishVideo("dream");
	ytChannel.PublishVideo("grim");
	//ytChannel.Subscribe();
	//ytChannel.Subscribe();
	//ytChannel.Subscribe();
	ytChannel.unSubscribe();
	ytChannel.GetInfo();

	system("pause>0");
}