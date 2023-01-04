#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Movie
{
  string name;
  int year;
  int duration;
  string director;
  vector<int> reviews;

public:
  Movie()
  {
    name = "N/A";
    year = 0;
    duration = 0;
    director = "N/A";
  }

  Movie(string _name, int _year, int _duration, string _director)
  {
    name = _name;
    year = _year;
    duration = _duration;
    director = _director;
  }

  void setName(string _name)
  {
    name = _name;
  }

  void setYear(int _year)
  {
    year = _year;
  }

  void setDuration(int _duration)
  {
    duration = _duration;
  }

  void setDirector(string _director)
  {
    director = _director;
  }

  void addReview(int score)
  {
    if (score >= 0 && score <= 5)
      reviews.push_back(score);
    else
      cout << "invalid review score";
  }

  float getReviewAverage()
  {
    float sum = 0.0;
    for (int i = 0; i < reviews.size(); i++)
    {
      sum += reviews[i];
    }

    if (reviews.size() > 0)
      return sum / reviews.size();
    else
      return 0;
  }

  void display()
  {
    cout << "------------------------------" << endl;
    cout << "Movie info: " << endl;
    cout << "Name: " << name << endl;
    cout << "Release Year: " << year << "(age: "<< getAge() << ")" << endl;
    cout << "Duration: " << duration << endl;
    cout << "Director: " << director << endl;
    cout << "Reviews: " ;
    for(int i=0; i < reviews.size(); i++)
    {
      cout << reviews[i] << " ";
    }
    cout << endl << "Reviews average: " << getReviewAverage()  << endl;
    cout << "------------------------------" << endl;
  }

  int getAge()
  {
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    int current_year = local_time.tm_year + 1900;
    return current_year - year;
  }

};

int main()
{
  Movie m1;
  Movie m2("Hunger Games", 2012, 142, "Gary Ross");
  m2.addReview(5);
  m2.addReview(4);
  m2.addReview(6);

  Movie m3(m2);
  m1.display();
  m2.display();
  m3.display();

}
