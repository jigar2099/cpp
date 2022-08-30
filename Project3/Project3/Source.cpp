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
	int ContentQuality; // track quality content reading
public:
	//constructor
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
		ContentQuality = 0;
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
	void CheckAnalytics() {
		if (ContentQuality < 5) {
			cout << Name << ":smaller database" << endl;
		}
		else
			cout << Name << ":larger database." << endl;
	}
};

//inheritance from base class(YouTubeChannel) to child class(newsLetter)
class newsLetter :public YouTubeChannel {
public:
	newsLetter(string name, string ownerName) : YouTubeChannel(name, ownerName) {

	}
	void Experiment() {
		cout << OwnerName << ":BASE(Baryon Anti-baryon Symmetry Experiment )" << endl;
		ContentQuality++;
	}
};


// Polymorphisam
class HEPexperiments :public YouTubeChannel {
public:
	HEPexperiments(string name, string ownerName) : YouTubeChannel(name, ownerName) {

	}
	void Experiment() {
		cout << OwnerName << ":high energy and very high energy events" << endl;
		ContentQuality++;
	}
};


int main() {

	HEPexperiments hepexp("HEP and HE-Astrophysics", "Fundamental Physics");
	newsLetter nsLetter("CERN news", "CERN");

	hepexp.Experiment();
	hepexp.Experiment();
	hepexp.Experiment();
	hepexp.Experiment();
	hepexp.Experiment();
	nsLetter.Experiment();
	nsLetter.Experiment();

	YouTubeChannel* yt1 = &nsLetter;
	YouTubeChannel* yt2 = &hepexp;

	yt1->CheckAnalytics();
	yt2->CheckAnalytics();

	system("pause>0");
}